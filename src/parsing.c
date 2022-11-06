//
// Created by rafael on 06-11-2022.
//

#include "parsing.h"


void parsing(){

    initHashTableDrivers();
    initHashTableRides();
    initHashTableUsers();
    //Drivers

    FILE *fpDrivers;

    fpDrivers = fopen ("../datasetfase1/drivers.csv","r");

    char linha [250];
    fgets(linha,250,fpDrivers);//linha lixo

    while(fgets(linha,250,fpDrivers)!=NULL){
        driversParsing(linha);
    }
    printTableDrivers();

    fclose(fpDrivers);

    //Rides
    FILE *fpRides;

    fpRides = fopen ("../datasetfase1/rides.csv","r");

    fgets(linha,250,fpRides);//linha lixo

    while(fgets(linha,250,fpRides)!=NULL){
        ridesParsing(linha);
    }
    printTableRides();

    fclose(fpRides);


    //Users
    FILE *fpUsers;
    fpUsers = fopen ("../datasetfase1/users.csv","r");

    fgets(linha,250,fpDrivers);//linha lixo

    while(fgets(linha,250,fpRides)!=NULL){
        userParsing(linha);
    }
    printTableUsers();

    fclose(fpUsers);


}