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
	LinkNode<T> *locate(int i);            //���ص�i��Ԫ�صĵ�ַ(ͷ���Ϊ0����һ�����Ϊ1)
	void insert(int i,T x);                //�ڵ�i��Ԫ�غ������ֵΪx����Ԫ��
	void setData(int i,T x);               //����i��Ԫ�ظ�ֵ
	T getData(int i);                      //���ص�i��Ԫ�ص�ֵ
	int getSize();                         //��������size
	void reversePrintData();                      //����������н�����ֵ
   
protected:
    LinkNode<T> *first;
private:
}; 

