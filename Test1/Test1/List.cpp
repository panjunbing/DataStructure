#include "StdAfx.h"
#include "List.h"
#include <stack>
#include <iostream>
using namespace std;

template<class T>
List<T>::List(){
	first = new LinkNode<T>;
	first->data =0;
	first->link = NULL;
}

template<class T>
List<T>::~List(){

}

template<class T>
LinkNode<T> *List<T>::locate(int i){
	int k = 0;
	LinkNode<T> *current = first;
	for(;current != NULL && k != i ;current = current->link){
		k++;
	}
	return current;
}

template<class T>
void List<T>::insert(int i,T x){
	LinkNode<T> *current = locate(i);

	if(current == NULL){
		cerr<<"���벻�ɹ���"<<endl;
		return;
	}

	LinkNode<T> *newNode = new LinkNode<T>;
	newNode->data = x;

	if(newNode == NULL){
		cerr<<"�½���ڴ����ʧ�ܣ�"<<endl;
		return;
	}
	newNode->link = current->link;
	current->link = newNode;
	first->data++;

}

template<class T>
void List<T>::setData(int i,T x){
	if(i < 0){
		cerr<<"����iֵ������"<<endl;
		return;
	}
	LinkNode<T> *current = locate(i);
	if(current != NULL){
		current->data = x;
	}
}

template<class T>
T  List<T>::getData(int i){
	if(i < 0){
		cerr<<"����iֵ����������ֵΪ-1"<<endl;
		return -1;
	}
	LinkNode<T> *current = locate(i);
	if(current != NULL){
		return current->data;
	}
	else{
		cerr<<"��i��Ԫ��Ϊ��,����ֵΪ-1"<<endl;
		return -1;
	}
}

template<class T>
int List<T>::getSize(){
	return first->data;
}

template<class T>
void List<T>::reversePrintData(){
	stack<T> mStack;

	for(LinkNode<T> *current = first->link;current != NULL;current = current->link)
		mStack.push(current->data);

	while(!mStack.empty()){
		T data = mStack.top();
		mStack.pop();
		if(data < 10)
			cout<<0<<0<<data;
		else if(data >= 10 && data < 100)
			cout<<0<<data;
		else
			cout<<data;
		cout<<'-';
	}
	cout<<endl;
}