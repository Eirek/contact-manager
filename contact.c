#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "contact.h"

void menu(short item)
{
	clear();

	char name[80];
	char phone[13];
	char group[10];
    char filename[120];

	switch (item)
	{
	case MENU_MAIN:
		printf("\n"
			" Welcome to Contact Manager!\n"
			" Please select option:\n"
			"  1) Add contact\n"
			"  2) Change contact name/phone/group\n"
			"  3) Remove contact\n"
			"  4) Display\n"
            "  5) Load contacts\n"
            "  6) Save contacts\n"
			"  7) Close the program\n\n- ");
		break;
	
	default:
		break;
	}
}

void clear()
{
	system("clear");
}
