#include <stdio.h>
#include <stdlib.h>
#include "linked-list.h"

node *createList(){
	return NULL;
}

// check whether a list is empty
int isListEmpty(node *root){
	return root == NULL;
}

// add more element
node *add(node *root, item x){
	node *temp = (node*)malloc(sizeof(node));
	temp->data = x;
	temp->next = NULL;
	
	if(isListEmpty(root)) return temp;
	
	node *cur = root;
	while(cur->next != NULL){
		cur = cur->next;
	}
	cur->next = temp;
	return root;
}

// insert new element after a specific node 
node *insertAfter(node *root, node *p, item x){
	if(isListEmpty(root)) return NULL;
	
	node *temp = (node*)malloc(sizeof(node));
	temp->data = x;
	temp->next = p->next;
	p->next = temp;
	
	return root;
}

// insert new element before a specific node 
node *insertBefore(node *root, node *p, item x){
	if(isListEmpty(root)) return NULL;
	
	node *temp = (node*)malloc(sizeof(node));
	temp->data = x;
	temp->next = p;
	
	if(root == p) return temp;
	else{
		node *cur = root;
		while(cur->next != p){
			cur = cur->next;
		}
		cur->next = temp;
		return root;
	}
	
}

// remove an element
node *removeAt(node *root, node *p){
	if(isListEmpty(root)) return NULL;
	
	if(root == p){
		node *temp = root->next;
		free(root);
		return temp;
	}
	
	node *temp = root;
	while(temp->next != p){
		temp = temp->next;
	}
	temp->next = p->next;
	free(p);
	return root;
}

// search
node *find(node *root, item x){
	if(isListEmpty(root)) return NULL;
	
	node *temp = root;
	while(temp != NULL){
		if(temp->data == x) return temp;
		temp = temp->next;
	}
	return NULL;
}

// last node - TODO
node *last(node *root){
	if(isListEmpty(root)) return NULL;
	
	node *temp = root;
	while(temp->next != NULL){
		temp = temp->next;
	}
	return temp;
}

// nth node - TODO
node *nth(node *root, int n){
	if(isListEmpty(root)) return NULL;
	
	node *temp = root;
	int i = 1;
	while(temp->next != NULL && i < n){
		temp = temp->next;
		i++;
	}
	if(i == n) return temp;
	return NULL;
	
}

// length - TODO
int length(node *root){
	if(isListEmpty(root)) return 0;
	
	node *temp = root;
	int i = 1;
	while(temp->next != NULL){
		temp = temp->next;
		i++;
	}
	return i;
}

// free a list
void freeList(node *root){
	node *temp;
	while(root != NULL){
		temp = root->next;
		free(root);
		root = temp;
	}
}


