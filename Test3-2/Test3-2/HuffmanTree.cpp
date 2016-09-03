#include "StdAfx.h"
#include "HuffmanTree.h"
#include "MinHeap.cpp"
#include <fstream>

template <class T>
HuffmanTree<T>::HuffmanTree(char str[]){
	WPL = 0;
	root = new HuffmanTreeNode<T>;
	creat(str);
};

template <class T>
HuffmanTree<T>::~HuffmanTree(){
	deleteTree(root);                                           //ɾ����������
}

template <class T>
void HuffmanTree<T>::creat(char str[]){
	unsigned int count[50];                                    //���ַ���Ȩֵ�����ִ���)
	char data[50];                                    //����
    unsigned int size;                                         //�ַ��ĸ���
	for(unsigned int i = 0; i < 50; i++)                       //count�ĳ�ʼ��
		count[i] = 0;         
	census(count,data,str,size);
	minHeap<HuffmanTreeNode<T>> hp;
	HuffmanTreeNode<T> *parent, *first, *second;
	HuffmanTreeNode<T>  *work;
	for(unsigned int i = 0; i < size; i++){                                      //��ÿ��Ԫ�ض�������С����
		work = new HuffmanTreeNode<T>;
		work->data = data[i];
		work->count = count[i];
		work->leftChild = NULL;
		work->rightChild = NULL;
		work->parent = NULL;
		hp.insert(*work);
	}
	for(unsigned int i = 0; i < size-1; i++){
		parent = new HuffmanTreeNode<T>;
		first = new HuffmanTreeNode<T>;
		second = new HuffmanTreeNode<T>;
		hp.removeMin(*first);                                         //ÿ�δ���С����ȡ��������С����
		hp.removeMin(*second);
		parent->leftChild = first;                                    //parent��Ϊ���ǵĸ��ڵ�
		parent->rightChild = second;
		parent->count = first->count + second->count;
		parent->data = '#';                                           //parent���Ǹ�������԰�����data��Ϊ'#'
		first->parent = parent;
		second->parent = parent;
		hp.insert(*parent);                                           //�ٰ�parent������С���У�����ѭ���ж�
	}
	root = parent;                                                    //���һ��parent���Ǹ����
	unsigned int code[50];											  //�Խ����й��������루�յĵط�ȡ-1��
	code[0] = 2;
	encode(root,code);                                                
	calculateWPL(root);                                               //��������ǵ�WPL
};

template <class T>
void HuffmanTree<T>::deleteTree(HuffmanTreeNode<T> *subTree){
	if(subTree != NULL){
		deleteTree(subTree->leftChild);                          //���������ɾ�����
		deleteTree(subTree->rightChild);
		delete subTree;
	}
}

template <class T>
void HuffmanTree<T>::census(unsigned int count[],char data[],char str[],unsigned int &size){
	//����ͳ���ַ����ֵĴ���
	for(int i = 0; str[i] != 0;i++){
		if(str[i] == '#')                        //�����ֵ����ѳ��ֹ����ַ�ʱ��ִ���´�ѭ��
			continue;
		static int n = 0;
		count[n]++;                               //��һ�γ���ʱ��һ
		data[n] = str[i];
		for(int j = 0; str[j] != 0;j++){
			if(str[i] == str[j] && i != j){
				count[n]++;                    //ÿ�γ����ظ���ʱ���һ����
				str[j] = '#';                     //�����ѳ��ֹ�
			}
		}
		data[++n] = 0;
		size = n;
	}
}

template <class T>
void HuffmanTree<T>::encode(HuffmanTreeNode<T> *subTree,unsigned int code[] ,int m = 2){

	if(subTree != NULL){
		int num = 0;
		for(;code[num] != 2;num++)
			subTree->code[num] = code[num];                          //���ǰ���ı�����������ڵ�ı���
		subTree->code[num] = m;                                      //ǰ���ı�����������ڵ�ı����ټ���1��0������Ů������Ů��
		subTree->code[num+1] = 2;
		encode(subTree->leftChild,subTree->code,0);                  //ǰ��������н��
		encode(subTree->rightChild,subTree->code,1);
	}
}

template <class T>
void HuffmanTree<T>::calculateWPL(HuffmanTreeNode<T> *subTree,int i = 0){
	if(subTree != NULL){
		if(subTree->data != '#')
			WPL += i*subTree->count;                     //iΪ��ǰ����,countΪ���Ȩֵ
		calculateWPL(subTree->leftChild,++i);            //ǰ�����
		i--;
		calculateWPL(subTree->rightChild,++i);
		i--;
	}
}

template <class T>
int HuffmanTree<T>::getWPL(){
	return WPL;
}

template <class T>
void HuffmanTree<T>::inFile(char ch[]){
	    char str[500];
		ifstream in;
		in.open(ch,ios::in|ios::binary);
		while (!in.eof()){
			in.read(str,100);
		}
		str[in.gcount()]=0;                           //��β����/0
		in.close();
		creat(str);
}

template <class T>
void HuffmanTree<T>::printCode(){
	printCode(root);
}

template <class T>
void HuffmanTree<T>::printCode(HuffmanTreeNode<T> *subTree){
	if(subTree != NULL){
		if(subTree->data != '#'){
			cout<<subTree->data<<":";
		for(int i = 0;subTree->code[i] != 2;i++)
			cout<<subTree->code[i];                              
		cout<<endl;
		}
		printCode(subTree->leftChild);             //ǰ��������н��
		printCode(subTree->rightChild);
	}
}

template <class T>
void HuffmanTree<T>::printData(){
	printData(root);
}

template <class T>
void HuffmanTree<T>::printData(HuffmanTreeNode<T> *subTree){
	if(subTree != NULL){
		if(subTree->data != '#')
			cout<<"����:"<<subTree->data<<" ���ִ���:"<<subTree->count<<endl;                                   
		printData(subTree->leftChild);             //ǰ��������н��
		printData(subTree->rightChild);
		}
}