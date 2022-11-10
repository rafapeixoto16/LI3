//
// Created by rafael on 06-11-2022.
//

#include "parsing.h"


void parsing(char *dataset){

    //inicializaçao das HashTables-Com valor NULL
    initHashTableDrivers();
    initHashTableRides();
    initHashTableUsers();

    //Linha
    char linha [232];

    //Drivers
    FILE *fpDrivers;

    char *path= strdup(dataset);
    strcat(path,"drivers.csv");
    fpDrivers = fopen (path,"r");

    char *drop1 = fgets(linha,232,fpDrivers);//linha lixo


    if(drop1!=NULL) {
        while (fgets(linha, 232, fpDrivers) != NULL) {
            driversParsing(linha);
        }
    }

    printTableDrivers();
    fclose(fpDrivers);
    free(path);

    //Rides
    FILE *fpRides;

    path= strdup(dataset);
    strcat(path,"rides.csv");
    fpRides = fopen (path,"r");

    char *drop2 = fgets(linha,232,fpRides);//linha lixo

    if(drop2 != NULL ){
        while (fgets(linha, 232, fpRides) != NULL) {
            ridesParsing(linha);
        }
    }

    printTableRides();

    fclose(fpRides);
    free(path);


    //Users
    FILE *fpUsers;

    path = strdup(dataset);
    strcat(path,"users.csv");
    fpUsers = fopen (path,"r");

    char *drop3 = fgets(linha,232,fpUsers);//linha lixo

    if(drop3 != NULL) {
        while (fgets(linha, 232, fpRides) != NULL) {
            userParsing(linha);
        }
    }

    printTableUsers();

    fclose(fpUsers);
    free(path);

}