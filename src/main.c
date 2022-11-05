#include <stdio.h>
#include "drivers.h"
#include "rides.h"
#include "users.h"

int main (){

    initHashTableDrivers();
    initHashTableRides();
    initHashTable();
    //Drivers

    FILE *fpDrivers;

    fpDrivers = fopen ("../datasetfase1/drivers.csv","r");//linha lixo

    char linha [250];
    fgets(linha,250,fpDrivers);

    while(fgets(linha,250,fpDrivers)!=NULL){
        driversParsing(linha);
    }
    printTableDrivers();

    fclose(fpDrivers);

    //Rides
    FILE *fpRides;

    fpRides = fopen ("../datasetfase1/rides.csv","r");//linha lixo

    fgets(linha,250,fpRides);

    while(fgets(linha,250,fpRides)!=NULL){
        ridesParsing(linha);
    }
    printTableRides();

    fclose(fpRides);


    //Users
    FILE *fpUsers;
    fpDrivers = fopen ("../datasetfase1/drivers.csv","r");//linha lixo

    fgets(linha,250,fpDrivers);

    while(fgets(linha,250,fpRides)!=NULL){
        userParsing(linha);
    }
    printTableUsers();
    //free();
    return 0;
}
