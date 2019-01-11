#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "contact.h"

int main(){

	int choice =0;
	char filename[100];
	Contact* myContact;

	while (choice != 7) {
 		printf("Choose option:\n");
 		printf("1 - Add contact.\n");
 		printf("2 - Delete contact.\n");
		printf("3 - Search for contact.\n");
		printf("5 - Save contacts.\n");
 		printf("7 - Exit.\n");
 		scanf("%d", &choice);

	switch(choice) {
		case 1:
			myContact = addContact(myContact);
			break;
		case 2:
			deleteContact(myContact);
			break;
		case 3:
			searchContact(myContact);
			break;
		case 5:
			saveContactsToFile(filename, myContact);
			break;
		case 7:
			printf("Shutting down.\n\n");
			break;
		default:
			printf("Invalid option. Try again.\n\n");
			break;

		}
 	}
}