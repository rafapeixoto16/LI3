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