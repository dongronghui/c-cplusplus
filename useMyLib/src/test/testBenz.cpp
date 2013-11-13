/*
 * testBenz.cpp
 *
 *  Created on: Oct 22, 2013
 *      Author: dongronghui
 */

#include "Benz.h"
#include "gtest/gtest.h"
#include <iostream>
using namespace std;
/**
 * summary:
 *  非virtual方法：
 * 	   C++对象上方法调用原则，很简单。
 * 	   C++只以左值为准，也就是说不管对象是由谁new出来的，C++只调用左值中定义的方法。
 * 	virtual方法：
 * 	    对于定义为virtual的方法，在运行时根据实际new的对象来决定方法调用。
 * 	    而对于非virtual方法，在编译器就决定了方法归属哪个对象。
 * 	误区：
 * 	   在C++中只有定义为virtual的方法，子类才能继承
 * 	   -》子类是否继承父类中的方法与方法是否为virtual无关。
 *
 * */
class BenzTest : public testing::Test {
protected:
	virtual void SetUp(){
		//cout<<"FunPara::SetUp()"<<endl;
	}
	virtual void TearDown(){
		//cout<<"FunPara::TearDown()"<<endl;
	}
};
TEST_F(BenzTest,test1){
	Benz bz;
	EXPECT_STREQ("Benz::hiWithoutVirtual()",bz.hiWithoutVirtual().c_str());
}
TEST_F(BenzTest,test2){
	Benz bz;
	EXPECT_STREQ("Car::hiWithoutVirtalAndOnlyCar()",bz.hiWithoutVirtalAndOnlyCar().c_str());
}

TEST_F(BenzTest,test3){
	Benz *pbz=new Benz;
	EXPECT_STREQ("Benz::hiWithoutVirtual()",pbz->hiWithoutVirtual().c_str());
	delete pbz;
}
TEST_F(BenzTest,test4){
	Benz *pbz=new Benz;
	EXPECT_STREQ("Car::hiWithoutVirtalAndOnlyCar()",pbz->hiWithoutVirtalAndOnlyCar().c_str());
	delete pbz;
}
TEST_F(BenzTest,test5){
	Car *pbz=new Benz;
	EXPECT_STREQ("Car::hiWithoutVirtual()",pbz->hiWithoutVirtual().c_str());
	delete pbz;
}
TEST_F(BenzTest,test6){
	Car *pbz=new Benz;
	EXPECT_STREQ("Car::hiWithoutVirtalAndOnlyCar()",pbz->hiWithoutVirtalAndOnlyCar().c_str());
	delete pbz;
}

TEST_F(BenzTest,test11){
	Benz bz;
	EXPECT_STREQ("Benz::hiWithVirtual()",bz.hiWithVirtual().c_str());
}
TEST_F(BenzTest,test12){
	Benz bz;
	EXPECT_STREQ("Car::hiWithVirtalAndOnlyCar()",bz.hiWithVirtalAndOnlyCar().c_str());
}
TEST_F(BenzTest,test13){
	Benz *pbz=new Benz;
	EXPECT_STREQ("Benz::hiWithVirtual()",pbz->hiWithVirtual().c_str());
	delete pbz;
}
TEST_F(BenzTest,test14){
	Benz *pbz=new Benz;
	EXPECT_STREQ("Car::hiWithVirtalAndOnlyCar()",pbz->hiWithVirtalAndOnlyCar().c_str());
	delete pbz;
}
TEST_F(BenzTest,test15){
	Car *pbz=new Benz;
	EXPECT_STREQ("Benz::hiWithVirtual()",pbz->hiWithVirtual().c_str());
	delete pbz;
}
TEST_F(BenzTest,test16){
	Car *pbz=new Benz;
	EXPECT_STREQ("Car::hiWithVirtalAndOnlyCar()",pbz->hiWithVirtalAndOnlyCar().c_str());
	delete pbz;
}

TEST_F(BenzTest,test20){
	Car *pbz=new Benz;
	//error: ‘class Car’ has no member named ‘hiWithoutVirtualOnlyInBenz’
	//EXPECT_STREQ("Car::hiWithVirtalAndOnlyCar()",pbz->hiWithoutVirtualOnlyInBenz().c_str());
	delete pbz;
}

