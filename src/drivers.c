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

int hashDrivers(char *id){
    return ((atoi(id)-1));
}


DRIVERS hashTableDrivers[hashMaxDrivers];

void initHashTableDrivers(){
    for (int i = 0; i < hashMaxDrivers; i++) {
        hashTableDrivers[i]=NULL;
    }
}

void printTableDrivers() {

    for (int i = 0; i < hashMaxDrivers; i++) {
        if (hashTableDrivers[i] != NULL) {
            printf("\t%s\n", ((hashTableDrivers[i])->id));
        } else
            printf("errou\n");
    }
}
bool hashTableInsertDrivers(DRIVERS driver){
    if(driver==NULL) return false;
    int index = hashDrivers(((driver)->id));
    if(hashTableDrivers[index]!=NULL){
        return false;
    }
    hashTableDrivers[index]=driver;
    return true;
}

DRIVERS hashTableLookupDrivers(char *id){
    int index = hashDrivers(id);
    if(hashTableDrivers[index]!=NULL && strcmp((hashTableDrivers[index])->id,id)==0)
        return hashTableDrivers[index];
    else
        return NULL;
}

void driversParsing(char *linha){

    DRIVERS driver1 = malloc(sizeof (struct driver ));
    char *head;
    char *tail;
    int i ;

    head = strtok_r(linha,";",&tail);
    i = strlen(head);
    head[i]='\0';
    driver1->id= strdup(head);

    head = strtok_r(NULL,";",&tail);
    i = strlen(head);
    head[i]='\0';
    driver1->name= strdup(head);

    head = strtok_r(NULL,";",&tail);
    i= strlen(head);
    head[i]='\0';
    driver1->birth_day= strdup(head);

    head = strtok_r(NULL,";",&tail);
    i = strlen(head);
    head[i]='\0';
    driver1->gender= strdup(head);

    head = strtok_r(NULL,";",&tail);
    i = strlen(head);
    head[i]='\0';
    driver1->car_class= strdup(head);

    head = strtok_r(NULL,";",&tail);
    i = strlen(head);
    head[i]='\0';
    driver1->license_plate= strdup(head);

    head = strtok_r(NULL,";",&tail);
    i = strlen(head);
    head[i]='\0';
    driver1->city= strdup(head);

    head = strtok_r(NULL,";",&tail);
    i = strlen(head);
    head[i]='\0';
    driver1->account_creation= strdup(head);

    head = strtok_r(NULL,";",&tail);
    i = strlen(head);
    head[i]='\0';
    driver1->account_status= strdup(head);

    bool bools =hashTableInsertDrivers(driver1);
    if(!bools){

    }
}
