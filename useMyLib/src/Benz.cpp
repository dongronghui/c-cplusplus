/*
 * Benz.cpp
 *
 *  Created on: Oct 21, 2013
 *      Author: dongronghui
 */

#include "Benz.h"

Benz::Benz() {
	// TODO Auto-generated constructor stub

}
string Benz::hiWithoutVirtual(){
	return "Benz::hiWithoutVirtual()";
}
string Benz::hiWithVirtual(){
	return "Benz::hiWithVirtual()";
}
string Benz::hiWithoutVirtualOnlyInBenz(){
	return Benz::hiWithoutVirtualOnlyInBenz();
}
Benz::~Benz() {
	// TODO Auto-generated destructor stub
}

