/*
 * BasicClass.cpp
 *
 *  Created on: Oct 23, 2013
 *      Author: dongronghui
 */

#include "BasicClass.h"
int BasicClass::_num=1000;
const int BasicClass::_num2=200;
BasicClass::BasicClass(){
	this->_age=100;
	this->_tall=101;
	this->_x=102;
}
BasicClass::BasicClass(int age,int tall,int x):_age(age),_tall(tall){
	this->_x=x;
}
void BasicClass::setX(int x){
	_x=x;
}
int BasicClass::getX(){
	_x=_x+10;
	return _x;
}
int BasicClass::getX() const{
	return _x;
}
void BasicClass::setAge(int age){
	this->_age=age;
}


