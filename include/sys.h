#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H

#include <stdbool.h>

#include "setting.h"
#include "client.h"
#include "trainer.h"

#define MAX_STRING_LENGTH 50
#define QUERY_MAX 5
#define EVALUATE_RANK 2

//  SINGLETON
typedef struct
{
    Client clients[MAX_CLIENT];
    Trainer trainers[MAX_TRAINER];
    int ClientCount;
    int TrainerCount;

    char fileNameTrainer[MAX_STRING_LENGTH];
    char fileNameClient[MAX_STRING_LENGTH];

    // int ID_generator;
} SystemManager;

// FUNCTIONS
    // FETCHING OBJECTS
Client getClientbyID(SystemManager *SystemManager, int ClientID); // done
Trainer getTrainerbyID(SystemManager *SystemManager, int TrainerID); // done

    // INSERT OBJECTS
void insertClient(SystemManager *SystemManager, char Name);
void insertTrainer(SystemManager *SystemManager, char Name);

    // IMPORT TXT FILE
void importTrainerData(SystemManager *SystemManager, const char fileName);
void importClientData(SystemManager *SystemManager, const char fileName);

    // EXPORT TXT FILE  
void exportTrainerData(SystemManager *SystemManager, const char fileName);
void exportClientData(SystemManager *SystemManager, const char fileName);

    // SET FUNCTION
void setTrainerSalary(SystemManager *SystemManager, int newIncome);
void setClientSubscriptionBadge(SystemManager *SystemManager, SubscriptionBadge SubscriptionBadge);

    // GET ID BY NAME - LIST NAME LIST WITH ID WITH THAT NAME (CASE INSENSITIVE)
void fetchClientIDsbyName(SystemManager *SystemManager, const char Name);
void fetchTrainerIDsbyName(SystemManager *SystemManager, const char Name);

    // GET EXPIRED LIST CLIENT
void fetchExpiredSubscriptionClients(SystemManager *SystemManager);

    // GET PAYING LIST TRAINER
void fetchPayingTrainers(SystemManager *SystemManager);


#endif