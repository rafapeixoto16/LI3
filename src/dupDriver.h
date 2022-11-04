//
// Created by diogo on 04-11-2022.
//

#ifndef LI3_DUPDRIVER_H
#define LI3_DUPDRIVER_H
#include "drivers.h"
typedef struct dupDriver *DupDrivers;

DupDrivers novoDupDrivers();
void addDriver(DRIVERS driver,DupDrivers dup);
#endif //LI3_DUPDRIVER_H

