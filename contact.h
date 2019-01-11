#ifndef CONTACT_H
#define CONTACT_H

#include <stdbool.h>

Contact *ScanList(Contact *head, char name[]);

void deleteContact(Contact *head);

Contact* addContact(Contact* head);

Contact* makeNode(char *name, char *phone, char *group);

bool isExist(Contact *head, char *name);

void searchContact(Contact *head);

char *convertGroupIdToName(int id);

int convertGroupNameToId(char *name);

void saveContactsToFile(char *filename, Contact *head);


#endif