/*
 * testBasicClass.cpp
 *
 *  Created on: Oct 23, 2013
 *      Author: dongronghui
 */
#include "gtest/gtest.h"
#include "BasicClass.h"
void testConst(){
	const BasicClass cin;
	BasicClass in;
	cin.getX();
	in.getX();
}
TEST(BasicClass,testConstClass){
	const BasicClass cin;
	BasicClass in;
	//error: passing ‘const BasicClass’ as ‘this’ argument of ‘void BasicClass::setX(int)’ discards qualifiers [-fpermissive]
	//cin.setX(1000);
	ASSERT_EQ(102,cin.getX());
	in.setX(1000);
	ASSERT_EQ(1000+10,in.getX());
}
TEST(BasicClass,testStaticVar){
	BasicClass::setNum(234);
	EXPECT_EQ(234,BasicClass::getNum());
	EXPECT_EQ(3,BasicClass::getNum1());
	EXPECT_EQ(200,BasicClass::getNum2());
}


