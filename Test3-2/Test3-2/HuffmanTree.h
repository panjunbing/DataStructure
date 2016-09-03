#pragma once

template <class T>
struct HuffmanTreeNode{
	T data;                                                                         //����
	unsigned int count;                                                             //Ȩֵ
	unsigned int code[50];                                                            //���Ĺ���������
	HuffmanTreeNode<T> *leftChild;                                                  //����Ů
	HuffmanTreeNode<T> *rightChild;                                                 //����Ů
	HuffmanTreeNode<T> *parent;                                                     //���ڵ�
	HuffmanTreeNode():leftChild(NULL),rightChild(NULL),parent(NULL){}               //���캯��
	bool operator <=(HuffmanTreeNode &R){return count <= R.count;}                  //����<=��>�����
	bool operator >(HuffmanTreeNode &R){return count > R.count;}
};

template <class T>
class HuffmanTree
{
public:
	HuffmanTree(char str[]);
	HuffmanTree(HuffmanTree<T> &t);
	~HuffmanTree(void);
	void printCode();																		//�������������
	void printData();																		//������н��data��Ȩֵ
	int getWPL();                                                                           //��ȡWPL
	void inFile(char ch[]);                                                                 //���ļ�
protected:
	HuffmanTreeNode<T> *root;
private:
	int WPL;
	void creat(char str[]);
	void census(unsigned int count[],char data[],char str[],unsigned int &size);                        //������������ʱͳ�Ƹ��ַ����ֵĴ���
	void deleteTree(HuffmanTreeNode<T> *subTree);                                     //ɾ��subTree���������ӽ��
	void encode(HuffmanTreeNode<T> *subTree,unsigned int code[],int m = 2);				//����
	void calculateWPL(HuffmanTreeNode<T> *subTree,int i = 0);                          //����WPL
	void printCode(HuffmanTreeNode<T> *subTree);                                       //�������������
	void printData(HuffmanTreeNode<T> *subTree);                                       //������н��data��Ȩֵ
};

