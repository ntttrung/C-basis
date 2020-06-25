#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bus-list.h"

busNode *createListBus(){
	return NULL;
}

// check whether a list is empty
int isListEmptyBus(busNode *root){
	return root == NULL;
}

// add more element
busNode *addBus(busNode *root, busItem x){
	busNode *temp = (busNode*)malloc(sizeof(busNode));
	temp->data = x;
	temp->next = NULL;
	
	if(isListEmptyBus(root)) return temp;
	
	busNode *cur = root;
	while(cur->next != NULL){
		cur = cur->next;
	}
	cur->next = temp;
	return root;
}

// insert new element after a specific busNode 
busNode *insertAfterBus(busNode *root, busNode *p, busItem x){
	if(isListEmptyBus(root)) return NULL;
	
	busNode *temp = (busNode*)malloc(sizeof(busNode));
	temp->data = x;
	temp->next = p->next;
	p->next = temp;
	
	return root;
}

// insert new element before a specific busNode 
busNode *insertBeforeBus(busNode *root, busNode *p, busItem x){
	if(isListEmptyBus(root)) return NULL;
	
	busNode *temp = (busNode*)malloc(sizeof(busNode));
	temp->data = x;
	temp->next = p;
	
	if(root == p) return temp;
	else{
		busNode *cur = root;
		while(cur->next != p){
			cur = cur->next;
		}
		cur->next = temp;
		return root;
	}
	
}

// remove an element
busNode *removeAtBus(busNode *root, busNode *p){
	if(isListEmptyBus(root)) return NULL;
	
	if(root == p){
		busNode *temp = root->next;
		free(root);
		return temp;
	}
	
	busNode *temp = root;
	while(temp->next != p){
		temp = temp->next;
	}
	temp->next = p->next;
	free(p);
	return root;
}

// search
busNode *findBus(busNode *root, char *x){
	if(isListEmptyBus(root)) return NULL;
	
	busNode *temp = root;
	while(temp != NULL){
		if(!strcmp(temp->data.id, x)) return temp;
		temp = temp->next;
	}
	return NULL;
}

// last busNode - TODO
busNode *lastBus(busNode *root){
	if(isListEmptyBus(root)) return NULL;
	
	busNode *temp = root;
	while(temp->next != NULL){
		temp = temp->next;
	}
	return temp;
}

// nth busNode - TODO
busNode *nthBus(busNode *root, int n){
	if(isListEmptyBus(root)) return NULL;
	
	busNode *temp = root;
	int i = 1;
	while(temp->next != NULL && i < n){
		temp = temp->next;
		i++;
	}
	if(i == n) return temp;
	return NULL;
	
}

// length - TODO
int lengthBus(busNode *root){
	if(isListEmptyBus(root)) return 0;
	
	busNode *temp = root;
	int i = 1;
	while(temp->next != NULL){
		temp = temp->next;
		i++;
	}
	return i;
}

// free a list
void freeListBus(busNode *root){
	busNode *temp;
	while(root != NULL){
		temp = root->next;
		free(root);
		root = temp;
	}
}