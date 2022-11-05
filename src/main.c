#include <stdio.h>
#include "drivers.h"
#include "rides.h"
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
    initHashTableRides();

    FILE *fpRides;

    fpRides = fopen ("../datasetfase1/rides.csv","r");//linha lixo

    fgets(linha,250,fpRides);

    while(fgets(linha,250,fpRides)!=NULL){
        ridesParsing(linha);
    }
    printTableRides();
    fclose(fpRides);

    return 0;
}
