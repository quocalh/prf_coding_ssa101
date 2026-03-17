#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/hello.h"
#include "include/client.h"
#include "include/interface.h"
#include "include/time.h"
#include "include/sys.h"


int main()
{
    printf("tesing header file\n");
    SayGoodbye();
    SayHello();

    SystemManager systemManager;
    Client first_client;
    systemManager.clients[0] = first_client;
    strcpy(first_client.name, "Niggaton");

    printf("the first client's name is: %s\n", first_client.name);



    first_client.ID = 5;
    first_client.name;

    strcpy(first_client.name, "my name is Kira\n");

    printf("Client ID is %d\n", first_client.ID);
    printf("Client name is: %s\n", first_client.name);

    CurrentTime currentTime;

    printf("today is a good day\n");

    FetchTime(&currentTime);
    printf("today is %d/%d/%d\n", currentTime.date, currentTime.month ,currentTime.year);
    
    // mainInterface();




        // testing  import func (successful)
    importClientData(&systemManager, "io/Clients.txt");
    importTrainerData(&systemManager, "io/Trainers.txt");
    // for (int i = 0; i < systemManager.ClientCount; i++)
    // {
    //     Client client = systemManager.clients[i];
    //     printf("name: %s, ID: %d, badge: %s\n", client.name, client.ID, BadgeInString[client.subscriptionBadge]);
    // }
    // for (int i = 0; i < systemManager.TrainerCount; i++)
    // {
    //     Trainer trainer = systemManager.trainers[i];
    //     printf("name: %s, ID: %d, badge: %d\n", trainer.name, trainer.ID, trainer.salary);
    // }


    // Trainer new_trainer;
    // systemManager.trainers[systemManager.TrainerCount] = new_trainer;
    // Trainer *trainer_pnt = &systemManager.trainers[systemManager.TrainerCount];
    
        // testing insert
    // trainer_pnt->ID = systemManager.TrainerCount;
    // strcpy(trainer_pnt->name, "hello_world");
    // trainer_pnt->salary = 1230;
    // systemManager.TrainerCount ++;



        // testing export -- success
    exportClientData(&systemManager, "io/Clients.txt");
    exportTrainerData(&systemManager, "io/Trainers.txt");

        // print client trainer -- success
    // DisplayClients(&systemManager);
    // DisplayTrainers(&systemManager);

        // testing fetch funcs(successfull) 
    // fetchClientIDsbyName(&systemManager, "N");
    // fetchTrainerIDsbyName(&systemManager, "N");

        // sorted display -- success
    // DescendingSortTrainerBySalary(&systemManager);
    // AscendingSortTrainerBySalary(&systemManager);


        // insert -- success
    // insertClient(&systemManager, "nailtrimmer3000", "DIAMOND");
    // insertClient(&systemManager, "nailtrimmer3000", "DIAMOND");
    // insertClient(&systemManager, "nailtrimmer3000", "DIAMOND");
    // DisplayClients(&systemManager);

    // insertTrainer(&systemManager, "nailtrimmer3000", 1201);
    // insertTrainer(&systemManager, "nailtrimmer3000", 1202);
    // insertTrainer(&systemManager, "nailtrimmer3000", 1203);
    // DisplayTrainers(&systemManager);
    // DescendingSortTrainerBySalary(&systemManager);
}
