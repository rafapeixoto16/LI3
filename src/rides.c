#include "../includes/rides.h"
#include "../includes/array.h"


struct ride {
    char *id;
    int  date;
    char *driver;
    char *user;
    char *city;
    char *distance;
    char *score_user;
    char *score_driver;
    char *tip;
};


// --------------------------------------------
// ridesParsing
// --------------------------------------------


void ridesParsing (char *linha,void* arrayD){
    ARRAYDinamico array = arrayD;
    RIDES ride1 = malloc(sizeof (struct ride));

    char *tail = NULL;
    int i;

    i = idRide (strtok_r(linha,";",&tail), ride1);

    if(i)
        return;

    i = dataCorridaRide (strtok_r(NULL,";",&tail), ride1);

    if(i)
        return;

    i = idDriverRide (strtok_r(NULL,";",&tail), ride1);

    if(i)
        return;

    i = nomeUserRide (strtok_r(NULL,";",&tail), ride1);

    if(i)
        return;

    i = cidadeRide (strtok_r(NULL,";",&tail), ride1);

    if(i)
        return;

    i = distanciaRide (strtok_r(NULL,";",&tail), ride1);

    if(i)
        return;

    i = scoreUserRide (strtok_r(NULL,";",&tail), ride1);

    if(i)
        return;

    i = scoreDriverRide (strtok_r(NULL,";",&tail), ride1);

    if(i)
        return;

    i = tipRide (strtok_r(NULL,";",&tail), ride1);

    if(i)
        return;

    arrayAdd(array,ride1, strdup(ride1->id));
}

// --------------------------------------------
// idRide
// --------------------------------------------

int idRide(char *id, RIDES rides){
    id[strlen(id)] = '\0';

    if(tamanhoEqual0(id)){
        free(id);
        return 1;
    }

    rides -> id = strdup(id);
    return 0;
}

// --------------------------------------------
// dataCorridaRide
// --------------------------------------------

int dataCorridaRide (char *data, RIDES rides){
    data[strlen(data)] = '\0';

    if(!verificaDate(data)){
        freeRideId(rides);
        return 1;
    }

    rides -> date = data2Int(data);
    return 0;
}

// --------------------------------------------
// idDriverRide
// --------------------------------------------

int idDriverRide (char *id, RIDES rides){
    id[strlen(id)] = '\0';

    if(tamanhoEqual0(id)){
        freeRideDate(rides);
        return 1;
    }

    rides -> driver = strdup(id);
    return 0;
}

// --------------------------------------------
// nomeUserRide
// --------------------------------------------

int nomeUserRide(char *nome, RIDES rides){
    nome[strlen(nome)] = '\0';

    if(tamanhoEqual0(nome)){
        freeRideDriver(rides);
        return 1;
    }

    rides -> user = strdup(nome);
    return 0;
}

// --------------------------------------------
// cidadeRide
// --------------------------------------------

int cidadeRide(char *cidade, RIDES rides){
    cidade[strlen(cidade)] = '\0';

    if(tamanhoEqual0(cidade)){
        freeRideUser(rides);
        return 1;
    }

    rides -> city = strdup(cidade);
    return 0;
}

// --------------------------------------------
// distanciaRide
// --------------------------------------------

int distanciaRide(char *distancia, RIDES rides){
    distancia[strlen(distancia)] = '\0';

    if (!(isInteger(distancia) && atoi(distancia) > 0)){
        freeRideCity(rides);
        return 1;
    }

    rides -> distance = strdup(distancia);
    return 0;
}

// --------------------------------------------
// scoreUserRide
// --------------------------------------------

int scoreUserRide(char *scoreU,RIDES rides){
    scoreU[strlen(scoreU)] = '\0';

    if(!(isInteger(scoreU) && atoi(scoreU) > 0)){
        freeRideDistance(rides);
        return 1;
    }

    rides -> score_user = strdup(scoreU);
    return 0;
}

// --------------------------------------------
// scoreDriverRide
// --------------------------------------------

int scoreDriverRide(char *scoreD, RIDES rides){
    scoreD[strlen(scoreD)] = '\0';

    if(!(isInteger(scoreD) && atoi(scoreD) > 0)){
        freeRideScore_User(rides);
        return 1;
    }

    rides->score_driver= strdup(scoreD);
    return 0;
}

// --------------------------------------------
// tipRide
// --------------------------------------------

int tipRide(char *tip, RIDES rides){
    tip[strlen(tip)] = '\0';

    if(isNumber(tip) || atoi(tip) < 0){
        freeRideScore_Driver(rides);
        return 1;
    }

    rides->tip= strdup(tip);
    return 0;
}

// --------------------------------------------
// printRide
// --------------------------------------------

void printRide(RIDES rides){
    printf("id= %s, date= %i,driver= %s, user= %s, city= %s, distance= %s, scrore_user= %s, score_driver= %s, tip = %s \n ",
            rides->id,
            rides->date,
            rides->driver,
            rides->user,
            rides->city,
            rides->distance,
            rides->score_user,
            rides->score_driver,
            rides->tip);
}

// --------------------------------------------
// lookupCidadeRides
// --------------------------------------------

char *lookupCidadeRides (RIDES ride1){
    return strdup(ride1->city);
}

// --------------------------------------------
// lookupDriverRides
// --------------------------------------------

char *lookupDriverRides (RIDES ride1){
    return strdup(ride1->driver);
}

// --------------------------------------------
// lookupDriverIntRides
// --------------------------------------------

int lookupDriverIntRides(RIDES ride1){
    return atoi(ride1->driver);
}

// --------------------------------------------
// lookupUserRides
// --------------------------------------------

char *lookupUserRides (RIDES ride1) {
    return strdup(ride1->user);
}

// --------------------------------------------
// lookupDistanceRides
// --------------------------------------------

int lookupDistanceRides (RIDES ride1){
    return atoi(ride1->distance);
}

// --------------------------------------------
// lookupDateRides
// --------------------------------------------

int lookupDateRides (RIDES ride1){
    int retorna = ride1 -> date;
    return retorna;
}

// --------------------------------------------
// lookupTipRides
// --------------------------------------------


double lookupTipRides (RIDES ride1){
    return atof(ride1->tip);
}

// --------------------------------------------
// lookupScoreUserRides
// --------------------------------------------


double lookupScoreUserRides (RIDES ride1){
    return atof(ride1->score_user);
}

// --------------------------------------------
// lookupScoreDriverRides
// --------------------------------------------

double lookupScoreDriverRides (RIDES ride1){
    return atof(ride1->score_driver);
}

// --------------------------------------------
// lookupIdViagem
// --------------------------------------------

char *lookupIdViagem(RIDES rides1){
    return strdup(rides1->id);
}

// --------------------------------------------
// lookupIdViagemInt
// --------------------------------------------

int lookupIdViagemInt(RIDES ride1){
    return (int )atoi(ride1->id);
}

// --------------------------------------------
// freeRide
// --------------------------------------------


void freeRide(RIDES ride){
    free            (ride->id);
    free        (ride->driver);
    free          (ride->user);
    free          (ride->city);
    free      (ride->distance);
    free    (ride->score_user);
    free  (ride->score_driver);
    free           (ride->tip);
    free                (ride);
}

// --------------------------------------------
// freeRideId
// --------------------------------------------


void freeRideId(RIDES rides){
    free            (rides->id);
    free                (rides);
}

// --------------------------------------------
// freeRideDate
// --------------------------------------------


void freeRideDate(RIDES rides){
    free            (rides->id);
    free                (rides);
}


// --------------------------------------------
// freeRideDriver
// --------------------------------------------


void freeRideDriver(RIDES rides){
    free            (rides->id);
    free        (rides->driver);
    free                (rides);
}

// --------------------------------------------
// freeRideUser
// --------------------------------------------


void freeRideUser(RIDES rides){
    free            (rides->id);
    free        (rides->driver);
    free          (rides->user);
    free                (rides);
}

// --------------------------------------------
// freeRideCity
// --------------------------------------------


void freeRideCity(RIDES rides){
    free            (rides->id);
    free        (rides->driver);
    free          (rides->user);
    free          (rides->city);
    free                (rides);
}

// --------------------------------------------
// freeRideDistance
// --------------------------------------------


void freeRideDistance(RIDES rides){
    free            (rides->id);
    free        (rides->driver);
    free          (rides->user);
    free          (rides->city);
    free      (rides->distance);
    free                (rides);
}

// --------------------------------------------
// freeRideScore_User
// --------------------------------------------


void freeRideScore_User(RIDES rides){
    free            (rides->id);
    free        (rides->driver);
    free          (rides->user);
    free          (rides->city);
    free      (rides->distance);
    free    (rides->score_user);
    free                (rides);
}

// --------------------------------------------
// freeRideScore_Driver
// --------------------------------------------


void freeRideScore_Driver(RIDES rides){
    free            (rides->id);
    free        (rides->driver);
    free          (rides->user);
    free          (rides->city);
    free      (rides->distance);
    free    (rides->score_user);
    free  (rides->score_driver);
    free                (rides);
}
