#ifndef CONFIG_H
#define CONFIG_H

enum MenuOptions
{
	MENU_MAIN,
	MENU_ADD,
	MENU_CHANGE,
	MENU_REMOVE,
	MENU_DISPLAY,
    MENU_LOAD,
    MENU_SAVE,
	MENU_CLOSE
};

enum Groups
{
	NO_GROUP,
	FAMILY,
	FRIENDS,
	COLLEAGUES
};

typedef struct contact
{
char name[80];
char phone[12];
enum Groups group;
}Contact;

#endif