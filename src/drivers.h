//
// Created by rafael on 04-11-2022.
//

#ifndef LI3_DRIVERS_H
#define LI3_DRIVERS_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define hashMaxDrivers 10000

typedef struct driver *DRIVERS;

int hashDrivers(char *id);
void initHashTableDrivers();
void printTableDrivers();
void driversParsing(char *linha);
DRIVERS hashTableLookupDrivers(char *id);
char *lookupDrivers(char *i);
bool hashTableInsertDrivers(DRIVERS driver);

#endif //LI3_DRIVERS_H
