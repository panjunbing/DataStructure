#pragma once

template <class T>
struct BinTreeNode{
	T data;
	int depth;                           //������
	int x;                               //�������ʱ��λ��
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
	void creatTree(T str[],BinTreeNode<T> *&subTree, BinTreeNode<T> *parent,int depth = 1);       //����������(ǰ��)
	void creatTree(T str1[],T str2[]);                                                            //������������ǰ�������
	void swapTree(BinTreeNode<T> *subTree);                                                       //���������������Ե���Ů�ڵ�
	void findKey(BinTreeNode<T> *subTree,T key);                                                  //�ڶ�������Ѱ�ҽ��Ϊkey�Ľ�㲢���������������Ƚ��
	int getCount(BinTreeNode<T> *subTree);                                                        //���ض������Ľ����
	int getHeight(BinTreeNode<T> *subTree);                                                       //���ض������߶�
	void print(BinTreeNode<T> *subTree);                                                          //������������
	void inOrder(BinTreeNode<T> *subTree);                                                        //�������������
	BinTreeNode<T> *root;                                                                         //�������ĸ��ڵ�

private:
    BinTreeNode<T> *creatTree(T str1[],T str2[],int n,int depth = 1);                                                      //������������ǰ�������
};