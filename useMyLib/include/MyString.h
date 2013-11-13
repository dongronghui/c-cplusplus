/*
 * MyString.h
 *
 *  Created on: 2013-9-28
 *      Author: apple
 */

#ifndef MYSTRING_H_
#define MYSTRING_H_
#include <iostream>
using namespace std;
class MyString{
	private:
		int _size;
		char *_string;
	public:
		MyString();
		~MyString();
		friend ostream& operator<<(ostream& os,const MyString& str);
		char& operator[](int elem) const;
		MyString& operator=(const char*);

		void printme();
};


#endif /* MYSTRING_H_ */
