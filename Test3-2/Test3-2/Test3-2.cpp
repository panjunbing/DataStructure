// Test3-2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "HuffmanTree.cpp"
#include <iostream>
#include <fstream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"-----------------------------������������---------------------------------------"<<endl;
	char str [100];                                     //������ַ�
	cout<<"ѡ������һ���ַ������������������Ƕ�ȡtext�ĵ�������������������������0��1��"<<endl;
	bool type;
	cin>>type;
	if(type == false){                                //��ѡ������һ���ַ���������������ʱ
		cout<<"������һ���ַ�                           ���磺abdcdddcaaabababab(a7b5c2d4)"<<endl;
		cin>>str;
	}
	if(type == true){                                 //��ѡ���ȡtext�ĵ�������������������ʱ
		ifstream in;
		in.open("text.txt",ios::in|ios::binary);
		while (!in.eof()){
			in.read(str,100);
			cout<<"�ɹ���ȡtext.txt��"<<endl;
		}
		str[in.gcount()]=0;                           //��β����/0
		in.close();
	}
    HuffmanTree<char> tree(str);


	cout<<"-----------------------------�ַ�Ȩֵ��WPL--------------------------------------"<<endl;
	cout<<"�ַ�ȨֵΪ��"<<endl;
	tree.printData();

	cout<<endl<<"WPL="<<tree.getWPL()<<endl;

	cout<<"------------------------------����������----------------------------------------"<<endl;
	cout<<"����������Ϊ��"<<endl;
	tree.printCode();
	cout<<"---------------------------------����-------------------------------------------"<<endl;

	return 0;
}

