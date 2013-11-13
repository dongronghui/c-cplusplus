/*
 * testMyString.cpp
 *
 *  Created on: Oct 23, 2013
 *      Author: dongronghui
 */
#include "gtest/gtest.h"
#include "MyString.h"
TEST(MyString,test){
	const char * name="abc";
	ASSERT_EQ(3ul,strlen(name));
	//char name1[]={'a','b','c','d','e'};
	//EXPECT_EQ(5ul,strlen(name1))<<"由于strlen是按照\\0来决定计算字符串长度";
	char name2[]={'a','b','c','d','e','\0'};
	ASSERT_EQ(5ul,strlen(name2));
	ASSERT_EQ(6ul,sizeof(name2));
}
TEST(byteAligned,test1){
	struct stu{
        char sex;
        int length;
        char name[10];
	};
	struct stu my_stu;
	EXPECT_EQ(20ul,sizeof(my_stu));

	struct stu1{
        char sex;
        int length;
        char name[10];
	}__attribute__ ((aligned (1)));
	struct stu1 my_stu1;
	EXPECT_EQ(20ul,sizeof(my_stu1));
	struct stu2{
        char sex;
        int length;
        char name[10];
	}__attribute__ ((packed));
	struct stu2 my_stu2;
	EXPECT_EQ(15ul,sizeof(my_stu2));
#pragma pack(2)
	struct stu3{
        char sex;
        int length;
        char name[10];
	};
	struct stu3 my_stu3;
	EXPECT_EQ(16ul,sizeof(my_stu3));
#pragma pack()
}
/*void testMyString1(){
	MyString* s=new MyString;
	*s="i amok";
	cout<<"*s[2]="<<(*s)[2]<<endl;
	s->printme();
	delete s;
}
void testMyString2(){
	MyString s;
	s="i amok!";
	cout<<"s[2]="<<s[1]<<endl;
	s.printme();
}
void testMyString3(){
	MyString s;
	//char name[]="i am ok!!";
	char name[]={'1','2','\0'};
	s=name;
	cout<<"name[1]="<<name[1]<<endl;
	s.printme();
}
void testMyString4(){
	MyString s;
	//char name[]="i am ok!!";
	const char* name="i am ok!!!!!!";
	s=name;
	cout<<"s[2]="<<s[2]<<endl;
	s.printme();
}
void testMyStringCout(){
	MyString s;
	s="i love huihui";
	cout<<"s is "<<s<<endl;
}*/



