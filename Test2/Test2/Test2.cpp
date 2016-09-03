// Test2.cpp : �������̨Ӧ�ó������ڵ㡣
// a+b*(c-d)-e/f
// 3+5*(9-6)-8/2 = 14
// 14+9-21 = 2

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
using namespace std;

bool isOperand(char ch){
	//�ж�ch�Ƿ�Ϊ������
	switch (ch){
	case'=': case '(': case'*': case'/': case '+': case'-': case ')':
		return false;
		break;
	}
	return true;
}
bool isNegative(char ch1,int ch2){
	//�ж��Ƿ�Ϊ����
	if(ch1 == '(' && ch2 == '-')
		return true;
	return false;

}
int isp(char ch){
	switch (ch){
	case'=':
		return 0;
		break;
	case '(':
		return 1;
		break;
	case'*' : case'/':
		return 5;
		break;
	case '+': case'-': 
		return 3;
		break;
	case ')':
		return 6;
		break;
	}
	return 7;
}
int icp(char ch){
	switch (ch){
	case'=':
		return 0;
		break;
	case '(':
		return 6;
		break;
	case'*' : case'/':
		return 4;
		break;
	case '+': case'-': 
		return 2;
		break;
	case ')':
		return 1;
		break;
	}
	return 7;
}
void calculate(int &a,int &b,char result[],const char ch,bool &isDouble,bool &isNegative){
	//��a��b���м��㣬�������ch�����������result��isDouble��isNegative�����жϽ���Ƿ�Ϊ��λ�����Ƿ�Ϊ����
	switch(ch){
	case '*':
		if(abs(a*b) >= 10){
			if(a*b<0){
				result[2] = abs(a*b) % 10 + 48;
				result[1] = abs(a*b) / 10 + 48;
				result[0] = '-';
				isNegative = true;
			}
			else{
				result[1] = a*b % 10 + 48;
				result[0] = a*b / 10 + 48;
			}
			isDouble = true;
		}
		else{
			if(a*b<0){
				result[1] = abs(a*b) + 48;
				result[0] = '-';
				isNegative = true;
			}
			else
				result[0] = a*b + 48;
		}
		break;
	case '/':
				if(abs(a/b) >= 10){
			if(a/b<0){
				result[2] = abs(a/b) % 10 + 48;
				result[1] = abs(a/b) / 10 + 48;
				result[0] = '-';
				isNegative = true;
			}
			else{
				result[1] = a/b % 10 + 48;
				result[0] = a/b / 10 + 48;
			}
			isDouble = true;
		}
		else{
			if(a/b<0){
				result[1] = abs(a/b) + 48;
				result[0] = '-';
				isNegative = true;
			}
			else
				result[0] = a/b + 48;
		}
		break;
	case '+':
					if(abs(a+b) >= 10){
			if(a+b<0){
				result[2] = abs(a+b) % 10 + 48;
				result[1] = abs(a+b) / 10 + 48;
				result[0] = '-';
				isNegative = true;
			}
			else{
				result[1] = a+b % 10 + 48;
				result[0] = a+b / 10 + 48;
			}
			isDouble = true;
		}
		else{
			if(a+b<0){
				result[1] = abs(a+b) + 48;
				result[0] = '-';
				isNegative = true;
			}
			else
				result[0] = a+b + 48;
		}
		break;
	case '-':							 
						if(abs(a-b) >= 10){
			if(a-b<0){
				result[2] = abs(a-b) % 10 + 48;
				result[1] = abs(a-b) / 10 + 48;
				result[0] = '-';
				isNegative = true;
			}
			else{
				result[1] = a-b % 10 + 48;
				result[0] = a-b / 10 + 48;
			}
			isDouble = true;
		}
		else{
			if(a-b<0){
				result[1] = abs(a-b) + 48;
				result[0] = '-';
				isNegative = true;
			}
			else
				result[0] = a-b + 48;
		}
		break;
	}
}
void fun1(const char ch1[],char ch2[]){      
	//��׺���ʽתΪ��׺���ʽ
	stack<char> mStack;
	mStack.push('=');

	int i = 0;
	int n = -1;
	bool Operand = false;                                              //�������ִ���10�����Ƕ��������һ����
	while(ch1[i] != '=' || !mStack.empty()){
		if(isOperand(ch1[i])){                                         //��Ϊ������ʱ
			ch2[++n] = ch1[i];
			i++;
			Operand = true;
		}
		else if(isNegative(ch1[i],ch1[i+1])){
			ch2[++n] = ch1[i];                                         //'('
			ch2[++n] = ch1[++i];                                       //'-'
			while(isOperand(ch1[++i]))                                 //������
				ch2[++n] = ch1[i];                                     
			ch2[++n] = ch1[i];                                        //')'
			ch2[++n] = ' ';
			i++;
		}
		else{
			if(icp(ch1[i]) > isp(mStack.top())){
				if(ch1[i] != '(' && Operand)                           //����ǰ�ַ����ǣ�������һ���ַ����ǲ�����ʱ�����һ���ո�������������)                       
					ch2[++n] = ' ';
				mStack.push(ch1[i++]);
			}
			else if(icp(ch1[i]) < isp(mStack.top())){

				ch2[++n] = mStack.top();
				mStack.pop();
				Operand = false;
			}
			else if(icp(ch1[i]) == isp(mStack.top())){
				if(mStack.top() == '(')
					i++;
				mStack.pop();
			}
			else 
				cout<<"error";
			
		}
	}
	ch2[++n] = 0;      //�ַ�����0����β
}
void fun2(const char ch2[],char result[] ){
	//��׺���ʽ��ֵ
	stack<char> mStack;
	stack<char> tempStack;

	int i = 0;
	while(ch2[i] != 0){

		if(isOperand(ch2[i])){                         //��ch2������������(����)ʱ
				mStack.push(ch2[i]);
		}
		else if(isNegative(ch2[i],ch2[i+1])){           //��ch2����������ʱ
			int j = ++i;
			
			while(isOperand(ch2[++i]))                  //������
				 mStack.push(ch2[i]);
			mStack.push(ch2[j]);                      //'-'
		}
		else{                                           //��ch2������������ʱ
			int left = 0; 
			int right = 0;
			int n = 1;
			int m = 1;	
			bool isNegative = false;
			while(mStack.top() != ' '){                 //�����һ�������ǿո�������ʮ����ԭ�����Դ�����
				if(mStack.top() == '-'){
					mStack.pop();
					isNegative = true;
				}
				right += ( (int)mStack.top()-48 )*n;    //���������ֵ�������ASCII���ȥ48
				n *= 10;
				mStack.pop();
			}
			if(isNegative){
				right *= -1;
				isNegative = false;
			}

			if(mStack.top() == ' ')                     //��������֮��Ŀո�ȥ��
				mStack.pop();

			while(mStack.top() != ' '){                  //���ڶ�����
				if(mStack.top() == '-'){
					mStack.pop();
					isNegative = true;
				}
				left += ( (int)mStack.top()-48)*m;
				m *= 10;
				mStack.pop();
				if(mStack.empty())
					break;
			}
			if(isNegative){
				left *= -1;
				isNegative = false;
			}
			 
			bool isDouble = false;                                             //�Ƿ�Ϊ��λ������ʼֵΪfalse
			calculate(left,right,result,ch2[i],isDouble,isNegative);           //����

			if(mStack.empty()){                                                //�����ջ�ǿյģ���ô�ڼ���result��Ҫ�ټ���һ���ո������ͺ������ջ�����ֿ�
				if(isDouble && isNegative){                                    //��λ�ĸ���Ҫ����λ����
					mStack.push(result[1]);
					mStack.push(result[2]);
					mStack.push(result[0]);
				}
				else if( (isDouble && !isNegative) || (!isDouble && isNegative) ){    //��λ��������λ����Ҫ��λ����
				    mStack.push(result[1]);
					mStack.push(result[0]);
				} 
				else                                                              //��λ����Ҫһλ����
					mStack.push(result[0]);                   
				mStack.push(' ');
			}

			else{                                                              //���ջ���ǿյ����üӿո�
				if(isDouble && isNegative){ 
					mStack.push(result[1]);
					mStack.push(result[2]);
					mStack.push(result[0]);
				}
				else if( (isDouble && !isNegative) || (!isDouble && isNegative) ){
				    mStack.push(result[1]);
					mStack.push(result[0]);
				}
				else
					mStack.push(result[0]);

			}
		}
		i++;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"--------------------------------���ʽ��ֵ--------------------------------------"<<endl;
	cout<<"֧��+��-��*��/���㣬֧�ָ����������ŰѸ���������������λ��������,�ݲ�֧����λ����С��������"<<endl;
	char ch1[50];                                //��׺���ʽ���ַ���
	char ch2[50];                                //��׺���ʽ���ַ���

	while(1){
		cout<<"������һ����׺���ʽ(��=��β),����#��������   ���磺(-23)*2+(9-4)-8/2= "<<endl;
    cin>>ch1;
	if(ch1[0] == '#')
		break;
    fun1(ch1,ch2);                               //���׺���ʽ
	cout<<"���ĺ�׺���ʽΪ��"<<endl;
	cout<<ch2<<endl;
	char result[4] = {'0','0','0',0};            //���һλΪ/0;
	fun2(ch2 , result);                          //��ֵ
	cout<<"result = "<<result<<endl<<endl;             //���ֵ
	}

	return 0;
}

