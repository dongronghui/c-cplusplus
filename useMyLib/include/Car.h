/*
 * Car.h
 *
 *  Created on: Oct 21, 2013
 *      Author: dongronghui
 */

#ifndef CAR_H_
#define CAR_H_
#include "myCommon.h"
class Car {
public:
	Car();
	string hiWithoutVirtual();
	string hiWithoutVirtalAndOnlyCar();

	virtual string hiWithVirtual();
	virtual string hiWithVirtalAndOnlyCar();
	virtual ~Car();
};

#endif /* CAR_H_ */
