
#include "../include/sys.h"
#include "../include/client.h"
#include "../include/trainer.h"

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define READ_FAILED_STRING "Failed to read the file\n"
#define READ_SUCCESSED_STRING "Successfully read the file\n"
#define WRITE_FAILED_STRING "Failed to write the file\n"
#define WRITE_SUCCESSED_STRING "Successfully write the file\n"

int min(int a, int b)
{
  	return (a < b) ? a : b;
}

int max(int a, int b)
{
	return (a > b)? a :  b;
}

void swap(int* a, int* b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

void DescendingSortTrainerBySalary(SystemManager *SystemManager)
{	
	int indexArray[SystemManager->TrainerCount];
	for (int i = 0; i < SystemManager->TrainerCount; i++)
	{
		indexArray[i] = i;
	}
		// bijection projection 
	for (int i = 0; i < SystemManager->TrainerCount; i++)
	{	
		for (int j = i + 1; j < SystemManager->TrainerCount; j++)
		{
			Trainer *trainer_a = &SystemManager->trainers[ indexArray[i] ];
			Trainer *trainer_b = &SystemManager->trainers[ indexArray[j] ];
			if (trainer_a->salary < trainer_b->salary)
			{
				swap(&indexArray[i], &indexArray[j]);
			}
		}
	}

		// display the result
	for (int i = 0; i < SystemManager->TrainerCount; i++)
	{
		Trainer *trainer = &SystemManager->trainers[ indexArray[i] ];

		printf("%d| \n\tID -> %d\n\tName -> %s\n\tSalary -> %d\n", 
			i + 1, 
			trainer->ID,
			trainer->name,
			trainer->salary
		);
	}

}
void AscendingSortTrainerBySalary(SystemManager *SystemManager)
{
	int indexArray[SystemManager->TrainerCount];
	for (int i = 0; i < SystemManager->TrainerCount; i++)
	{
		indexArray[i] = i;
	}
		// bijection projection 
	for (int i = 0; i < SystemManager->TrainerCount; i++)
	{	

		for (int j = i + 1; j < SystemManager->TrainerCount; j++)
		{
			Trainer *trainer_b = &SystemManager->trainers[ indexArray[j] ];
			Trainer *trainer_a = &SystemManager->trainers[ indexArray[i] ];
			if (trainer_a->salary > trainer_b->salary)
			{
				swap(&indexArray[i], &indexArray[j]);
			}
		}
	}
	
		// display the result
	for (int i = 0; i < SystemManager->TrainerCount; i++)
	{
		Trainer *trainer = &SystemManager->trainers[ indexArray[i] ];

		printf("%d| \n\tID -> %d\n\tName -> %s\n\tSalary -> %d\n", 
			i + 1, 
			trainer->ID,
			trainer->name,
			trainer->salary
		);
	}
}




    // DISPLAY OBJECSTS
void DisplayClients(SystemManager* SystemManager)
{
	// SystemManager->clients[0].ID;
	// SystemManager->clients[0].name;
	// SystemManager->clients[0].subscriptionBadge;
	for (int i = 0; i < SystemManager->ClientCount; i++)
	{	
		Client* client = &(SystemManager->clients[i]);
		client->ID;
		client->name;
		client->subscriptionBadge;
		printf("%d|\n\tID -> %d \n\tName -> %s \n\tBadge -> %s\n", 
			i + 1,
			client->ID, 
			client->name, 
			client->subscriptionBadge
		);
	}
}
void DisplayTrainers(SystemManager *SystemManager)
{
	for (int i = 0; i < SystemManager->TrainerCount; i++)
	{
		Trainer* trainer = &(SystemManager->trainers[i]);
		trainer->ID;
		trainer->name;
		trainer->salary;
		printf("%d|\n\tID -> %d \n\tName -> %s \n\tSalary -> %d\n", 
			i + 1,
			trainer->ID, 
			trainer->name, 
			trainer->salary
		);

	}
}


Client getClientbyID(SystemManager *SystemManager, int ClientID){
  	return SystemManager -> clients[ClientID];
}

Trainer getTrainerbyID(SystemManager *SystemManager, int TrainerID){
  	return SystemManager -> trainers[TrainerID];
}

void insertClient(SystemManager *SystemManager, const char *Name, const char* Badge)
{
	Client* client = &SystemManager->clients[SystemManager->ClientCount];

	client->ID = SystemManager->ClientCount;
	strcpy(client->name, Name);
	strcpy(client->subscriptionBadge, Badge);

	SystemManager->ClientCount ++;
}
void insertTrainer(SystemManager *SystemManager, const char *Name, int salary)
{
	Trainer* trainer = &SystemManager->trainers[SystemManager->TrainerCount];

	trainer->ID = SystemManager->TrainerCount;
	strcpy(trainer->name, Name);
	trainer->salary = salary;

	SystemManager->TrainerCount ++;
}


enum SUBSCRIPTIONBADGE SubscriptionBadgeStringEnumConvert(const char *Badge)
{	
	// could have implemented a hashmap righthere
	if (strcmp(Badge, "GOLD") == 0)
	{
		return GOLD;
	}
	else if (strcmp(Badge, "PLATINUM") == 0)
	{
		return PLATINUM;
	}
	else if (strcmp(Badge, "DIAMOND") == 0)
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
	FILE *filepnt = fopen(fileName, "r");
	if (filepnt == NULL)
	{
		printf(READ_FAILED_STRING);
		fclose(filepnt);
		return;
	}
	char name[MAX_LENGTH_NAME];
	int salary;
	
	int i = 0;
	while (fscanf(filepnt, "%s %d", name, &salary) == 2)
	{	
		Trainer *trainer = &(SystemManager->trainers[i]);
		
		strcpy(trainer->name, name);
		trainer->salary = salary;
		trainer->ID = i;

		i++;
	}
	SystemManager->TrainerCount = i;

	printf(READ_SUCCESSED_STRING);
	fclose(filepnt);

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
	while(fscanf(filepnt, "%s %s", name, badge) == 2)
	{	
		strcpy(SystemManager->clients[i].name, name);
		strcpy(SystemManager->clients[i].subscriptionBadge, badge);
		SystemManager->clients[i].ID = i;

		i++;
	}
	SystemManager->ClientCount = i;


	printf(READ_SUCCESSED_STRING);
	fclose(filepnt);
}	

    // EXPORT TXT FILE  
void exportTrainerData(SystemManager *SystemManager, const char *fileName)
{	
	FILE *file_pnt = fopen(fileName, "w");
	if (file_pnt == NULL)
	{
		printf(WRITE_FAILED_STRING);
	}
	int isFirstLine = true;
	for (int i = 0; i < SystemManager->TrainerCount; i ++)
	{	
		Trainer *trainer = &SystemManager->trainers[i];
		if (!isFirstLine)
		{
			fprintf(file_pnt, "\n");
		}
		else
		{
			isFirstLine = false;
		}

		fprintf(file_pnt, "%s %d", trainer->name, trainer->salary);
	}
	printf(WRITE_SUCCESSED_STRING);
	fclose(file_pnt);
}
void exportClientData(SystemManager *SystemManager, const char *fileName)
{
	FILE *file_pnt = fopen(fileName, "w");
	if (file_pnt == NULL)
	{
		printf(WRITE_FAILED_STRING);
	}
	int isFirstLine = true;
	for (int i = 0; i < SystemManager->ClientCount; i ++)
	{	
		Client *client = &SystemManager->clients[i];
		if (!isFirstLine)
		{
			fprintf(file_pnt, "\n");
		}
		else
		{
			isFirstLine = false;
		}

		fprintf(file_pnt, "%s %s", client->name, client->subscriptionBadge);
	}
	printf(WRITE_SUCCESSED_STRING);
	fclose(file_pnt);
}


    // SET FUNCTION
void setTrainerSalary(SystemManager *SystemManager, int TrainerID, int newIncome)
{
	(&SystemManager->trainers[TrainerID])->salary = newIncome;
}

void setClientSubscriptionBadge(SystemManager *SystemManager, int ClientID, char* subscriptionBadge)
{
	strcpy(SystemManager->clients[ClientID].subscriptionBadge, subscriptionBadge);
}


    // STRING COMPARISON FOR FETCHING FUNTIONS | can not make use of spare set or linked list unfortunatelly
bool stringCompare(const char *name1, const char *name2)
{ 
  	int name1Length = (int)strlen(name1); 
  	int name2Length = (int)strlen(name2);

  	// int CompLength = min(EVALUATE_RANK, name1Length);
  	int CompLength = name1Length;
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

  	while((queryCount < queryLength) && (i < SystemManager->ClientCount))
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

  	while((queryCount < queryLength) && (i < SystemManager->TrainerCount))
  	{
	
  	  	Trainer *trainer = &SystemManager->trainers[i];
  	  	// trainer.name;

  	  	if (stringCompare(Name, trainer->name))
  	  	{
  	  	  IDquery[queryCount] = trainer->ID;
  	  	  queryCount++;
  	  	}
  	  	i++;
  	}
	printf("the query count: %d\n", queryCount);

  	int ID;
  	for (i = 0; i < queryCount; i++)
  	{
  	  	ID = IDquery[i]; 
		Trainer *trainer = &SystemManager->trainers[ID];
  	  	printf("Name = %s -> ID = %d\n", trainer->name, trainer->ID);
  	}


}

