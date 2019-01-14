#ifndef CONFIG_H
#define CONFIG_H

enum Groups
{
	NO_GROUP,
	FAMILY,
	FRIENDS,
	COLLEAGUES
};

typedef struct Person Contact;

struct Person {
char name[80];
char phone[12];
enum Groups group;
Contact  *next;
};

#endif