// Test3-2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "HuffmanTree.cpp"
#include <iostream>
#include <fstream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"-----------------------------建立哈弗曼树---------------------------------------"<<endl;
	char str [100];                                     //输入的字符
	cout<<"选择输入一串字符来建立哈弗曼树还是读取text文档内容来建立哈弗曼树（输入0或1）"<<endl;
	bool type;
	cin>>type;
	if(type == false){                                //当选择输入一串字符来建立哈弗曼树时
		cout<<"请输入一串字符                           例如：abdcdddcaaabababab(a7b5c2d4)"<<endl;
		cin>>str;
	}
	if(type == true){                                 //当选择读取text文档内容来建立哈弗曼树时
		ifstream in;
		in.open("text.txt",ios::in|ios::binary);
		while (!in.eof()){
			in.read(str,100);
			cout<<"成功读取text.txt！"<<endl;
		}
		str[in.gcount()]=0;                           //结尾加上/0
		in.close();
	}
    HuffmanTree<char> tree(str);


	cout<<"-----------------------------字符权值及WPL--------------------------------------"<<endl;
	cout<<"字符权值为："<<endl;
	tree.printData();

	cout<<endl<<"WPL="<<tree.getWPL()<<endl;

	cout<<"------------------------------哈弗曼编码----------------------------------------"<<endl;
	cout<<"哈弗曼编码为："<<endl;
	tree.printCode();
	cout<<"---------------------------------结束-------------------------------------------"<<endl;

	return 0;
}

