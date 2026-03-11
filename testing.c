#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TESTING_KEY 100

int getStringLength(const char *string)
{
    return (int)strlen(string);
}

void ReadFile(const char *Name)
{
    FILE *file_pnt;
    file_pnt = fopen(Name, "r");
    if (file_pnt == NULL)
    {
        printf("get jumped on bro\n");
    }
    else
    {
        printf("Successfully read the file\n");
    }
    
    char clientName[TESTING_KEY];
    char clientBadge[TESTING_KEY];

    // fscanf(file_pnt, "{%s | %s}", &clientName, &clientBadge);
    while (fscanf(file_pnt, "%s %s", &clientName, &clientBadge) == 2)
    // while (fscanf(file_pnt, "{%s | %s}", &clientName, &clientBadge) == 2)
    {
        printf("the client's name: %s\n", clientName);
        printf("the client's badge: %s\n", clientBadge);
    }
    fclose(file_pnt);
}


int main()
{
    const char hello[200] = "NIGGER";
    int helloLength = (int)strlen(hello);
    printf("length: %d\n", helloLength);
    printf("length: %d\n", getStringLength(hello));

    printf("the first letter:%c\n", tolower(hello[0]));
    printf("true or false: %d\n", ("n" == "n") ? 1: 0);
    
    ReadFile("io/Clients.txt");
}