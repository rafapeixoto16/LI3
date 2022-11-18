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

RIDES hashTableRides[hashMaxRides];

// --------------------------------------------
// hashRides
// --------------------------------------------

unsigned int hashRides(char *id){
    return ((atoi(id)-1));
}

// --------------------------------------------
// initHashTableRides
// --------------------------------------------

void initHashTableRides(){
    for (int i = 0; i < hashMaxRides; i++) {
        hashTableRides[i]=NULL;
    }
}

// --------------------------------------------
// printTableRides
// --------------------------------------------

void printTableRides(){
    for (int i = 0; i < hashMaxRides; i++){
        if (hashTableRides[i]!=NULL){
            printf("\t%s--%s--%s--\n", ((hashTableRides[i])->id),(hashTableRides[i]->date),hashTableRides[i]->distance);
    } else
        printf("errou\n");
    }
}

// --------------------------------------------
// hashTableInsertRides
// --------------------------------------------

bool hashTableInsertRides(RIDES ride){
    if(ride==NULL) return false;
    unsigned int index = hashRides(((ride)->id));
    if(hashTableRides[index]!=NULL){
        return false;
    }
    hashTableRides[index]=ride;
    return true;
}

// --------------------------------------------
// hashTableLookupRides
// --------------------------------------------

/*RIDES hashTableLookupRides(char *id){
    unsigned int index = hashRides(id);
    if(hashTableRides[index]!=NULL && strcmp((hashTableRides[index])->id,id)==0)
        return hashTableRides[index];
    else
        return NULL;

}*/

// --------------------------------------------
// ridesParsing
// --------------------------------------------

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

// --------------------------------------------
// lookupCidadeRides
// --------------------------------------------

char *lookupCidadeRides (int i){
    return strdup(hashTableRides[i]->city);
}

// --------------------------------------------
// lookupDriverRides
// --------------------------------------------

char *lookupDriverRides (int i){
    return strdup(hashTableRides[i]->driver);
}

// --------------------------------------------
// lookupDistanceRides
// --------------------------------------------

int lookupDistanceRides(int i){
    return atoi(hashTableRides[i]->distance);
}

// --------------------------------------------
// lookupDateRides
// --------------------------------------------

char *lookupDateRides(int i){
    char *retorna = strdup(hashTableRides[i]->date);
    return retorna;
}

// --------------------------------------------
// lookupAvalNViagemTotAufDrivers
// --------------------------------------------

void lookupAvalNViagemTotAufDrivers (char *id,double *avaliacaoMedia,int *numeroViagens,double *totalAuferido){
    int divide=0,nV = 0;
    double avaliacao = 0.000, dinheiro =0.000;

    for (int i = 0; i < hashMaxRides; i++){
        if(strcmp(hashTableRides[i]->driver,id)==0){
            avaliacao  += atoi(hashTableRides[i]->score_driver);
            dinheiro   += atof(hashTableRides[i]->tip) + precoViagem(atoi(hashTableRides[i]->distance),id);
            nV++;
            divide++;
        }
    }
    *avaliacaoMedia = (avaliacao/divide);
    *totalAuferido  =  dinheiro;
    *numeroViagens  =  nV;
}

// --------------------------------------------
// lookupAvalNViagemTotGastoUser
// --------------------------------------------

void lookupAvalNViagemTotGastoUser(char *id,double *avaliacaoMedia,int *numeroViagens,double *totalGasto){
    int nV = 0;
    double avaliacao = 0.000, dinheiro =0.000, divide = 0;

    for (int i = 0; i < hashMaxRides; i++) {

        if(strcmp(hashTableRides[i]->user,id) == 0){
            avaliacao  += atoi(hashTableRides[i]->score_user);
            dinheiro   += (double ) atof(hashTableRides[i]->tip) + (double )precoViagem(atoi(hashTableRides[i]->distance),hashTableRides[i]->driver);
            nV++;
            divide++;
        }
    }
    *avaliacaoMedia = (avaliacao/divide);
    *totalGasto     =  dinheiro;
    *numeroViagens  =  nV;
}


void freeRides (){
    for (int i = 0; i < hashMaxRides ; i++) {
        free     (hashTableRides[i]->distance);
        free       (hashTableRides[i]->driver);
        free           (hashTableRides[i]->id);
        free          (hashTableRides[i]->tip);
        free         (hashTableRides[i]->date);
        free         (hashTableRides[i]->city);
        free   (hashTableRides[i]->score_user);
        free         (hashTableRides[i]->user);
        free (hashTableRides[i]->score_driver);
        free      (hashTableRides[i]->comment);
    }
}