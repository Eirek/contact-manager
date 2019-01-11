#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


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

Contact* makeNode(char *name, char *phone, char *group) {
	Contact *newNode = (Contact *) malloc(sizeof(Contact));
	strcpy(newNode->name, name);
	strcpy(newNode->phone, phone);
	newNode->group = convertGroupNameToId(group);
	newNode->next = NULL;
	return newNode;
}

Contact* addContact(Contact* head){
	
	Contact *newEntry;
	char name[80];
	char phone[12];
	char group[10];

	printf("Enter the name: \n");
 	scanf("%s", name);
 	printf("Enter the phone: \n");
 	scanf("%s", phone);
 	printf("Enter the group: \n");
 	scanf("%s", group);

	if(!isExist(head, name)){
		newEntry = makeNode(name, phone, group);
		newEntry->next = head;
		head = newEntry;
	}
	return head;
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
 		head->next = delNode->next;
 		printf("Contact with name %s deleted.\n\n", name);
 		free(delNode);
 	}
 	else
 		printf("The contact was not found.\n");
}


void searchContact(Contact *head){
	system("clear");
	char searchName[80];
	char searchPhone[12];
	char searchGroup[10];
	int searchChoice = 0;

	while (searchChoice < 1){
		printf("1. Name\n");
		printf("2. Phone\n");
		printf("3. Group\n");
		printf("4. Show all contacts\n");
		printf("How would you like to search: ");
		scanf("%d", &searchChoice);

		switch(searchChoice){
			case 1:
			printf("Enter the name: ");
			scanf("%s", searchName);
			printf("\n");
			if(head == NULL) {
				printf("Contact list is Empty!\n");
			}
			while(head != NULL) {
				if(strcmp(head->name, searchName) == 0){
					printf("Found contact with name %s:\n", searchName);
					printf("%-20s %-12s %-10s\n", "NAME", "PHONE", "GROUP");
					printf("%-20s %-12s %-10s\n", head->name, head->phone, convertGroupIdToName(head->group));

				} else {
					printf("No contact with name %s found\n", searchName);
				}
				head = head->next;
			}
			break;

			case 2:
			printf("Enter the phone: ");
			scanf("%s", searchPhone);
			printf("\n");
			if(head == NULL) {
				printf("Contact list is Empty!\n");
			}
			while(head != NULL) {
				if(strcmp(head->phone, searchPhone) == 0){
					printf("Found contact with phone %s:\n", searchPhone);
					printf("%-20s %-12s %-10s\n", "NAME", "PHONE", "GROUP");
					printf("%-20s %-12s %-10s\n", head->name, head->phone, convertGroupIdToName(head->group));

				} else {
					printf("No contact with phone %s found\n", searchPhone);
				}
				head = head->next;
			}
			break;

			case 3:
			if(head == NULL) {
				printf("Contact list is Empty!\n");
				
			}
			printf("Enter the group: ");
			scanf("%s", searchGroup);
			printf("\n");
			printf("Contacts in group %s:\n", searchGroup);
			printf("%-20s %-12s %-10s\n", "NAME", "PHONE", "GROUP");
			while(head != NULL) {				
				if(strcmp(convertGroupIdToName(head->group), searchGroup) == 0){					
					printf("%-20s %-12s %-10s\n", head->name, head->phone, convertGroupIdToName(head->group));
				} else {
					printf("No contacts in group %s\n", searchGroup);
					break;
				}
				head = head->next;
				}
			 
			break;

			case 4:
				if(head == NULL) {
					printf("Contact list is Empty!\n");
					break;
				}
			printf("\n");
			printf("Displaying all contacts:\n");
			printf("%-20s %-12s %-10s\n", "NAME", "PHONE", "GROUP");
			while(head != NULL) {							
				printf("%-20s %-12s %-10s\n", head->name, head->phone, convertGroupIdToName(head->group));
				head = head->next;
				} 			 
			break;

			default:
				printf("Invalid option.\n");
				break;

		}
	}
}

char *convertGroupIdToName(int id){
	switch(id){
		case 1:
			return "family";
		case 2:
			return "friends";
		case 3:
			return "colleagues";
		default:
			return "nogroup";
	}
}

void saveContactsToFile(char *filename, Contact *head){

	printf("Please enter the name and extension of file (e.g. contacts.txt): ");
	scanf("%s", filename);
	FILE *newFile = fopen(filename, "w");

	while(head != NULL){
		fprintf(newFile, "%s %s %d\n", head->name, head->phone, head->group);
		head = head->next;
	}
	fclose(newFile);
}

int convertGroupNameToId(char *name) {
		if (strcmp(name, "family") == 0)
		return FAMILY;
		else if (strcmp(name, "friends") == 0)
		return FRIENDS;
		else if (strcmp(name, "colleagues") == 0)
		return COLLEAGUES;
		else
		return NO_GROUP;
}

bool isExist(Contact *head, char *name){
	Contact *checkNode = head;
    while(checkNode){
    	if(strcmp(name,checkNode->name) == 0 ){
        	printf("This contact already exists !!! \n");
            return true;
        }
     checkNode = checkNode->next;
	}
	return false;	
}
