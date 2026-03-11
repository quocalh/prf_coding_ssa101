#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

/* ==============================
   SETTINGS
================================ */

#define MAX_NAME_LENGTH 150
#define MAX_LENGTH_NAME 200
#define MAX_CLIENT 100
#define MAX_TRAINER 10
#define MAX_STRING_LENGTH 50


/* ==============================
   ENUMS
================================ */

enum SUBSCRIPTIONBADGE
{
    GOLD,
    PLATINUM,
    DIAMOND,
};


/* ==============================
   STRUCTS
================================ */

typedef struct{
    enum SUBSCRIPTIONBADGE SubscriptionBadge;
    short int expiredDay;
    short int expiredMonth;
    int expiredYear;
} SubscriptionBadge;


typedef struct{
    int ID;
    char name[MAX_NAME_LENGTH];
    int salary;
} Trainer;


typedef struct{
    int ID;
    char name[MAX_NAME_LENGTH];
    SubscriptionBadge subscriptionBadge;
} Client;


typedef struct
{
    Client clients[MAX_CLIENT];
    Trainer trainers[MAX_TRAINER];

    char fileNameTrainer[MAX_STRING_LENGTH];
    char fileNameClient[MAX_STRING_LENGTH];

    int ID_generator;

} SystemManager;


typedef struct {
    int month;
    int date;
    int year;

    int sec;
    int min;
    int hour;

} CurrentTime;


/* ==============================
   FUNCTION PROTOTYPES
================================ */

/* HELLO */
void SayHello();
void SayGoodbye();

/* INTERFACE */
void mainInterface();
void mainLoop();
void objectModifyingLoop();

/* CLIENT */
SubscriptionBadge getSubscriptionBadge(enum SUBSCRIPTIONBADGE subscription_badge);
void setSubScriptionBadge(int ClientID, enum SUBSCRIPTIONBADGE SubscriptionBadge);
void isClientIsSubscriptionExpired(int ClientID);
void TheNumber();

/* SYSTEM MANAGER */

// FETCHING OBJECTS
Client getClientbyID(SystemManager *SystemManager, int ClientID);
Trainer getTrainerbyID(SystemManager *SystemManager, int TrainerID);

// INSERT OBJECTS
void insertClient(SystemManager *SystemManager, char Name[]);
void insertTrainer(SystemManager *SystemManager, char Name[]);

// IMPORT TXT FILE
void importTrainerData(SystemManager *SystemManager, const char fileName[]);
void importClientData(SystemManager *SystemManager, const char fileName[]);

// EXPORT TXT FILE
void exportTrainerData(SystemManager *SystemManager, const char fileName[]);
void exportClientData(SystemManager *SystemManager, const char fileName[]);

// SET FUNCTION
void setTrainerSalary(SystemManager *SystemManager, int newIncome);
void setClientSubscriptionBadge(SystemManager *SystemManager, SubscriptionBadge SubscriptionBadge);

// SEARCH FUNCTIONS
void fetchClientIDsbyName(SystemManager *SystemManager, const char Name[]);
void fetchTrainerIDsbyName(SystemManager *SystemManager, const char Name[]);

// REPORT FUNCTIONS
void fetchExpiredSubscriptionClients(SystemManager *SystemManager);
void fetchPayingTrainers(SystemManager *SystemManager);

/* TIME */
void FetchTime(CurrentTime *Time);


/* ==============================
   HELLO IMPLEMENTATION
================================ */

void SayHello()
{
    printf("Hello world\n");
}

void SayGoodbye()
{
    printf("Goodbye world\n");
}


/* ==============================
   CLIENT IMPLEMENTATION
================================ */

SubscriptionBadge getSubscriptionBadge(enum SUBSCRIPTIONBADGE subscription_badge)
{
    SubscriptionBadge badge;
    badge.SubscriptionBadge = subscription_badge;
    return badge;
}

void setSubScriptionBadge(int ClientID, enum SUBSCRIPTIONBADGE SubscriptionBadge)
{
    /* TODO */
}

void isClientIsSubscriptionExpired(int ClientID)
{
    /* TODO */
}

void TheNumber()
{
    printf("the number is: %d\n", MAX_NAME_LENGTH);
}


/* ==============================
   SYSTEM MANAGER IMPLEMENTATION
================================ */

Client getClientbyID(SystemManager *SystemManager, int ClientID)
{
    return SystemManager->clients[ClientID];
}

Trainer getTrainerbyID(SystemManager *SystemManager, int TrainerID)
{
    return SystemManager->trainers[TrainerID];
}

void insertClient(SystemManager *SystemManager, char Name[])
{
    /* TODO */
}

void insertTrainer(SystemManager *SystemManager, char Name[])
{
    /* TODO */
}

void importTrainerData(SystemManager *SystemManager, const char fileName[])
{
    /* TODO */
}

void importClientData(SystemManager *SystemManager, const char fileName[])
{
    /* TODO */
}

void exportTrainerData(SystemManager *SystemManager, const char fileName[])
{
    /* TODO */
}

void exportClientData(SystemManager *SystemManager, const char fileName[])
{
    /* TODO */
}

void setTrainerSalary(SystemManager *SystemManager, int newIncome)
{
    /* TODO */
}

void setClientSubscriptionBadge(SystemManager *SystemManager, SubscriptionBadge SubscriptionBadge)
{
    /* TODO */
}

void fetchClientIDsbyName(SystemManager *SystemManager, const char Name[])
{
    /* TODO */
}

void fetchTrainerIDsbyName(SystemManager *SystemManager, const char Name[])
{
    /* TODO */
}

void fetchExpiredSubscriptionClients(SystemManager *SystemManager)
{
    /* TODO */
}

void fetchPayingTrainers(SystemManager *SystemManager)
{
    /* TODO */
}


/* ==============================
   TIME IMPLEMENTATION
================================ */

void FetchTime(CurrentTime* Time)
{
    time_t rawTime;
    time(&rawTime);

    struct tm* localTime = localtime(&rawTime);

    Time->year = localTime->tm_year + 1900;
    Time->month = localTime->tm_mon + 1;
    Time->date = localTime->tm_mday;

    Time->sec = localTime->tm_sec;
    Time->min = localTime->tm_min;
    Time->hour = localTime->tm_hour;
}


/* ==============================
   INTERFACE IMPLEMENTATION
================================ */

void mainInterface()
{
    printf("Interface starting...\n");
}

void mainLoop()
{
    /* TODO */
}

void objectModifyingLoop()
{
    /* TODO */
}


/* ==============================
   MAIN
================================ */

int main()
{
    printf("testing header file\n");

    SayGoodbye();
    SayHello();

    SystemManager systemManager;

    Client first_client;

    systemManager.clients[0] = first_client;

    strcpy(first_client.name, "Example Name");

    printf("the first client's name is: %s\n", first_client.name);

    first_client.ID = 5;

    strcpy(first_client.name, "my name is Kira\n");

    printf("Client ID is %d\n", first_client.ID);
    printf("Client name is: %s\n", first_client.name);

    TheNumber();

    CurrentTime currentTime;

    printf("today is a good day\n");

    FetchTime(&currentTime);

    printf("today is %d/%d/%d\n",
           currentTime.date,
           currentTime.month,
           currentTime.year);

    mainInterface();

    return 0;
}