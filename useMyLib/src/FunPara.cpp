/*
 * FunPara.cpp
 *
 *  Created on: Oct 20, 2013
 *      Author: dongronghui
 */
#include "FunPara.h"
/**
 * Use to demo how different passing way of function parameter to effect the value of parameter.
 *
 * */
void funValueParamDontModifyIt(int a){
	a=a+1;
}
void funPointParamModifyIt(int* a){
	*a =*a +1;
}
void funRefParamModifyIt(int& a){
	a=a+1;
}



