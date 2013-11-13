/*
 * testModifyArray.cpp
 *
 *  Created on: Oct 21, 2013
 *      Author: dongronghui
 */
#include "gtest/gtest.h"
#include "ModifyArray.h"
TEST(modifyArrayByArrayPoint, modifyArrayByArrayPoint)
{
	int as[]={2,4,7,8};
	modifyArrayByArrayPoint(as,4);

	EXPECT_EQ(2+10,as[0]);
	EXPECT_EQ(4+10,as[1]);
	EXPECT_EQ(7+10,as[2]);
	EXPECT_EQ(8+10,as[3]);
}
TEST(modifyArrayByArrayRef, modifyArrayByArrayRef)
{
	int as[]={2,4,7,8};
	modifyArrayByArrayRef(as);

	EXPECT_EQ(2+100,as[0]);
	EXPECT_EQ(4+100,as[1]);
	EXPECT_EQ(7+100,as[2]);
	EXPECT_EQ(8+100,as[3]);
}



