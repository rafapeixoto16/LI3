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
            printf("\t%s--%s--%s--\n", ((hashTableRides[i])->id),(hashTableRides[i]->date),hashTableRides[i]->distance);
    } else
        printf("errou\n");
    }
}

bool hashTableInsertRides(RIDES ride){
    if(ride==NULL) return false;
    unsigned int index = hashRides(((ride)->id));
    if(hashTableRides[index]!=NULL){
        return false;
    }
    hashTableRides[index]=ride;
    return true;
}

RIDES hashTableLookupRides(char *id){
    unsigned int index = hashRides(id);
    if(hashTableRides[index]!=NULL && strcmp((hashTableRides[index])->id,id)==0)
        return hashTableRides[index];
    else
        return NULL;

}

void ridesParsing (char *linha){

    RIDES ride1 = malloc(sizeof (struct ride));
    char *head;
    char *tail;
    unsigned long i;

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

char *lookupCidadeRides(int i ){
    return hashTableRides[i]->city;
}

char *lookupDriverRides(int i){
    return hashTableRides[i]->driver;
}

int lookupDistanceRides(int i){
    return atoi(hashTableRides[i]->distance);
}

char *lookupDateRides(int i){
    return hashTableRides[i]->date;
}

void lookupAvalNViagemTotAufDrivers (char *id,double *avaliacaoMedia,int *numeroViagens,double *totalAuferido){
    int divide=0,nV = 0;
    double avaliacao = 0.000, dinheiro =0.000;

    for (int i = 0; i < hashMaxRides; i++){
        if(strcmp(hashTableRides[i]->driver,id)==0){
            avaliacao += atoi(hashTableRides[i]->score_driver);
            dinheiro  += atoi(hashTableRides[i]->tip) + precoViagem(atoi(hashTableRides[i]->distance),id);
            nV++;
            divide++;
        }
    }
    *avaliacaoMedia = avaliacao/divide;
    *totalAuferido  = dinheiro;
    *numeroViagens  = nV;
}

void lookupAvalNViagemTotAufUser(char *id,double *avaliacaoMedia,int *numeroViagens,double *totalGasto){
    double divide=0;

    for (int i = 0; i < hashMaxRides; i++) {
        if(strcmp(hashTableRides[i]->user,id)==0){
            *avaliacaoMedia += atoi(hashTableRides[i]->score_user);
            *totalGasto  += atoi(hashTableRides[i]->tip) + precoViagem(atoi(hashTableRides[i]->distance),id);
            numeroViagens++;
            divide++;
        }
    }
    *avaliacaoMedia=*avaliacaoMedia/divide;
}