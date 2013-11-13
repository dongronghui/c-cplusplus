#include "gtest/gtest.h"
#include "Foo.h"
#include <iostream>
using namespace std;


TEST(FooTest, HandleNoneZeroInput)
{
	//cout<<"i am ok"<<endl;
    EXPECT_EQ(2, Foo(4, 10));
    EXPECT_EQ(6, Foo(30, 18));
    //cout<<"i am over"<<endl;
}
