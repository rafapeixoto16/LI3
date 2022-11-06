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

RIDES hashTableRides[hashMaxRides];

void initHashTableRides(){
    for (int i = 0; i < hashMaxRides; i++) {
        hashTableRides[i]=NULL;
    }
}

void printTableRides(){
    for (int i = 0; i < hashMaxRides; i++){
        if (hashTableRides[i]!=NULL){
            printf("\t%s\n", ((hashTableRides[i])->id));
    } else
        printf("errou\n");
    }
}

bool hashTableInsertRides(RIDES ride){
    if(ride==NULL) return false;
    int index = hashRides(((ride)->id));
    if(hashTableRides[index]!=NULL){
        return false;
    }
    hashTableRides[index]=ride;
    return true;
}

RIDES hashTableLookupRides(char *id){
    int index = hashRides(id);
    if(hashTableRides[index]!=NULL && strcmp((hashTableRides[index])->id,id)==0)
        return hashTableRides[index];
    else
        return NULL;

}

void ridesParsing (char *linha){

    RIDES ride1 = malloc(sizeof (struct ride));
    char *head;
    char *tail;
    int i;

    head = strtok_r(linha,";",&tail);
    i = strlen(head);
    head[i]='\0';
    ride1->id= strdup(head);

    head = strtok_r(NULL,";",&tail);
    i = strlen(head);
    head[i]='\0';
    ride1->date= strdup(head);

    head = strtok_r(NULL,";",&tail);
    i = strlen(head);
    head[i]='\0';
    ride1->driver= strdup(head);

    head = strtok_r(NULL,";",&tail);
    i = strlen(head);
    head[i]='\0';
    ride1->user= strdup(head);

    head = strtok_r(NULL,";",&tail);
    i = strlen(head);
    head[i]='\0';
    ride1->city= strdup(head);

    head = strtok_r(NULL,";",&tail);
    i = strlen(head);
    head[i]='\0';
    ride1->distance= strdup(head);

    head = strtok_r(NULL,";",&tail);
    i = strlen(head);
    head[i]='\0';
    ride1->score_user= strdup(head);

    head = strtok_r(NULL,";",&tail);
    i = strlen(head);
    head[i]='\0';
    ride1->score_driver= strdup(head);

    head = strtok_r(NULL,";",&tail);
    i = strlen(head);
    head[i]='\0';
    ride1->tip= strdup(head);

    head = strtok_r(NULL,";",&tail);
    i = strlen(head);
    head[i]='\0';
    ride1->comment=strdup(head);

    bool bools =hashTableInsertRides(ride1);
    if(!bools){

    }

}

bool lookupCidadeRides(int i ,char *cidade){
    if(strcmp(hashTableRides[i]->city,cidade)==0)
        return true;
    return false;
}

char *lookupDriverRides(int i){
    return hashTableRides[i]->driver;
}

int lookupDistanceRides(int i){
    return atoi(hashTableRides[i]->distance);
}