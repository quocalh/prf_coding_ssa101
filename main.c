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

    importClientData(&systemManager, "io/Clients.txt");
    for (int i; i < systemManager.ClientCount; i++)
    {
        Client client = systemManager.clients[i];
        printf("name: %s, ID: %d, badge: %s\n", client.name, client.ID, BadgeInString[client.subscriptionBadge]);
    }
}
