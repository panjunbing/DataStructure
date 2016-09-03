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

//创建二叉树(前序)
template <class T>
void BinTree<T>::creatTree(T str[], BinTreeNode<T> *&subTree, BinTreeNode<T> *parent,int depth = 1){

	//使用前序遍历创建二叉树
	static int i = -1;
	T item;
	if(str[++i] != 0)
		item = str[i];
	if(item != RefValue){                             //RefValue表示空结点
		subTree = new BinTreeNode<T>;
		subTree->data = item;
		subTree->depth = depth;
		subTree->parent = parent;

		creatTree(str,subTree->leftChild,subTree,++depth);    //前序遍历
		depth--;											  //返回上一层时
		creatTree(str,subTree->rightChild,subTree,++depth);
		depth--;
	}
	else
		subTree = NULL;
	root = subTree;
}


//创建二叉树(前序加中序)
template <class T>
void BinTree<T>::creatTree(T *str1,T *str2){
	int size = strlen(str1);
	root = creatTree(str1,str2,size);
}



template <class T>
BinTreeNode<T>* BinTree<T>::creatTree(T *str1,T *str2,int n,int depth = 1){
	if(n == 0) return NULL;
	int k = 0;
	while(str1[0] != str2[k])k++;                //寻找根结点
	BinTreeNode<T> *subTree = new BinTreeNode<T>;
	subTree->data = str1[0];
	subTree->depth = depth;
	subTree->leftChild = creatTree(str1+1,str2,k,++depth);                //遍历中序从0到k-1个元素
	depth--;
	subTree->rightChild = creatTree(str1+k+1,str2+k+1,n-k-1,++depth);     //遍历中序从k+1到n-1个元素
	depth--;
	return subTree;
}


//交换左右子女
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

//寻找key
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

//返回结点数
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

//层次输出二叉树
template <class T>
void BinTree<T>::print(BinTreeNode<T> *subTree){
	queue<BinTreeNode<T>* > mQueue;                     
	queue<int> xQueue;                                  //用于存当前结点的左右子女之间的x值

	inOrder(subTree);                                   //中序遍历确定结点的x位置

	mQueue.push(subTree);

	cout<<"             ";
	while(!mQueue.empty()){
		BinTreeNode<T> *temp = mQueue.front();            //temp为当前结点，subTree为上一个结点
        mQueue.pop();        

		if(subTree->leftChild != NULL){
			xQueue.push(subTree->leftChild->x);
		}

		if(subTree->rightChild != NULL){
			xQueue.push(subTree->rightChild->x);
		}

		static int n = 0;                                 //输入结点左边的结点的x值

		if(subTree->depth < temp->depth){                 //当队头的数据是下一层的数据时
			n = 0;
			cout<<endl;                                   //换行
			cout<<"             ";
		}
		if(temp->leftChild != NULL){
			for(int i = n+1;i <= temp->leftChild->x;i++)                //把该结点和它左边那个结点之间用' '填满
				cout<<' ';
			for(int i = temp->leftChild->x+1;i < temp->x;i++)
				cout<<'_';
		}
		else
			for(int i = n+1;i < temp->x;i++)
				cout<<' ';
		cout<<temp->data;                                 //输出结点

		if(temp->rightChild != NULL){
			for(int i = temp->x+1;i < temp->rightChild->x;i++)
				cout<<'_';
		}
		n= temp->x;

		subTree = temp;
		
		if(subTree->leftChild != NULL)
			mQueue.push(subTree->leftChild);              //左子女加入队列

		if(subTree->rightChild != NULL)
			mQueue.push(subTree->rightChild);             //右子女加入队列
	}
	cout<<endl;
}

//确定结点中序遍历的位置
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