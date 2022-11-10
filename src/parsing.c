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
    char linha[250];


    //Drivers
    FILE *fpDrivers;

    snprintf(linha,250,"%s%s",dataset,"drivers.csv");
    fpDrivers = fopen (linha,"r");
    if(fpDrivers == NULL) {
        perror("Error opening file");
        return;
    }
    char *drop1 = fgets(linha,250,fpDrivers);//linha lixo

    if(drop1!=NULL) {
        while (fgets(linha, 250, fpDrivers) != NULL) {
            driversParsing(linha);
        }
    }

    printTableDrivers();
    fclose(fpDrivers);
    //free(path);


    //Rides
    FILE *fpRides;

    snprintf(linha,250,"%s%s",dataset,"rides.csv");
    fpRides = fopen (linha,"r");//linha lixo
    char *drop2 = fgets(linha,250,fpRides);

    if(drop2 != NULL ){
        while (fgets(linha, 250, fpRides) != NULL) {
            ridesParsing(linha);
        }
    }

    printTableRides();

    fclose(fpRides);
    //free(path);


    //Users
    FILE *fpUsers;

    //path = strdup(dataset);
    // strcat(path,"users.csv");

    snprintf(linha,250,"%s%s",dataset,"users.csv");
    fpUsers = fopen (linha,"r");

    char *drop3 = fgets(linha,250,fpUsers);//linha lixo

    if(drop3 != NULL) {
        while (fgets(linha, 250, fpUsers) != NULL) {
            userParsing(linha);
        }
    }

    printTableUsers();

    fclose(fpUsers);
    //free(path);

}