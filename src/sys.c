
#include "../include/sys.h"
#include "../include/client.h"
#include "../include/trainer.h"

#include <stdio.h>

Client getClientbyID(SystemManager *SystemManager, int ClientID){
  return SystemManager -> clients[ClientID];
}

Trainer getTrainerbyID(SystemManager *SystemManager, int TrainerID){
  return SystemManager -> trainers[TrainerID];
}
