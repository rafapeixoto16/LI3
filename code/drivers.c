//
// Created by rafael on 04-11-2022.
//

#include "drivers.h"

struct driver {
    char *id;
    char *name;
    char *birth_day;
    char *gender;
    char *car_class;
    char *license_plate;
    char *city;
    char *account_creation;
    char *account_status;
};

unsigned int hashDrivers(char *id){
    return ((atoi(id)-1));
}


DRIVERS *hashTableDrivers[hashMaxDrivers];

void initHashTableDrivers(){
    for (int i = 0; i < hashMaxDrivers; i++) {
        hashTableDrivers[i]=NULL;
    }
}

void printTableDrivers(){
    for (int i = 0; i < hashMaxDrivers; i++){
        if (hashTableDrivers[i]!=NULL)
            printf("siu");
        else
            printf(";(");
    }
}

bool hashTableInsertDrivers(DRIVERS *driver){
    if(driver==NULL) return false;
    int index = hashDrivers((*driver)->id);
    if(hashTableDrivers[index]!=NULL){
        return false;
    }
    hashTableDrivers[index]=driver;
}

DRIVERS *hashTableLookupDrivers(char *id){
    int index = hashDrivers(id);
    if(hashTableDrivers[index]!=NULL && strcmp((*hashTableDrivers[index])->id,id)==0)
        return hashTableDrivers[index];
    else
        return NULL;

}