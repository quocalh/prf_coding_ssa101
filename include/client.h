#ifndef CLIENT_H
#define CLIENT_H

#define MAX_NAME_LENGTH 150


enum SUBSCRIPTIONBADGE
{
    GOLD,
    PLATINUM,
    DIAMOND,
};

typedef  struct{
    enum SUBSCRIPTIONBADGE SubscriptionBadge;
    short int expiredDay;
    short int expiredMonth;
    int expiredYear;
}SubscriptionBadge;

typedef struct{
    int ID;
    char name[MAX_NAME_LENGTH];
    SubscriptionBadge subscriptionBadge;
} Client;


SubscriptionBadge getSubscriptionBadge(enum SUBSCRIPTIONBADGE subscription_badge);
void setSubScriptionBadge(int ClientID, enum SUBSCRIPTIONBADGE SubscriptionBadge);
void isClientIsSubscriptionExpired(int CLientID);

void TheNumber();

#endif