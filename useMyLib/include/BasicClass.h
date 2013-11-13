/*
 * BasicClass.h
 *
 *  Created on: Oct 23, 2013
 *      Author: dongronghui
 */

#ifndef BASICCLASS_H_
#define BASICCLASS_H_
/*
 * 达到宏的效果，兼有函数的好处，那我们何乐而不为呢？
 * 1. inline只是对编译器的一个建议，不见得编译器真的在原地展开（比如递归就不行）
 * */

#include "myCommon.h"
/*
 * 关于类的内联函数需要注意的几点：
 * 1. 在类的成员函数声明处即定义的函数不管有没有关键字inline，都是内联函数
 * 2. inline函数也可以在声明外定义（跟普通的方法定义方式一样），只是在声明时一定要指定
 * 为内联函数，在定义时inline关键词可以省略
 *
 * mutable: 不受const控制的变量
 *
 * 静态成员：这个必须说的是，其实静态成员就是有了特性类这个名字空间限制的全局变量而已。
 * 所有的静态变量必须有初始化。
 * 1. 静态成员不可以在声明时就初始化,必须在实现处初始化。
 * 2. 常量静态成员可以在声明处初始化，也可以在实现处初始化。
 * 3. 静态成员函数不能是const或者volatile，也没有所有的this指针
 * 4. 静态变量只有静态成员能访问。
 * */

class BasicClass{
private:
	int _age;
	int _tall;
	int _x;
	mutable int count;
	//ERROR: ISO C++ forbids in-class initialization of non-const static member `_num'
	//static int _num=52;
	static int _num;

	const static int _num1=3;
	const static int _num2;
public:
	BasicClass();
	BasicClass(int age,int tall,int x);
	static void setNum(int num){
		_num=num;
	}
	static int getNum1(){return _num1;}
	static int getNum2(){return _num2;}
	//ERROR: static member function `static int MyInline::getNum()' cannot have `const' method qualifier
	//static int getNum() const{return _num;}
	static int getNum(){return _num;}

	inline int getTall() const{
		//ERROR: assignment of data-member `MyInline::_tall' in read-only structure
		//_tall=_tall+1;
		count=count+1;
		return this->_tall;
	}
	void setX(int x);
	/*
	 * O'shit,下面两个函数竟然在C++中形成了重载。
	 * */
	int getX();
	int getX() const;
	int getAge(){
		//静态变量只有静态成员能访问。
		//num=1;
		return _age;
	}
	inline void setAge(int age);
};

#endif /* BASICCLASS_H_ */
