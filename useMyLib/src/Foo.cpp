/*
 * Foo.cpp
 *
 *  Created on: Oct 20, 2013
 *      Author: dongronghui
 */

/****************************/
#include "Foo.h"
int Foo(int a, int b)
{
    if (a == 0 || b == 0)
    {
        throw "don't do that";
    }
    int c = a % b;
    if (c == 0)
        return b;
    return Foo(b, c);
}


