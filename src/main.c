#include <stdio.h>
#include "drivers.h"
int main (){

    printf("aqui");

    //Drivers
    initHashTableDrivers();
    FILE *fpDrivers;

    fpDrivers = fopen ("../datasetfase1/drivers.csv","r");

    char linha [1000];

    fgets(linha,1000,fpDrivers);

    while(fgets(linha,1000,fpDrivers)!=NULL){
        driversParsing(linha);
    }
    fclose(fpDrivers);
    //Rides

    FILE *fpRides;

    fpRides = fopen ("../datasetfase1/rides.csv","r");

    fgets(linha,1000,fpRides);

    while(fgets(linha,1000,fpRides)!=NULL){

    }

    return 0;
}
