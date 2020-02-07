#define DEBUG 0

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//For getch
#include <conio.h>

//Wrapper
#include "mci_wrapper.h"


int main(int argc, char *argv[])
{
	//Pressed key
	int key = 0;

	char short_path[255] = {0};
	
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

	//
	if (argc < 2)
	{
		printf("Nothing to play.\n");
		return EXIT_FAILURE;
	}
	
	GetShortPathName(argv[1], short_path, sizeof(short_path));
	
	printf("Track: %s\n", argv[1]);
	printf("\n");
	printf("Keys:\n");
	printf("\n");
	printf("P - pause\n");
	printf("Q - quit\n");

	play(short_path);

	do
	{
		key = getch();
		
		switch (key)
		{
			//P key
			case 112:
			{
				static is_played = true;

				if (!is_played)
				{
					if (!play(short_path))
					{
						printf("%s", mci_error_text);
						return EXIT_FAILURE;
					}

					is_played = true;
				}
				else
				{
					if (!pause(short_path))
					{
						printf("%s", mci_error_text);
						return EXIT_FAILURE;
					}

					is_played = false;
				}

				break;
			}
			
			default: break;
		}
		
		if (DEBUG == 1)
			printf("Pressed key: %d\n", key);
	}
	//Q key
	while(key != 113);

	return EXIT_SUCCESS;
}

