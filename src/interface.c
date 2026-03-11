#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "../include/time.h"
#include "../include/interface.h"

void mainInterface()
{   
    int choice;
    while (1)
    {   
        choice = 0; // reset
        printf("\nTHE GYM'S MANAGER COMMAND INTERFRACE\n");
        printf("1. import Data \n");
        printf("2. export Data \n");
        printf("3. insert Trainer \n");
        printf("4. insert Trainer \n");
        printf("-1. exit\n");
        
        printf("make your choice betch: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("nigger what the fuck\n");

            while (getchar() != '\n'); // clear input buffer
            {
                ;
            }
            continue;
        }

        if (choice == -1)
        {   
            break;
        }

        switch (choice)
        {
        case 1: 
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        
        default:
            printf("nigger what the fuck\n");
            break;
        }
    }
}

