#ifndef CLIENT_H
#define CLIENT_H

#define MAX_NAME_LENGTH 150


enum SUBSCRIPTIONBADGE
{
    GOLD,
    PLATINUM,
    DIAMOND,
};


typedef struct{
    int ID;
    char name[MAX_NAME_LENGTH];
    enum SUBSCRIPTIONBADGE subscriptionBadge;
} Client;



#endif