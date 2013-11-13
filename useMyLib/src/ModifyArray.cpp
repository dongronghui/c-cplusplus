/*
 * ModifyArray.cpp
 *
 *  Created on: Oct 21, 2013
 *      Author: dongronghui
 */
#include "ModifyArray.h"
#include "myCommon.h"
//Use normal array point way to modify array's value.
void modifyArrayByArrayPoint(int *as,int size){
	for(int i=0;i<size;i++){
		as[i]=as[i]+10;
	}
}
//Use array ref to modify array's value.
void modifyArrayByArrayRef(int (&as)[4]){
	for(int i=0;i<4;i++){
		as[i]=as[i]+100;
	}
}


