// Test3.cpp : �������̨Ӧ�ó������ڵ㡣
//�������������������У�����һ�ö�����
//ʵ��SwapTree�������Ը����Ϊ����������ÿ������������������������ʾ��ǰ��ݹ飩
//ʵ��Find����������ֵΪkey�Ľ�㣬������ý����������Ƚ��
//

#include "stdafx.h"
#include "BinTree.cpp"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	BinTreeNode<char> *mTreeNode = NULL;
	BinTree<char> mTree;
 	cout<<"------------------------------����������----------------------------------------"<<endl;
	cout<<"��ѡ�����������ķ�ʽ��"<<endl;
	cout<<"1.����ǰ�����н�����������#��ʾ�ս�㣩"<<endl;
	cout<<"2.����ǰ�����к�������������������������������#��"<<endl;
	int choice;
	cin>>choice;
	if(choice == 1){
		char str[20];
		cout<<"������һ����������ǰ���������(��#��ʾ�ս�㣩"<<endl;   
		cout<<"���罨�����¶�������"<<endl;
		cout<<"     ____A____        "<<endl;
		cout<<"  __B__     __C__     "<<endl;
		cout<<" #    _D_  #    _F_   "<<endl;
		cout<<"     #   #     #   #  "<<endl;
		cout<<"��Ҫ����AB#D##C#F##"<<endl<<endl;
		cin>>str;

		mTree.creatTree(str,mTreeNode,NULL);
	}
	if(choice == 2){
		char str1[20];
		char str2[20];
		cout<<"                 _____A "<<endl;
		cout<<"               _B_      "<<endl;
		cout<<"              C  __D_    "<<endl;
		cout<<"                E_   F   "<<endl;
		cout<<"                  G     "<<endl<<endl;;

		cout<<"�������������ǰ������   ���磺ABCDEGF"<<endl;
		cin>>str1;
		cout<<"���������������������   ���磺CBEGDFA"<<endl;
		cin>>str2;
		mTree.creatTree(str1,str2);
	}



	cout<<"------------------------------����������----------------------------------------"<<endl;
	cout<<"ѡ����Ҫ���еĲ�����0.����������Ů 1.Ѱ��X��㲢�����������Ƚ��  9.�˳�"<<endl;
	
	cin>>choice;
	while(1){
		if(choice == 9){
			break;
		}
		if(choice == 0){
			mTree.swapTree(mTree.root);
			cout<<"��������һ������"<<endl;
			cin>>choice;
			continue;
		}
		if(choice == 1){
			char s;
			cout<<"������Ҫ���ҵĽ��"<<endl;
			cin>>s;
			mTree.findKey(mTree.root,s);
			cout<<"��������һ������"<<endl;
			cin>>choice;
			continue;
		}
	}

    cout<<"-----------------------------������������-------------------------------------"<<endl;
	mTree.print(mTree.root);

	cout<<"---------------------------------����-------------------------------------------"<<endl;
	return 0;
}

