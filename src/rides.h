#ifndef RIDES_H
#define RIDES_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define hashMaxRides 1000000

#define dataDia "9/10/2022"

typedef struct ride *RIDES;

unsigned int hashRides(char *id);
void initHashTableRides();
void printTableRides();
void ridesParsing(char *linha);
RIDES hashTableLookupRides(char *id);
char *lookupRides(char *i);
char *lookupDriverRides(int i);
int lookupDistanceRides(int i);
bool lookupCidadeRides(int i ,char *cidade);
bool hashTableInsertRides(RIDES ride);


#endif