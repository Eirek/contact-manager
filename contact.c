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

void searchContact(Contact *head){
	char searchName[80];
	char searchPhone[12];
	int serachGroup;
	int searchChoice = 0;

	while (searchChoice < 1 || searchChoice > 3){
		printf("1. Name\n");
		printf("2. Phone\n");
		printf("3. Group\n");
		printf("How would you like to search: ");
		scanf("%d", &searchChoice);

		switch(searchChoice){
			case 1:
			printf("Enter the name: ");
			scanf("%s", searchName);
			printf("\n");
			while(head != NULL) {
				if(strcmp(head->name,searchName) == 0){
					printf("Found contact with name %s", searchName);
					printf("%s %s %d\n", head->name, head->phone, head->group);

				}
				head = head->next;
			}
			break;

		}
}
}

