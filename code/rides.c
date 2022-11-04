#include "rides.h"

struct ride {
	char *id;
	char *date;
	char *driver;
	char *user;
	char *city;
	char *distance;
	char *score_user;
	char *score_driver;
	char *tip;
	char *comment;
};

unsigned int hashRides(char *id){
    return ((atoi(id)-1));
}

RIDES *hashTableRides[hashMaxRides];

void initHashTableRides(){
    for (int i = 0; i < hashMaxRides; i++) {
        hashTableRides[i]=NULL;
    }
}

void printTableRides(){
    for (int i = 0; i < hashMaxRides; i++){
        if (hashTableRides[i]!=NULL)
            printf("siu");
        else
            printf(";(");
    }
}

bool hashTableInsertRides(RIDES *ride){
    if(ride==NULL) return false;
    int index = hashRides((*ride)->id);
    if(hashTableRides[index]!=NULL){
        return false;
    }
    hashTableRides[index]=ride;
}
