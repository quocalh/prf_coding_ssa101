
#include "../include/sys.h"
#include "../include/client.h"
#include "../include/trainer.h"

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define READ_FAILED_STRING "Failed to read the file\n"
#define READ_SUCCESSED_STRING "Successfull read the file\n"

Client getClientbyID(SystemManager *SystemManager, int ClientID){
  	return SystemManager -> clients[ClientID];
}

Trainer getTrainerbyID(SystemManager *SystemManager, int TrainerID){
  	return SystemManager -> trainers[TrainerID];
}

int min(int a, int b)
{
  	return (a < b) ? a : b;
}

enum SUBSCRIPTIONBADGE SubscriptionBadgeStringEnumConvert(const char *Badge)
{	
	// could have implemented a hashmap righthere
	if (strcmp(Badge, "GOLD"))
	{
		return GOLD;
	}
	else if (strcmp(Badge, "PLATINUM"))
	{
		return PLATINUM;
	}
	else if (strcmp(Badge, "DIAMOND"))
	{
		return DIAMOND;
	}
	else
	{
		return FREE;
	}
	

}

  // IMPORT TXT FILE
void importTrainerData(SystemManager *SystemManager, const char *fileName)
{

}
void importClientData(SystemManager *SystemManager, const char *fileName)
{
    FILE *filepnt = fopen(fileName, "r");
	if (filepnt == NULL)
	{
		printf(READ_FAILED_STRING);
		fclose(filepnt);
		return;
	}
	char name[MAX_LENGTH_NAME];
	char badge[MAX_LENGTH_NAME];
	int i = 0; // ID generator
	while(fscanf(filepnt, "%s %s", &name, &badge) == 2)
	{	
		strcpy(SystemManager->clients[i].name, name);
		printf("badge: %s\n", badge);
		SystemManager->clients[i].subscriptionBadge = SubscriptionBadgeStringEnumConvert(badge);
		SystemManager->clients[i].ID = SystemManager->ClientCount;

		SystemManager->ClientCount ++;
		i++;
	}


	printf(READ_SUCCESSED_STRING);
	fclose(filepnt);
}	



    // STRING COMPARISON FOR FETCHING FUNTIONS | can not make use of spare set or linked list unfortunatelly
bool stringCompare(const char *name1, const char *name2)
{ 
  	int name1Length = (int)strlen(name1); 
  	int name2Length = (int)strlen(name2);

  	int CompLength = min(EVALUATE_RANK, name1Length);
  	CompLength = min(CompLength, name2Length);

  	char lowerCase1;
  	char lowerCase2;
  	for (int i = 0; i < CompLength; i++)
  	{
  	  	lowerCase1 = tolower(name1[i]);
  	  	lowerCase2 = tolower(name2[i]);
  	  	if (lowerCase1 != lowerCase2)
  	  	{
  	  	  	return false;;
  	  	} 
  	}
  return true;
}
  // FETCHING FUNCTIONS
void fetchClientIDsbyName(SystemManager *SystemManager, const char *Name)
{  
  	int queryLength = min(SystemManager->ClientCount, QUERY_MAX);
  	int IDquery[queryLength];

  	int i = 0;
  	int queryCount = 0;

  	while((queryCount < queryLength) || (i < SystemManager->ClientCount))
  	{
	
  	  	Client client = SystemManager->clients[i];
  	  	// client.name;

  	  	if (stringCompare(Name, client.name))
  	  	{
				// testing phrases
			// printf("the client's name: %s\n", client.name);
  	  	  	IDquery[queryCount] = client.ID;
  	  	  	queryCount++;
  	  	}
  	  	i++;
  	}
	printf("the query count: %d\n", queryCount);

  	int ID;
  	for (i = 0; i < queryCount; i++)
  	{
  	  	ID = IDquery[i]; 
		Client client = SystemManager->clients[ID];
  	  	printf("Name = %s -> ID = %d\n", client.name, client.ID);
  	}


}

void fetchTrainerIDsbyName(SystemManager *SystemManager, const char *Name)
{  
  	int queryLength = min(SystemManager->TrainerCount, QUERY_MAX);
  	int IDquery[queryLength];

  	int i = 0;
  	int queryCount = 0;

  	while((queryCount < queryLength) || (i < SystemManager->TrainerCount))
  	{
	
  	  	Trainer trainer = SystemManager->trainers[i];
  	  	// trainer.name;

  	  	if (stringCompare(Name, trainer.name))
  	  	{
  	  	  IDquery[queryCount] = trainer.ID;
  	  	  queryCount++;
  	  	}
  	  	i++;
  	}
  	int ID;
  	for (i  = 0; i < queryCount; i++)
  	{
  	  	ID = IDquery[i]; 
  	  	printf("Name = %s -> ID = %d", ID, SystemManager->trainers[ID]);
  	}


}

