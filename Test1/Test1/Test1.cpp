// Test1.cpp : �������̨Ӧ�ó������ڵ㡣
// ����n�Ľ׳ˣ�n>=20��

#include "stdafx.h"
#include "List.cpp"
#include <iostream>
using namespace std;


void mul(List<int> mList,int p){ 
	//���ڼ���֮ǰ�������p����2һֱ��n��
	int t = 0;
	int size = mList.getSize();
	for(int i = 1; i <= size; i++){
		mList.setData(i,mList.getData(i)*p+t);                //����ÿһλ��*p���Ͻ�λ����        
	    t = mList.getData(i)/1000;                            //��λ��                
		mList.setData(i,mList.getData(i)%1000);               //����               
	}
	while(t){                                                 //���λ��Ҫ��λʱ
		mList.insert(size,t%1000);                            //��������+1 �� ���λ���ڽ���λ��         
		size++;
		t /= 1000;                                            //��λ��/1000������λ��>=1000ʱ��Ҫ����λ
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"-------------------------------�����׳�-----------------------------------------"<<endl;
	while(1){
	cout<<"������һ����n,����Ϊ���������Ľ׳ˣ�����-1�˳���"<<endl;
	int n;
	cin >> n;
	if(n == -1)
		break;
	List<int> mList;
	mList.insert(0,1);
	for(int i=2; i<=n; i++)                                   //i��n��2
		mul(mList,i);                                         //i�Ľ׳�
	cout<<"���Ľ׳�Ϊ:";
	mList.reversePrintData();
	cout<<endl;
	}
	return 0;
}

