#include "StdAfx.h"
#include "BinTree.h"
#include <iostream>
#include <string>
using namespace std;

#include <queue>

const char RefValue = '#';

template <class T>
BinTree<T>::BinTree(void){
	root = NULL;
}

template <class T>
BinTree<T>::~BinTree(void){
	deleteTree(root);
}

template <class T>
void BinTree<T>::deleteTree(BinTreeNode<T> *&subTree){
	while(subTree != NULL){
		deleteTree(subTree->leftChild);
		deleteTree(subTree->rightChild);
		subTree = NULL;
	}
}

//����������(ǰ��)
template <class T>
void BinTree<T>::creatTree(T str[], BinTreeNode<T> *&subTree, BinTreeNode<T> *parent,int depth = 1){

	//ʹ��ǰ���������������
	static int i = -1;
	T item;
	if(str[++i] != 0)
		item = str[i];
	if(item != RefValue){                             //RefValue��ʾ�ս��
		subTree = new BinTreeNode<T>;
		subTree->data = item;
		subTree->depth = depth;
		subTree->parent = parent;

		creatTree(str,subTree->leftChild,subTree,++depth);    //ǰ�����
		depth--;											  //������һ��ʱ
		creatTree(str,subTree->rightChild,subTree,++depth);
		depth--;
	}
	else
		subTree = NULL;
	root = subTree;
}


//����������(ǰ�������)
template <class T>
void BinTree<T>::creatTree(T *str1,T *str2){
	int size = strlen(str1);
	root = creatTree(str1,str2,size);
}



template <class T>
BinTreeNode<T>* BinTree<T>::creatTree(T *str1,T *str2,int n,int depth = 1){
	if(n == 0) return NULL;
	int k = 0;
	while(str1[0] != str2[k])k++;                //Ѱ�Ҹ����
	BinTreeNode<T> *subTree = new BinTreeNode<T>;
	subTree->data = str1[0];
	subTree->depth = depth;
	subTree->leftChild = creatTree(str1+1,str2,k,++depth);                //���������0��k-1��Ԫ��
	depth--;
	subTree->rightChild = creatTree(str1+k+1,str2+k+1,n-k-1,++depth);     //���������k+1��n-1��Ԫ��
	depth--;
	return subTree;
}


//����������Ů
template <class T>
void BinTree<T>::swapTree(BinTreeNode<T> *subTree){
	if(subTree != NULL){
		BinTreeNode<T> *temp = subTree->leftChild;
		subTree->leftChild = subTree->rightChild;
		subTree->rightChild = temp;
		swapTree(subTree->leftChild);
		swapTree(subTree->rightChild);
	}
	root = subTree;
}

//Ѱ��key
template <class T>
void BinTree<T>::findKey(BinTreeNode<T> *subTree,T key){
	static T firstNodeData = subTree->data;
	if(subTree != NULL){
		if(subTree->data != key){
			findKey(subTree->leftChild,key);
			findKey(subTree->rightChild,key);
		}
		else{
			while(subTree->data != firstNodeData){
				subTree = subTree->parent;
				cout<<subTree->data<<'-';
			}
			cout<<endl;
		}
	}
}

//���ؽ����
template <class T>
int BinTree<T>::getCount(BinTreeNode<T> *subTree){
	static int count = 0;
	if(subTree != NULL){
		count++;
		getCount(subTree->leftChild);
		getCount(subTree->rightChild);
	}
	return count;
}

//������������
template <class T>
void BinTree<T>::print(BinTreeNode<T> *subTree){
	queue<BinTreeNode<T>* > mQueue;                     
	queue<int> xQueue;                                  //���ڴ浱ǰ����������Ů֮���xֵ

	inOrder(subTree);                                   //�������ȷ������xλ��

	mQueue.push(subTree);

	cout<<"             ";
	while(!mQueue.empty()){
		BinTreeNode<T> *temp = mQueue.front();            //tempΪ��ǰ��㣬subTreeΪ��һ�����
        mQueue.pop();        

		if(subTree->leftChild != NULL){
			xQueue.push(subTree->leftChild->x);
		}

		if(subTree->rightChild != NULL){
			xQueue.push(subTree->rightChild->x);
		}

		static int n = 0;                                 //��������ߵĽ���xֵ

		if(subTree->depth < temp->depth){                 //����ͷ����������һ�������ʱ
			n = 0;
			cout<<endl;                                   //����
			cout<<"             ";
		}
		if(temp->leftChild != NULL){
			for(int i = n+1;i <= temp->leftChild->x;i++)                //�Ѹý���������Ǹ����֮����' '����
				cout<<' ';
			for(int i = temp->leftChild->x+1;i < temp->x;i++)
				cout<<'_';
		}
		else
			for(int i = n+1;i < temp->x;i++)
				cout<<' ';
		cout<<temp->data;                                 //������

		if(temp->rightChild != NULL){
			for(int i = temp->x+1;i < temp->rightChild->x;i++)
				cout<<'_';
		}
		n= temp->x;

		subTree = temp;
		
		if(subTree->leftChild != NULL)
			mQueue.push(subTree->leftChild);              //����Ů�������

		if(subTree->rightChild != NULL)
			mQueue.push(subTree->rightChild);             //����Ů�������
	}
	cout<<endl;
}

//ȷ��������������λ��
template <class T>
void BinTree<T>::inOrder(BinTreeNode<T> *subTree){
	
	static int x = 1;
	if(subTree != NULL){
		inOrder(subTree->leftChild);
		subTree->x = x;
		x++;
		inOrder(subTree->rightChild);
	} 
}