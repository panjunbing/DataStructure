#pragma once

template <class T>
struct BinTreeNode{
	T data;
	int depth;                           //结点深度
	int x;                               //中序遍历时的位置
	BinTreeNode<T> *leftChild;
	BinTreeNode<T> *rightChild;
	BinTreeNode<T> *parent;
	
	BinTreeNode():leftChild(NULL),rightChild(NULL),parent(NULL){}
};

template <class T>
class BinTree
{
public:
	BinTree(void);
	~BinTree(void);

	void deleteTree(BinTreeNode<T> *&subTree);
	void creatTree(T str[],BinTreeNode<T> *&subTree, BinTreeNode<T> *parent,int depth = 1);       //创建二叉树(前序)
	void creatTree(T str1[],T str2[]);                                                            //创建二叉树（前序加中序）
	void swapTree(BinTreeNode<T> *subTree);                                                       //交换二叉树中所以的子女节点
	void findKey(BinTreeNode<T> *subTree,T key);                                                  //在二叉树中寻找结点为key的结点并返回它的所有祖先结点
	int getCount(BinTreeNode<T> *subTree);                                                        //返回二叉树的结点数
	int getHeight(BinTreeNode<T> *subTree);                                                       //返回二叉树高度
	void print(BinTreeNode<T> *subTree);                                                          //层次输出二叉树
	void inOrder(BinTreeNode<T> *subTree);                                                        //中序遍历二叉树
	BinTreeNode<T> *root;                                                                         //二叉树的根节点

private:
    BinTreeNode<T> *creatTree(T str1[],T str2[],int n,int depth = 1);                                                      //创建二叉树（前序加中序）
};