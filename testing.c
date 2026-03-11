#include <stdio.h>
#include <string.h>
#include <ctype.h>

int getStringLength(const char *string)
{
    return (int)strlen(string);
}

int main()
{
    const char hello[200] = "NIGGER";
    int helloLength = (int)strlen(hello);
    printf("length: %d\n", helloLength);
    printf("length: %d\n", getStringLength(hello));

    printf("the first letter:%c\n", tolower(hello[0]));
    printf("true or false: %d", ("n" == "n") ? 1: 0);
}