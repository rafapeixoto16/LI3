#ifndef RIDES_H;
#define RIDES_H;

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define hashMaxRides 1000000

typedef struct ride *RIDES;

unsigned int hashDrives(char *id);
void initHashTableDrives();


#endif