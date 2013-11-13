/*
 * testFunPara.cpp
 *
 *  Created on: Oct 20, 2013
 *      Author: dongronghui
 */
#include "FunPara.h"
#include "gtest/gtest.h"
#include <iostream>
using namespace std;
class FunParaTest : public testing::Test {
protected:
	virtual void SetUp(){
		//cout<<"FunPara::SetUp()"<<endl;
	}
	virtual void TearDown(){
		//cout<<"FunPara::TearDown()"<<endl;
	}
};

TEST_F(FunParaTest,testPara1){
	//void funValueParamDontModifyIt(int a);
	//void funPointParamModifyIt(int* a);
	//void funRefParamModifyIt(int& a);
	int a=5;
	funValueParamDontModifyIt(a);
	ASSERT_EQ(5,a)<<"para value pass just modify local variable a's value within function.";
	funPointParamModifyIt(&a);
	ASSERT_EQ(6,a)<<"handle point should modify value of a.";
	funRefParamModifyIt(a);
	ASSERT_EQ(7,a)<<"handle ref of a will modify vlaue of a.";
}

