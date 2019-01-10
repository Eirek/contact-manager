#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "contact.h"

Contact *ScanList(Contact *head, char *sName){
	Contact *previous, *current;
	previous = head;
	current = head->next;

	while ((current != NULL) && (strcmp(current->name, sName) != 0)) {
		previous = current;
		current = current->next;
	}
	return previous;
}

void addContact(Contact *head) {
	Contact *newNode, *prevNode, *nextNode;
	newNode = (Contact *) malloc(sizeof(Contact));

	printf("Enter the name: \n");
	scanf("%s",&newNode->name);
	printf("Enter the phone: \n");
	scanf("%s",&newNode->phone);
	printf("Enter the group: \n");
	scanf("%d",&newNode->group);

	prevNode = ScanList(head, newNode->name);
	nextNode = prevNode->next;

	if ((nextNode == NULL) || (strcmp(nextNode->name, newNode->name) != 0)){
		prevNode->next = newNode;
		newNode->next = nextNode;
		printf("Contact added.\n\n");
	}
	else {
		printf("Contact already exists.\n\n");
		free(newNode);
	}
}

void deleteContact(Contact *head) {
 	char name[80];  
 	Contact *delNode; 
 	Contact *prevNode; 

 	printf("Enter the name of the contact you want to delete:\n");
 	scanf("%s", &name);

 	prevNode = ScanList(head, name);
 	delNode = prevNode->next;

 	if (delNode != NULL && strcmp(delNode->name, name) == 0) {
 		prevNode->next = delNode->next;
 		printf("Contact with name %s deleted.\n\n", name);
 		free(delNode);
 	}
 	else
 		printf("The contact was not found.\n");
}

