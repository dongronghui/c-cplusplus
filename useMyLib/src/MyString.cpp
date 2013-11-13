/*
 * MyString.cpp
 *
 *  Created on: Oct 23, 2013
 *      Author: dongronghui
 */
/*
 * MyString.cpp
 *
 *  Created on: 2013-9-28
 *      Author: apple
 */
/*
 * 友元：在某些情况下，允许某个函数而不是整个程序可以访问类的私有成员，这样做会比较方便，友元机制
 * 就是允许一个类授权其他函数访问它的非公有成员。
 * 1. 友元只能出现在类的生命区，不需要在类中实现该方法
 * 2. 友元不受其在类体中被声明的public，private和protected区的影响。
 * */
#include "myCommon.h"
#include <iostream>
#include <cassert>
#include "MyString.h"
using namespace std;
MyString::MyString(){
}
MyString::~MyString(){
}
void MyString::printme(){
	printf("[%d]|%s|\n",_size,_string);
}
//这里的入参不能是char *sobj,因为C语言不允许把 const char*的指针赋值给char*,反之则可以。
//另外：定义成const的理由就是不希望更改sojb的值了。
MyString& MyString::operator=(const char* sobj){
	if(sobj==NULL){
		_size=0;
		//delete[] _string;
		_string=0;
	}else{
		_size=strlen(sobj);
		//TODO: 在使用非指正的方式时，这个会产生段错误。
		//delete[] _string;
		//注意：strlen返回的字符串大小不包含\0，所以我们在申请
		//空间的时候需要增加1
		_string = new char[_size+1];
		strcpy(_string,sobj);
	}
	return *this;
}
ostream& operator<<(ostream& os,const MyString& str){
	os<<str._string;
	return os;
}

char& MyString::operator [](int elem) const{
	return _string[elem];
}

/*int main(){
	//以指针的方式操作
	cout<<"Create by point!"<<endl;
	testMyString1();
	//以非指针的方式操作
	cout<<"Create by non point!!!!"<<endl;
	testMyString2();
	cout<<"x"<<endl;
	testMyString3();
	testMyString4();
	testMyStringCout();
	cout<<"Ok"<<endl;
	return 0;
}*/





