// Test3.cpp : 定义控制台应用程序的入口点。
//键盘输入二叉树结点序列，创建一棵二叉树
//实现SwapTree方法，以根结点为参数，交换每个结点的左子树和右子树（提示：前序递归）
//实现Find方法，查找值为key的结点，并输出该结点的所有祖先结点
//

#include "stdafx.h"
#include "BinTree.cpp"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	BinTreeNode<char> *mTreeNode = NULL;
	BinTree<char> mTree;
 	cout<<"------------------------------建立二叉树----------------------------------------"<<endl;
	cout<<"请选择建立二叉树的方式："<<endl;
	cout<<"1.输入前序序列建立二叉树（#表示空结点）"<<endl;
	cout<<"2.输入前序序列和中序序列来建立二叉树（不用输入#）"<<endl;
	int choice;
	cin>>choice;
	if(choice == 1){
		char str[20];
		cout<<"请输入一个二叉树的前序遍历序列(用#表示空结点）"<<endl;   
		cout<<"例如建立如下二叉树："<<endl;
		cout<<"     ____A____        "<<endl;
		cout<<"  __B__     __C__     "<<endl;
		cout<<" #    _D_  #    _F_   "<<endl;
		cout<<"     #   #     #   #  "<<endl;
		cout<<"需要输入AB#D##C#F##"<<endl<<endl;
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

		cout<<"请输入二叉树的前序序列   例如：ABCDEGF"<<endl;
		cin>>str1;
		cout<<"请输入二叉树的中序序列   例如：CBEGDFA"<<endl;
		cin>>str2;
		mTree.creatTree(str1,str2);
	}



	cout<<"------------------------------操作二叉树----------------------------------------"<<endl;
	cout<<"选择需要进行的操作：0.交换左右子女 1.寻找X结点并输入它的祖先结点  9.退出"<<endl;
	
	cin>>choice;
	while(1){
		if(choice == 9){
			break;
		}
		if(choice == 0){
			mTree.swapTree(mTree.root);
			cout<<"请输入下一个操作"<<endl;
			cin>>choice;
			continue;
		}
		if(choice == 1){
			char s;
			cout<<"请输入要查找的结点"<<endl;
			cin>>s;
			mTree.findKey(mTree.root,s);
			cout<<"请输入下一个操作"<<endl;
			cin>>choice;
			continue;
		}
	}

    cout<<"-----------------------------层次输出二叉树-------------------------------------"<<endl;
	mTree.print(mTree.root);

	cout<<"---------------------------------结束-------------------------------------------"<<endl;
	return 0;
}

