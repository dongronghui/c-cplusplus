/*
 * Benz.h
 *
 *  Created on: Oct 21, 2013
 *      Author: dongronghui
 */

#ifndef BENZ_H_
#define BENZ_H_
#include "Benz.h"
#include "Car.h"
#include "myCommon.h"
class Benz : public Car{
public:
	Benz();
	string hiWithoutVirtual();
	string hiWithoutVirtualOnlyInBenz();
	virtual string hiWithVirtual();
	virtual ~Benz();
};

#endif /* BENZ_H_ */
