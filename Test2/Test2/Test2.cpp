// Test2.cpp : 定义控制台应用程序的入口点。
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
	//判断ch是否为操作数
	switch (ch){
	case'=': case '(': case'*': case'/': case '+': case'-': case ')':
		return false;
		break;
	}
	return true;
}
bool isNegative(char ch1,int ch2){
	//判断是否为负数
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
	//将a和b进行计算，计算符是ch，结果返回在result，isDouble，isNegative用来判断结果是否为两位数和是否为负数
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
	//中缀表达式转为后缀表达式
	stack<char> mStack;
	mStack.push('=');

	int i = 0;
	int n = -1;
	bool Operand = false;                                              //用来区分大于10的数是多个数还是一个数
	while(ch1[i] != '=' || !mStack.empty()){
		if(isOperand(ch1[i])){                                         //当为操作数时
			ch2[++n] = ch1[i];
			i++;
			Operand = true;
		}
		else if(isNegative(ch1[i],ch1[i+1])){
			ch2[++n] = ch1[i];                                         //'('
			ch2[++n] = ch1[++i];                                       //'-'
			while(isOperand(ch1[++i]))                                 //操作数
				ch2[++n] = ch1[i];                                     
			ch2[++n] = ch1[i];                                        //')'
			ch2[++n] = ' ';
			i++;
		}
		else{
			if(icp(ch1[i]) > isp(mStack.top())){
				if(ch1[i] != '(' && Operand)                           //当当前字符不是（并且上一个字符不是操作符时，输出一个空格，来区分两个数)                       
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
	ch2[++n] = 0;      //字符串用0来结尾
}
void fun2(const char ch2[],char result[] ){
	//后缀表达式求值
	stack<char> mStack;
	stack<char> tempStack;

	int i = 0;
	while(ch2[i] != 0){

		if(isOperand(ch2[i])){                         //当ch2遍历到操作数(正数)时
				mStack.push(ch2[i]);
		}
		else if(isNegative(ch2[i],ch2[i+1])){           //当ch2遍历到负数时
			int j = ++i;
			
			while(isOperand(ch2[++i]))                  //操作数
				 mStack.push(ch2[i]);
			mStack.push(ch2[j]);                      //'-'
		}
		else{                                           //当ch2遍历到操作符时
			int left = 0; 
			int right = 0;
			int n = 1;
			int m = 1;	
			bool isNegative = false;
			while(mStack.top() != ' '){                 //如果下一个数不是空格，则它乘十加上原数，以此类推
				if(mStack.top() == '-'){
					mStack.pop();
					isNegative = true;
				}
				right += ( (int)mStack.top()-48 )*n;    //阿拉伯数字等于它的ASCII码减去48
				n *= 10;
				mStack.pop();
			}
			if(isNegative){
				right *= -1;
				isNegative = false;
			}

			if(mStack.top() == ' ')                     //把两个数之间的空格去掉
				mStack.pop();

			while(mStack.top() != ' '){                  //读第二个数
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
			 
			bool isDouble = false;                                             //是否为两位数，初始值为false
			calculate(left,right,result,ch2[i],isDouble,isNegative);           //计算

			if(mStack.empty()){                                                //如果是栈是空的，那么在加上result后，要再加上一个空格，用来和后面加入栈的数分开
				if(isDouble && isNegative){                                    //两位的负数要有三位来存
					mStack.push(result[1]);
					mStack.push(result[2]);
					mStack.push(result[0]);
				}
				else if( (isDouble && !isNegative) || (!isDouble && isNegative) ){    //单位负数和两位正数要两位来存
				    mStack.push(result[1]);
					mStack.push(result[0]);
				} 
				else                                                              //单位正数要一位来存
					mStack.push(result[0]);                   
				mStack.push(' ');
			}

			else{                                                              //如果栈不是空的则不用加空格
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
	cout<<"--------------------------------表达式求值--------------------------------------"<<endl;
	cout<<"支持+，-，*，/运算，支持负数（用括号把负号括起来）和两位数的运算,暂不支持三位数和小数的运算"<<endl;
	char ch1[50];                                //中缀表达式的字符串
	char ch2[50];                                //后缀表达式的字符串

	while(1){
		cout<<"请输入一个中缀表达式(以=结尾),输入#结束程序   例如：(-23)*2+(9-4)-8/2= "<<endl;
    cin>>ch1;
	if(ch1[0] == '#')
		break;
    fun1(ch1,ch2);                               //求后缀表达式
	cout<<"它的后缀表达式为："<<endl;
	cout<<ch2<<endl;
	char result[4] = {'0','0','0',0};            //最后一位为/0;
	fun2(ch2 , result);                          //求值
	cout<<"result = "<<result<<endl<<endl;             //最后值
	}

	return 0;
}

