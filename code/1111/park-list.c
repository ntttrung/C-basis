#include <stdio.h>
#include <stdlib.h>
#include "park-list.h"
#include <string.h>

parkNode *createListPark(){
	return NULL;
}

// check whether a list is empty
int isListEmptyPark(parkNode *root){
	return root == NULL;
}

// add more element
parkNode *addPark(parkNode *root, parkItem x){
	parkNode *temp = (parkNode*)malloc(sizeof(parkNode));
	temp->data = x;
	temp->next = NULL;
	
	if(isListEmptyPark(root)) return temp;
	
	parkNode *cur = root;
	while(cur->next != NULL){
		cur = cur->next;
	}
	cur->next = temp;
	return root;
}

// insert new element after a specific parkNode 
parkNode *insertAfterPark(parkNode *root, parkNode *p, parkItem x){
	if(isListEmptyPark(root)) return NULL;
	
	parkNode *temp = (parkNode*)malloc(sizeof(parkNode));
	temp->data = x;
	temp->next = p->next;
	p->next = temp;
	
	return root;
}

// insert new element before a specific parkNode 
parkNode *insertBeforePark(parkNode *root, parkNode *p, parkItem x){
	if(isListEmptyPark(root)) return NULL;
	
	parkNode *temp = (parkNode*)malloc(sizeof(parkNode));
	temp->data = x;
	temp->next = p;
	
	if(root == p) return temp;
	else{
		parkNode *cur = root;
		while(cur->next != p){
			cur = cur->next;
		}
		cur->next = temp;
		return root;
	}
	
}

// remove an element
parkNode *removeAtPark(parkNode *root, parkNode *p){
	if(isListEmptyPark(root)) return NULL;
	
	if(root == p){
		parkNode *temp = root->next;
		free(root);
		return temp;
	}
	
	parkNode *temp = root;
	while(temp->next != p){
		temp = temp->next;
	}
	temp->next = p->next;
	free(p);
	return root;
}

// search
parkNode *findPark(parkNode *root, char *x){
	if(isListEmptyPark(root)) return NULL;
	
	parkNode *temp = root;
	while(temp != NULL){
		if(!strcmp(temp->data.id, x)) return temp;
		temp = temp->next;
	}
	return NULL;
}

// last parkNode - TODO
parkNode *lastPark(parkNode *root){
	if(isListEmptyPark(root)) return NULL;
	
	parkNode *temp = root;
	while(temp->next != NULL){
		temp = temp->next;
	}
	return temp;
}

// nth parkNode - TODO
parkNode *nthPark(parkNode *root, int n){
	if(isListEmptyPark(root)) return NULL;
	
	parkNode *temp = root;
	int i = 1;
	while(temp->next != NULL && i < n){
		temp = temp->next;
		i++;
	}
	if(i == n) return temp;
	return NULL;
	
}

// length - TODO
int lengthPark(parkNode *root){
	if(isListEmptyPark(root)) return 0;
	
	parkNode *temp = root;
	int i = 1;
	while(temp->next != NULL){
		temp = temp->next;
		i++;
	}
	return i;
}

// free a list
void freeListPark(parkNode *root){
	parkNode *temp;
	while(root != NULL){
		temp = root->next;
		free(root);
		root = temp;
	}
}