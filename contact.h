#ifndef CONTACT_H
#define CONTACT_H


void add(char *name, char *phone, int group);


void removeContact(char *name);

void modify(char *name, char *phone, int group);


void save(char *filename);


void load(char *filename);

#endif