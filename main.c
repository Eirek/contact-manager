#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "contact.h"


int main(int argc, char* argv[])
{
	int choice = -1;
	char buf[3];

	while (choice != MENU_CLOSE)
	{
		menu(MENU_MAIN);

		scanf("%d", &choice);

		menu(choice);
	}

	return 0;
}