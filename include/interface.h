#ifndef INTERFACE_H
#define INTERFACE_H

#include "../include/sys.h"

void mainInterface(SystemManager* SystemManager);

void mainInterface(SystemManager* SystemManager);

// Import data
void interfaceImportClientData(SystemManager* SystemManager);
void interfaceImportTrainerData(SystemManager* SystemManager);

// Set badges
void interfaceSetClientBadge(SystemManager* SystemManager);
void interfaceSetTrainerSalary(SystemManager* SystemManager);

// Insert records
void interfaceInsertTrainer(SystemManager* SystemManager);
void interfaceInsertClient(SystemManager* SystemManager);

// Sorted displays
void interfaceDisplayTrainersSalaryAsc(SystemManager* SystemManager);
void interfaceDisplayTrainersSalaryDesc(SystemManager* SystemManager);

void interfaceDisplayTrainers(SystemManager* SystemManager);
void interfaceDisplayClients(SystemManager* SystemManager);

// Search by keywords
void interfaceListTrainersByKeyword(SystemManager* SystemManager);
void interfaceListClientsByKeyword(SystemManager* SystemManager);

// Search by ID
void interfaceFindTrainerByID(SystemManager* SystemManager);
void interfaceFindClientByID(SystemManager* SystemManager);


#endif
