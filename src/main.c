#include <stdio.h>
#include "drivers.h"
int main (){

    //Drivers
    initHashTableDrivers();
    FILE *fpDrivers;

    fpDrivers = fopen ("../datasetfase1/drivers.csv","r");//linha lixo

    char linha [1000];

    fgets(linha,200,fpDrivers);

    while(fgets(linha,200,fpDrivers)!=NULL){
        driversParsing(linha);

    }
    printTableDrivers();
    fclose(fpDrivers);

    //Rides

    FILE *fpRides;

    fpRides = fopen ("../datasetfase1/rides.csv","r");//linha lixo

    fgets(linha,1000,fpRides);

    while(fgets(linha,1000,fpRides)!=NULL){

    }

    return 0;
}
