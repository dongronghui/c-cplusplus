/*
 * array.c
 *
 *  Created on: Nov 3, 2013
 *      Author: dongronghui
 */
#include <stdio.h>

/**
 * 数组名代表什么？
 * 0.数组具有连续存储的确定数目的元素
 * 1、代表指向某种数据类型的常量指针，比如对于int a[5]; a 的值为 &a[0]
 * 2. 特例：
 *   a) 当数组名作为sizeof的参数时候，sizeof返回整个数组的长度。
 *   b) 取一个数据名的地址所产生的是一个指向数组的指针，而不是一个指向某个指针的常量值的指针。
 *     所有对于一维数组，int a[9]; a 和&a
 * */
// 下面这个有点迷惑性，ap里面的sizeof(a)和ap外的sizeof(a)是不同的。
void ap(short a[]){
	printf("ap::sizeof(a):%d,a[1]:%d,*(a+1):%d\n",sizeof(a),a[1],*(a+1));
}
void ap1(short *a){
	printf("ap1::sizeof(a):%d,a[1]:%d,*(a+1):%d\n",sizeof(a),a[1],*(a+1));
}

void test1(){
	short a[3]={12,23,34};
	short b[3];
	short *c;
	short *d;
	printf("sizeof(a) is %d\n",sizeof(a));
	printf("sizeof(&a) is %d\n",sizeof(&a));
	printf("sizeof(a[0]) is %d\n",sizeof(a[0]));
	printf("sizeof(&a[0]) is %d\n",sizeof(&a[0]));
	printf("sizeof(a[1]) is %d\n",sizeof(a[1]));
	printf("sizeof(c) is %d\n",sizeof(c));
	printf("sizeof(*c) is %d\n",sizeof(*c));
	printf("a[0] is %d\n",a[0]);
	printf("&a:%x,a:%x,&a[0]:%x,(a+1)%x\n",&a,a,&a[0],(a+1));
	/**
	 *一切都说明，数组名既可以是数组首元素的指针，但又有很多特殊的地方。
	 * 比如：sizeof
	 * 再比如 &a
	 * */
	printf("*(a+1):%d,*(&a+1):%d,*((short *)&a+1):\d\n",*(a+1),*(&a+1),*((short *)&a+1));
	ap(a);
	ap(&a);
	ap(&a[0]);

	ap1(a);
	ap1(&a);
	ap1(&a[0]);
	c=a+1;
	d=&a[0]+1;

	printf("*c:%d,*(c+1):%d,*(c-1):%d,c[1]:%d,c[-1]:%d,1[c]:%d,-1[c]:%d,2[a]:%d\n ",*c,*(c+1),*(c-1),c[1],c[-1],1[c],(-1)[c],2[a]);
}
//一般是short m[][3]
void hm1(short (*m)[3]){
	printf("hm1:sizeof(m):%d,sizeof(m[0]):%d,sizeof(m[1]:%d\n",sizeof(m),sizeof(m[0]),sizeof(m[1]));
	printf("hm1:*((m+1)+1):%d,*(m[1]+1):%d,m[1][1]:%d\n",*(*(m+1)+1),*(m[1]+1),m[1][1]);
}
void hm(short m[2][3]){
	printf("hm:sizeof(m):%d,sizeof(m[0]):%d,sizeof(m[1]:%d\n",sizeof(m),sizeof(m[0]),sizeof(m[1]));
	printf("hm:*((m+1)+1):%d,*(m[1]+1):%d,m[1][1]:%d\n",*(*(m+1)+1),*(m[1]+1),m[1][1]);
}
void testMultiA(){
	/**
	 * 多维数组数组第一维的元素实际上是另一个数组
	 * int matrix[3][0]可以看作是一个一维数组，包含三个元素，只是每个元素恰好是包含10个整型元素的数组。
	 * matrix这个名字的值是一个指向它的第一个元素的指针，所以matrix是一个指向一个包含10个整数元素的数组的指针。
	 * */
	short m[2][3]={100,101,102,110,111,112};
	short (*p)[3]=m;
	printf("p:sizeof(p):%d,sizeof(p[0]):%d,sizeof(p[1]:%d\n",sizeof(p),sizeof(p[0]),sizeof(p[1]));

	printf("sizeof(m):%d,sizeof(m[0]):%d,sizeof(m[1]:%d\n",sizeof(m),sizeof(m[0]),sizeof(m[1]));
	printf("*((m+1)+1):%d,*(m[1]+1):%d,m[1][1]:%d\n",*(*(m+1)+1),*(m[1]+1),m[1][1]);
	hm(m);
	hm1(m);
}

void test333(){
	/**
	 * 指向数组的指针
	 * */
}
void test2(short *m){
	printf("sizeof(m):%d,sizeof(m[0]):%d,sizeof(m[1]:%d\n",sizeof(m),sizeof(m[0]),sizeof(m[1]));
}

int fn(int a){
	printf("i am fn %d!\n",a);
}
int * ff(int *a){
	printf(" a is *a:%d\n",*a);
}
int fy(){
	printf("fy\n\n");
}
void testFn(){
	/**
	 * 注意：函数名被使用时总是由编译器把它转换为函数指针，所以fn和&fn是等价的。
	 * */
	int (*pf)(int)=&fn;
	fn(100);
	pf(120);
	(*pf)(130);
	int *(*x[10])(int *);
	x[0]=ff;
	int aa=3;
	x[0](&aa);
	typedef int UINT32;
	typedef int (*MyFun)(int);
	//TODO:typedef int *(*MyFuns[10])(int *);
	UINT32 aaa;
	MyFun myFn=fn;
	myFn(234);
	//TODO:MyFuns as=f


}

int x[3];
int y[3];
int i;
int *p1,*p2;
void try1(){
	for(i=0;i<3;i++){
		x[i]=y[i];
	}
}
void try2(){
	for(p1=x,p2=y;p1-x<3;){
		*p1++;*p2++;
	}
}
void try3(){
	for(i=0,p1=x,p2=y;i<3;i++){
		*p1++=*p2++;
	}
}
void try4(){
	register int *p1,*p2;
	register int i;
	for(i=0,p1=x,p2=y;i<3;i++){
		*p1++=*p2++;
	}
}
void try5(){
	register int *p1,*p2;
	for(p1=x,p2=y;p1<&x[3];){
		*p1++=*p2++;
	}
}
int mainx(){
	testFn();
	//testMultiA();
	//test1();
	printf("Successfully!\n");
	return 0;
}
