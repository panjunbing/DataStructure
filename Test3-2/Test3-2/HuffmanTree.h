#pragma once

template <class T>
struct HuffmanTreeNode{
	T data;                                                                         //数据
	unsigned int count;                                                             //权值
	unsigned int code[50];                                                            //结点的哈弗曼编码
	HuffmanTreeNode<T> *leftChild;                                                  //左子女
	HuffmanTreeNode<T> *rightChild;                                                 //右子女
	HuffmanTreeNode<T> *parent;                                                     //父节点
	HuffmanTreeNode():leftChild(NULL),rightChild(NULL),parent(NULL){}               //构造函数
	bool operator <=(HuffmanTreeNode &R){return count <= R.count;}                  //重载<=和>运算符
	bool operator >(HuffmanTreeNode &R){return count > R.count;}
};

template <class T>
class HuffmanTree
{
public:
	HuffmanTree(char str[]);
	HuffmanTree(HuffmanTree<T> &t);
	~HuffmanTree(void);
	void printCode();																		//输出哈弗曼编码
	void printData();																		//输出所有结点data和权值
	int getWPL();                                                                           //获取WPL
	void inFile(char ch[]);                                                                 //打开文件
protected:
	HuffmanTreeNode<T> *root;
private:
	int WPL;
	void creat(char str[]);
	void census(unsigned int count[],char data[],char str[],unsigned int &size);                        //建立哈弗曼树时统计各字符出现的次数
	void deleteTree(HuffmanTreeNode<T> *subTree);                                     //删除subTree结点的所有子结点
	void encode(HuffmanTreeNode<T> *subTree,unsigned int code[],int m = 2);				//编码
	void calculateWPL(HuffmanTreeNode<T> *subTree,int i = 0);                          //计算WPL
	void printCode(HuffmanTreeNode<T> *subTree);                                       //输出哈弗曼编码
	void printData(HuffmanTreeNode<T> *subTree);                                       //输出所有结点data和权值
};

