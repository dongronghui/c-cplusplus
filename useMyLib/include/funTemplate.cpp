/*
 * funTemplate.cpp
 *
 *  Created on: 2013-9-27
 *      Author: apple
 */
#include <iostream>
using namespace std;

template<typename T>
T MyMax(T a,T b,T c)
{
   if(b>a) a=b;
   if(c>a) a=c;
   return a;
}
template<typename T>//
T MyMin(T a,T b){
	return a;
	//return a<b?a:b;
}
template <typename Type,int size>
	void modifyA(Type (&as)[size]){
	for(int i=0;i<size;i++){
		as[i]=as[i]+1000;
	}
}




