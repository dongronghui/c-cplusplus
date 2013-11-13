/*
 * sort.c
 *
 *  Created on: Nov 9, 2013
 *      Author: dongronghui
 */
#include "stdio.h"
typedef struct _my_node{
	int value;
	int reserved;
}MY_NODE;

typedef struct _my_data{
	int age;
	int *abc;
	MY_NODE *node;
	char data[0];
}MY_DATA;
MY_DATA * data;
void initData(){
	data=(MY_DATA*)malloc(sizeof(MY_DATA)+sizeof(MY_NODE));
	data->abc=(int *)malloc(sizeof(int));
	data->node=(MY_NODE*)malloc(sizeof(MY_NODE));
}
void testS(){
	printf("sizeof(MY_DATA) is %d\n",sizeof(MY_DATA));

	MY_NODE node;
	node.value=100;
	node.reserved=300;
	int v=34;
	data->age=28;
	memcpy(data->abc,&v,sizeof(int));
	memcpy(data->node,&node,sizeof(MY_NODE));

	MY_NODE node1;
	node1.value=3100;
	node1.reserved=3300;
	memcpy(data->data,&node1,sizeof(MY_NODE));
}
void printData(){
	printf("=============\n");
		printf("age:%d,abc:%d,node->value:%d,node->reserved:%d\n",data->age,*(data->abc),data->node->value,data->node->reserved);
		MY_NODE *dd=(MY_NODE*)(data->data);
		printf("dd->value:%d,dd->reserved:%d\n",dd->value,dd->reserved);

}
int bubbleSort(int *as,int size){
	int tem;
	int i,j;
	for(i=0;i<size;i++){
		for(j=i+1;j<size;j++){
			if(as[i] > as[j]){
				tem =as[i];
				as[i] = as[j];
				as[j]=tem;
			}
		}
	}
}
int selSort(int *as,int size){
	int minIndex;
	int tem;
	int i,j;
	for(i=0;i<size;i++){
		minIndex=i;
		for(j=i+1;j<size;j++){
			if(as[minIndex] > as[j]){
				minIndex =j;
			}
		}
		tem=as[i];
		as[i]=as[minIndex];
		as[minIndex]=tem;
	}
}

void printMe(int *as,int size){
	int i;
	for(i=0;i<size;i++){
		printf(" as[%d]=%d\n",i,as[i]);
	}
}

int main(){
	printf("begin....\n");
	initData();
	testS();
	printData();
	printf("===============================\n");
	int as[5]={5,2,3,6,9};
	//bubbleSort(as,5);
	selSort(as,5);
	printMe(as,5);
	printf("Successful\n");
	return 0;
}



