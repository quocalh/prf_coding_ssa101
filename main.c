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

    SystemManager systemManger;
    Client first_client;
    systemManger.clients[0] = first_client;
    strcpy(first_client.name, "Niggaton");

    printf("the first client's name is: %s\n", first_client.name);



    first_client.ID = 5;
    first_client.name;

    strcpy(first_client.name, "my name is Kira\n");

    printf("Client ID is %d\n", first_client.ID);
    printf("Client name is: %s\n", first_client.name);

    TheNumber();

    CurrentTime currentTime;

    printf("today is a good day\n");

    FetchTime(&currentTime);
    printf("today is %d/%d/%d\n", currentTime.date, currentTime.month ,currentTime.year);
    
    printf("nigger");
    printf("nigger36");
    mainInterface();
}
