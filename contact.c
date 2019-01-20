#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "config.h"
#include "contact.h"

Contact* makeNode(char *name, char *phone, char *group) {
	Contact *newNode = (Contact *) malloc(sizeof(Contact));
	strcpy(newNode->name, name);
	strcpy(newNode->phone, phone);
	newNode->group = convertGroupNameToId(group);
	newNode->next = NULL;
	return newNode;
}

Contact* addContact(Contact* head){
	
	Contact *newContact;
	char name[80];
	char phone[12];
	char group[10];

	printf("Enter the name: \n");
 	scanf("%s", name);
 	printf("Enter the phone: \n");
 	scanf("%s", phone);
 	printf("Enter the group: \n");
 	scanf("%s", group);
	strUpper(name);

	if(!isExist(head, name)){

		newContact = makeNode(name, phone, group);
		newContact->next = head;
		head = newContact;
	}
	return head;
} 

void deleteContact(Contact **head){

	char name[80];

 	printf("Enter the name of the contact you want to delete:\n");
 	scanf("%s", &name);
	strUpper(name);	

	Contact *currentContact, *previousContact;

  	previousContact = NULL;

  	for (currentContact = *head;
		currentContact != NULL;
		previousContact = currentContact, currentContact = currentContact->next) {

    	if (strcmp(currentContact->name, name) == 0) {
      		if (previousContact == NULL) {
        
        		*head = currentContact->next;
      		} else {
        
        		previousContact->next = currentContact->next;
      		}
            free(currentContact);
      		return;
    	}
  	}

}

void searchContact(Contact *head){
	system("clear");
	char searchName[80];
	char searchPhone[12];
	char searchGroup[10];
	int searchChoice = 0;

	if(head == NULL) {
		printf("Contact list is Empty!\n");
	} else {

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
			strUpper(searchName);
			printf("\n");

			while(head != NULL) {
				if(strcmp(head->name, searchName) == 0){
					printf("Found contact with name %s:\n", searchName);
					printf("%-20s %-12s %-10s\n", "NAME", "PHONE", "GROUP");
					printf("%-20s %-12s %-10s\n", head->name, head->phone, convertGroupIdToName(head->group));

				} 
				head = head->next;
			}
			break;

			case 2:

			printf("Enter the phone: ");
			scanf("%s", searchPhone);
			printf("\n");

			while(head != NULL) {
				if(strcmp(head->phone, searchPhone) == 0){
					printf("Found contact with phone %s:\n", searchPhone);
					printf("%-20s %-12s %-10s\n", "NAME", "PHONE", "GROUP");
					printf("%-20s %-12s %-10s\n", head->name, head->phone, convertGroupIdToName(head->group));

				} 
				head = head->next;
			}
			break;

			case 3:

			printf("Enter the group: ");
			scanf("%s", searchGroup);
			strUpper(searchGroup);
			
			printf("\n");
			printf("Contacts in group %s:\n", searchGroup);
			printf("%-20s %-12s %-10s\n", "NAME", "PHONE", "GROUP");
			while(head != NULL) {				
				if(strcmp(convertGroupIdToName(head->group), searchGroup) == 0){					
					printf("%-20s %-12s %-10s\n", head->name, head->phone, convertGroupIdToName(head->group));
				}
				head = head->next;
				}
			 
			break;

			case 4:

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
}

char *convertGroupIdToName(int id){
	switch(id){
		case 1:
			return "FAMILY";
		case 2:
			return "FRIENDS";
		case 3:
			return "COLLEAGUES";
		default:
			return "NOGROUP";
	}
}

void saveContactsToFile(char *filename, Contact *head){

	printf("Please enter the name and extension of file (e.g. contacts.txt): ");
	scanf("%s", filename);
	FILE *newFile = fopen(filename, "w");

	while(head != NULL){

		fprintf(newFile, "%s %s %s\n", head->name, head->phone, convertGroupIdToName(head->group));
		head = head->next;
	}
	fclose(newFile);
}

int convertGroupNameToId(char *group) {

		if (strcmp(group, "family") == 0)
		return FAMILY;
		else if (strcmp(group, "friends") == 0)
		return FRIENDS;
		else if (strcmp(group, "colleagues") == 0)
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

Contact* clearList(Contact* head){
	Contact *nextContact;

	while(head != NULL) {
		nextContact = head->next;
		free(head);
		head = nextContact;
	}
	return head;
}

Contact* loadContactsFromFile(char *filename, Contact *head){

	char name[80];
	char phone[12];
	char group[10];

	Contact *temp;

	head = clearList(head);

	printf("Please enter the name and extension of file to load (e.g. contacts.txt): ");
	scanf("%s", filename);

	FILE *loadFile = fopen(filename, "r+");

	if(loadFile == NULL){
		printf("Error: Cannot open the file\n");
	} else{

	while(!feof(loadFile)) {
		fscanf(loadFile, "%s", name);
		fscanf(loadFile, "%s", phone);
		fscanf(loadFile, "%s", group);

		temp = makeNode(name, phone, group);

		if(head == NULL){
			head = temp;
		} else {
			temp->next = head;
		}

		head = temp;
	}

	fclose(loadFile);
	printf("File %s loaded.\n");
	
	}
	return head;
}

void changeContact(Contact* head) {

	system("clear");
	char searchName[80];
	char newName[80];
	char newPhone[12];
	char newGroup[10];
	int searchChoice = 0;
	Contact *searchContact;


	if(head == NULL) {
		printf("Contact list is Empty!\n");		
		} else {
			while(head != NULL) {

				printf("Enter the name: ");
				scanf("%s", searchName);
				strUpper(searchName);
				printf("\n");

				if(strcmp(head->name, searchName) == 0){
					printf("Found contact with name %s:\n", searchName);
					searchContact = head;
				} else {
					printf("No contact with name %s found\n", searchName);
				}
				head = head->next;
			}

		while (searchChoice < 1){
			printf("1. Change name\n");
			printf("2. Change phone\n");
			printf("3. Change group\n");
			printf("What do you want to change to contact %s: ", searchContact);
			scanf("%d", &searchChoice);

			switch(searchChoice){

				case 1:
					printf("Enter new name fo contact: \n");
					scanf("%s", newName);
					strUpper(newName);


					if(!isExist(searchContact, newName)) {
						strcpy(searchContact->name, newName);
					}
						searchContact =	searchContact->next;  

					break;

				case 2:
					printf("Enter new phone fo contact: \n");
					scanf("%s", newPhone);

					strcpy(searchContact->phone, newPhone);

					break;

				case 3:
					printf("Enter new group fo contact: \n");
					scanf("%s", newGroup);
					strUpper(newGroup);

					searchContact->group = convertGroupNameToId(newGroup);

					break;
			}
		}		
	}
}

void strUpper(char *str)
{
	unsigned char *c = (unsigned char *)str;

	while (*c) {
		*c = toupper((unsigned char)*c);
		c++;
	}

	return;
}

