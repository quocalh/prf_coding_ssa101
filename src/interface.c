#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "../include/time.h"
#include "../include/interface.h"

#define CONFUSED_STRING "what the fuck nigga"

void mainInterface(SystemManager* SystemManager)
{   
    int choice;
    while (1)
    {   
        choice = 0; // reset
        printf("\n\n\n\n\n");
        printf("\nTHE GYM'S MANAGER COMMAND INTERFRACE\n");
        printf("1. Import clients' Data \n");
        printf("2. Import trainers' Data\n");

        // client trainer data are exported automatically by the end yk
        printf("3. set Trainer's salary \n");
        printf("4. set Client's badge \n");

        printf("5. Insert Trainer...\n");
        printf("6. Insert Client... \n");
        
        printf("7. Sorted Trainer Display (Salary - Ascending)\n");
        printf("8. Sorted Trainer Display (Salary - Descending)\n");

        printf("9. Trainers Display \n");
        printf("10. Clients Display \n");

        printf("11.A list of Trainers by keywords...\n");
        printf("12.A list of Clients by keywords...\n");

        printf("13.Finding a Trainer by their ID...\n");
        printf("14.Finding a Client by their ID...\n");


        printf("-1. exit\n");
        
        printf("make your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf(CONFUSED_STRING);
            printf("\n");

            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        if (choice == -1)
        {   
            break;
        }

        switch (choice)
        {
        case 1:
            interfaceImportClientData(SystemManager);
            break;

        case 2:
            interfaceImportTrainerData(SystemManager);
            break;

        case 3:
            interfaceSetTrainerSalary(SystemManager);
            break;

        case 4:
            interfaceSetClientBadge(SystemManager);
            break;

        case 5:
            interfaceInsertTrainer(SystemManager);
            break;

        case 6:
            interfaceInsertClient(SystemManager);
            break;

        case 7:
            interfaceDisplayTrainersSalaryAsc(SystemManager);
            break;

        case 8:
            interfaceDisplayTrainersSalaryDesc(SystemManager);
            break;

        case 9:
            interfaceDisplayClients(SystemManager);
            break;

        case 10:
            interfaceDisplayClients(SystemManager);
            break;

        case 11:
            interfaceListTrainersByKeyword(SystemManager);
            break;

        case 12:
            interfaceListClientsByKeyword(SystemManager);
            break;

        case 13:
            interfaceFindTrainerByID(SystemManager);
            break;

        case 14:
            interfaceFindClientByID(SystemManager);
            break;

        default:
            printf(CONFUSED_STRING);
            printf("\n");
            break;
        }
        printf("\n\n");
    }
}

void interfaceImportClientData(SystemManager* SystemManager)
{   
    importClientData(SystemManager, SystemManager->fileNameClient);
    printf("Successfully imported the client's data");
}
void interfaceImportTrainerData(SystemManager* SystemManager)
{
    importTrainerData(SystemManager, SystemManager->fileNameTrainer);
    printf("Successfully imported the trainer's data");
}

// Set badges
void interfaceSetClientBadge(SystemManager* SystemManager)
{
    int clientID;
    char Badge[MAX_NAME_LENGTH];
    
    printf("Please fill in their ID: ");
    scanf("%d", &clientID);

    printf("Name -> %s\n", SystemManager->clients[clientID].name);

    printf("Pls fill in their Badge: ");
    scanf("%s", &Badge);

    Client* client = &SystemManager->clients[clientID];
    printf("The client with the\n\tID: %d \n\tname: %s\n has their badge turned into: %s \n",
        clientID, client->name, Badge
    );
}
void interfaceSetTrainerSalary(SystemManager* SystemManager)
{
    int TrainerID;
    int salary;

    printf("Please fill in their ID: ");
    scanf("%d", &TrainerID);

    printf("Name -> %s\n", SystemManager->trainers[TrainerID].name);

    printf("The new salary: ");
    scanf("%d", &salary);

    Trainer* trainer = &SystemManager->trainers[TrainerID];
    printf("The trainer with the\n\tID: %d \n\tname: %s\n has their salary turned into: %d \n",
        TrainerID, trainer->name, salary
    );
}

// Insert records
void interfaceInsertTrainer(SystemManager* SystemManager)
{
    char name[MAX_LENGTH_NAME];
    int salary;

    printf("Enter trainer name: ");
    scanf("%s", name);

    printf("Enter trainer salary: ");
    scanf("%d", &salary);

    insertTrainer(SystemManager, name, salary);

    printf("Trainer inserted successfully.\n");

    DisplayTrainers(SystemManager);
}

void interfaceInsertClient(SystemManager* SystemManager)
{
    char name[MAX_LENGTH_NAME];
    char badge[MAX_LENGTH_NAME];

    printf("Enter client name: ");
    scanf("%s", name);

    printf("Enter client badge: ");
    scanf("%s", badge);

    insertClient(SystemManager, name, badge);

    printf("Client inserted successfully.\n");

    DisplayClients(SystemManager);
}

// Sorted displays
void interfaceDisplayTrainersSalaryAsc(SystemManager* SystemManager)
{
    AscendingSortTrainerBySalary(SystemManager);
}
void interfaceDisplayTrainersSalaryDesc(SystemManager* SystemManager)
{
    DescendingSortTrainerBySalary(SystemManager);
}

void interfaceDisplayTrainers(SystemManager* SystemManager)
{
    DisplayTrainers(SystemManager);
}
void interfaceDisplayClients(SystemManager* SystemManager)
{
    DisplayClients(SystemManager);
}

// Search by keywords
void interfaceListTrainersByKeyword(SystemManager* SystemManager)
{
    char keyWord[MAX_NAME_LENGTH];

    printf("Enter keyword: ");
    scanf("%s", keyWord);

    fetchTrainerIDsbyName(SystemManager, keyWord);
}

void interfaceListClientsByKeyword(SystemManager* SystemManager)
{
    char keyWord[MAX_NAME_LENGTH];

    printf("Enter keyword: ");
    scanf("%s", keyWord);

    fetchClientIDsbyName(SystemManager, keyWord);
}

// Search by ID
void interfaceFindTrainerByID(SystemManager* SystemManager)
{
    int TrainerID;
    Trainer trainer;

    printf("Enter Trainer ID: ");
    scanf("%d", &TrainerID);

    trainer = getTrainerbyID(SystemManager, TrainerID);

    printf("The trainer with the ID: %d\n\tname: %s\n\tSalary: %d \n",
        trainer.ID, trainer.name, trainer.salary);

}
// a system built on hopes and dreams :pray: :wilted_rose:
void interfaceFindClientByID(SystemManager* SystemManager)
{
    int ClientID;
    Client client;

    printf("Enter Client ID: ");
    scanf("%d", &ClientID);

    client = getClientbyID(SystemManager, ClientID);

    printf("The client with the ID: %d\n\tname: %s\n\tBadge: %s \n",
           client.ID, client.name, client.subscriptionBadge);
}
