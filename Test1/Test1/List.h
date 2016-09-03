#pragma once


template<class T>
struct LinkNode{
	T data;
	LinkNode<T> *link;
	LinkNode(){link = NULL;}
};

template<class T>
class List
{
public:
	List();
	~List();
	LinkNode<T> *locate(int i);            //返回第i个元素的地址(头结点为0，第一个结点为1)
	void insert(int i,T x);                //在第i个元素后面插入值为x的新元素
	void setData(int i,T x);               //给第i个元素赋值
	T getData(int i);                      //返回第i个元素的值
	int getSize();                         //返回链表size
	void reversePrintData();                      //反向输出所有结点的数值
   
protected:
    LinkNode<T> *first;
private:
}; 

