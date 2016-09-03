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
	deleteTree(root);                                           //删除哈弗曼树
}

template <class T>
void HuffmanTree<T>::creat(char str[]){
	unsigned int count[50];                                    //各字符的权值（出现次数)
	char data[50];                                    //数据
    unsigned int size;                                         //字符的个数
	for(unsigned int i = 0; i < 50; i++)                       //count的初始化
		count[i] = 0;         
	census(count,data,str,size);
	minHeap<HuffmanTreeNode<T>> hp;
	HuffmanTreeNode<T> *parent, *first, *second;
	HuffmanTreeNode<T>  *work;
	for(unsigned int i = 0; i < size; i++){                                      //把每个元素都插入最小堆中
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
		hp.removeMin(*first);                                         //每次从最小堆中取出两个最小的数
		hp.removeMin(*second);
		parent->leftChild = first;                                    //parent作为他们的父节点
		parent->rightChild = second;
		parent->count = first->count + second->count;
		parent->data = '#';                                           //parent不是根结点所以把它的data设为'#'
		first->parent = parent;
		second->parent = parent;
		hp.insert(*parent);                                           //再把parent插入最小堆中，进行循环判断
	}
	root = parent;                                                    //最后一个parent就是根结点
	unsigned int code[50];											  //对结点进行哈弗曼编码（空的地方取-1）
	code[0] = 2;
	encode(root,code);                                                
	calculateWPL(root);                                               //计算出他们的WPL
};

template <class T>
void HuffmanTree<T>::deleteTree(HuffmanTreeNode<T> *subTree){
	if(subTree != NULL){
		deleteTree(subTree->leftChild);                          //后序遍历来删除结点
		deleteTree(subTree->rightChild);
		delete subTree;
	}
}

template <class T>
void HuffmanTree<T>::census(unsigned int count[],char data[],char str[],unsigned int &size){
	//用于统计字符出现的次数
	for(int i = 0; str[i] != 0;i++){
		if(str[i] == '#')                        //当出现的是已出现过的字符时就执行下次循环
			continue;
		static int n = 0;
		count[n]++;                               //第一次出现时加一
		data[n] = str[i];
		for(int j = 0; str[j] != 0;j++){
			if(str[i] == str[j] && i != j){
				count[n]++;                    //每次出现重复的时候加一并且
				str[j] = '#';                     //表明已出现过
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
			subTree->code[num] = code[num];                          //先令当前结点的编码等于它父节点的编码
		subTree->code[num] = m;                                      //前结点的编码等于它父节点的编码再加上1或0（左子女、右子女）
		subTree->code[num+1] = 2;
		encode(subTree->leftChild,subTree->code,0);                  //前序遍历所有结点
		encode(subTree->rightChild,subTree->code,1);
	}
}

template <class T>
void HuffmanTree<T>::calculateWPL(HuffmanTreeNode<T> *subTree,int i = 0){
	if(subTree != NULL){
		if(subTree->data != '#')
			WPL += i*subTree->count;                     //i为当前层数,count为结点权值
		calculateWPL(subTree->leftChild,++i);            //前序遍历
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
		str[in.gcount()]=0;                           //结尾加上/0
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
		printCode(subTree->leftChild);             //前序遍历所有结点
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
			cout<<"数据:"<<subTree->data<<" 出现次数:"<<subTree->count<<endl;                                   
		printData(subTree->leftChild);             //前序遍历所有结点
		printData(subTree->rightChild);
		}
}