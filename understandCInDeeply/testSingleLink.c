/*
 * testSingleLink.c
 *
 *  Created on: Nov 3, 2013
 *      Author: dongronghui
 */
#include <stdio.h>
typedef struct Node{
	struct NODE *next;
	int value;
}NODE;
void print_sll(NODE *root){
	NODE *cur;
	cur=root;
	if(NULL == cur){
		printf("sll is empty1\n");
		return;
	}
	printf(" value is:%d\n",cur->value);
	while(NULL != cur->next){

		cur=cur->next;
		printf(" value is:%d\n",cur->value);
	}
}
int create_new_node(NODE **new_node,int new_value){
	NODE *cur=(NODE*)malloc(sizeof(NODE));
	if(NULL == cur){
		return 1;
	}
	cur->value=new_value;
	cur->next=NULL;
	*new_node = cur;
	return 0;
}
int sll_del(NODE **root,int del_value){
	NODE *pre = NULL;
	NODE *cur = (*root);
	while(NULL != cur && cur->value != del_value){
		pre = cur;
		cur = cur->next;
	}
	//NOT FOUND or sll is empty!
	if(NULL == cur){
		printf("NOT FOUND\n");
		return 0;
	}
	//root need be delete!
	if(NULL == pre){
		(*root) = cur->next;
		free(cur);
		return 0;
	}
	pre->next = cur->next;
	free(cur);
}
int sll_insert(NODE **root,int new_value){
	NODE *new_node;
	if(0 != create_new_node(&new_node,new_value)){
		return 1;
	}
	NODE *pre = NULL;
	NODE *cur = (*root);
	while(NULL != cur && cur->value <= new_value){
		pre = cur;
		cur = cur->next;
	}
	//means *root is NULL.
	if(NULL == cur && NULL == pre){
		(*root) = new_node;
		return 0;
	}
	//means insert point is the most first.
	if(NULL == pre){
		(*root) = new_node;
		new_node->next = cur;
		return 0;
	}
	pre->next = new_node;
	new_node->next =cur;

	return 0;
}
int _main(){
	NODE *root = NULL;
	sll_insert(&root,10);
	sll_insert(&root,23);
	sll_insert(&root,10);
	sll_insert(&root,1);
	sll_insert(&root,11);
	sll_insert(&root,6);
	sll_insert(&root,2);
	sll_del(&root,11);
	sll_del(&root,13);
	printf("begin:\n");
	print_sll(root);
	printf("Successful!\n");
	return 0;
}


