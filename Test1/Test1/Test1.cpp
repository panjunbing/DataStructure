// Test1.cpp : 定义控制台应用程序的入口点。
// 计算n的阶乘（n>=20）

#include "stdafx.h"
#include "List.cpp"
#include <iostream>
using namespace std;


void mul(List<int> mList,int p){ 
	//用于计算之前结果乘以p（从2一直到n）
	int t = 0;
	int size = mList.getSize();
	for(int i = 1; i <= size; i++){
		mList.setData(i,mList.getData(i)*p+t);                //数组每一位都*p加上进位的数        
	    t = mList.getData(i)/1000;                            //进位数                
		mList.setData(i,mList.getData(i)%1000);               //余数               
	}
	while(t){                                                 //最大位需要进位时
		mList.insert(size,t%1000);                            //数组总数+1 ， 最大位等于进的位数         
		size++;
		t /= 1000;                                            //进位数/1000，当进位数>=1000时需要进多位
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"-------------------------------大数阶乘-----------------------------------------"<<endl;
	while(1){
	cout<<"请输入一个数n,程序将为你计算出它的阶乘（输入-1退出）"<<endl;
	int n;
	cin >> n;
	if(n == -1)
		break;
	List<int> mList;
	mList.insert(0,1);
	for(int i=2; i<=n; i++)                                   //i从n到2
		mul(mList,i);                                         //i的阶乘
	cout<<"它的阶乘为:";
	mList.reversePrintData();
	cout<<endl;
	}
	return 0;
}

