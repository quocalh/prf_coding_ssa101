
#include "../include/sys.h"
#include "../include/client.h"
#include "../include/trainer.h"

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

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


// can not make use of spare set or linked list unfortunatelly
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

void fetchClientIDsbyName(SystemManager *SystemManager, const char Name)
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
      IDquery[queryCount] = client.ID;
      queryCount++;
    }
    i++;
  }
  int ID;
  for (i  = 0; i < queryCount; i++)
  {
    ID = IDquery[i]; 
    printf("Name = %s -> ID = %d", ID, SystemManager->clients[ID]);
  }


}

