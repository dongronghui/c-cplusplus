/*
 * testFunTemplate.cpp
 *
 *  Created on: Oct 24, 2013
 *      Author: dongronghui
 */
#include "gtest/gtest.h"
#include "funTemplate.cpp"

TEST(funTemplate,testModifyA){
	int as[]={2,4,7,8};
	modifyA(as);
	ASSERT_EQ(2+1000,as[0]);
	ASSERT_EQ(4+1000,as[1]);
	ASSERT_EQ(7+1000,as[2]);
	ASSERT_EQ(8+1000,as[3]);
}
TEST(funTemplate,testMyMax){
	int i1=185,i2=-76,i3=567;
	double d1=56.87,d2=90.23,d3=-3214.78;
	long g1=67854,g2=-912456,g3=673456;
	EXPECT_EQ(i3,MyMax(i1,i2,i3));
	EXPECT_EQ(d2,MyMax(d1,d2,d3));
	EXPECT_EQ(g3,MyMax(g1,g2,g3));

	EXPECT_EQ(2,MyMin<int>(2,4));
	EXPECT_EQ(2.4,MyMin(2.4,4.5));
}


