/*
 * Car.cpp
 *
 *  Created on: Oct 21, 2013
 *      Author: dongronghui
 */

#include "Car.h"

Car::Car() {
	// TODO Auto-generated constructor stub

}
string Car::hiWithoutVirtual(){
	return "Car::hiWithoutVirtual()";
}
string Car::hiWithoutVirtalAndOnlyCar(){
	return "Car::hiWithoutVirtalAndOnlyCar()";
}

string Car::hiWithVirtual(){
	return "Car::hiWithVirtual()";
}
string Car::hiWithVirtalAndOnlyCar(){
	return "Car::hiWithVirtalAndOnlyCar()";
}

Car::~Car() {
	// TODO Auto-generated destructor stub
}

