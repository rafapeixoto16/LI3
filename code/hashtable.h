//
// Created by rafael on 04-11-2022.
//


#ifndef LI3_HASHTABLE_H
#define LI3_HASHTABLE_H

#include "rides.h"
#include "users.h"
#include "drivers.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define hashMaxDrivers 10000

unsigned int hashRides(char *id);
unsigned int hashDrivers(char *id);
void initHashTableDrivers();
void printTableDrivers();
bool hashTableInsertDrivers(DRIVERS *driver);

#endif //LI3_HASHTABLE_H
