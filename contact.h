#ifndef CONTACT_H
#define CONTACT_H

Contact *ScanList(Contact *head, char name[]);

void deleteContact(Contact *head);

void addContact(Contact *head);

void searchContact(Contact *head);

char *convertGroupIdToName(int id);

#endif