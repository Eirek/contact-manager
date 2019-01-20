#ifndef CONTACT_H
#define CONTACT_H

#include <stdbool.h>

void deleteContact(Contact **head);

Contact* addContact(Contact* head);

Contact* makeNode(char *name, char *phone, char *group);

Contact* clearList(Contact* head);

bool isExist(Contact *head, char *name);

void searchContact(Contact *head);

char *convertGroupIdToName(int id);

int convertGroupNameToId(char *name);

void saveContactsToFile(char *filename, Contact *head);

Contact* loadContactsFromFile(char *filename, Contact *head);

void changeContact(Contact* head);

void strUpper(char *str);

#endif