#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "contact.h"

int main(){
	int choice =0;
	Contact myContact;
	myContact.next = NULL;

	while (choice != 7) {
 		printf("Choose choicetion:\n");
 		printf("1 - Add contact.\n");
 		printf("2 - Delete contact.\n");
 		printf("7 - Exit.\n");
 		scanf("%d", &choice);

	switch(choice) {
		case 1:
			addContact(&myContact);
			break;
		case 2:
			deleteContact(&myContact);
			break;
		case 7:
			printf("Shutting down.\n\n");
			break;
		default:
			printf("Invalid choicetion. Try again.\n\n");
			break;

		}
 	}
}