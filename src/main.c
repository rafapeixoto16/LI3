#include <stdio.h>
#include "drivers.h"
int main (){

    //Drivers
    initHashTableDrivers();
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

    }

    return 0;
}
