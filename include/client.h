#ifndef CLIENT_H
#define CLIENT_H

#define MAX_NAME_LENGTH 150


enum SUBSCRIPTIONBADGE
{
    FREE, 
    GOLD,
    PLATINUM,
    DIAMOND,
};

extern const char *BadgeInString[];

typedef struct{
    int ID;
    char name[MAX_NAME_LENGTH];
    char subscriptionBadge[MAX_NAME_LENGTH];
} Client;

#endif