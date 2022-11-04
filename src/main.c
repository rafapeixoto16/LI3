#include <stdio.h>
int main (){

    printf("aqui");

    //Drivers

    FILE *fpDrivers;

    fpDrivers = fopen ("../datasetfase1/drivers.csv","r");

    char linha [1000];

    fgets(linha,1000,fpDrivers);

    while(fgets(linha,1000,fpDrivers)!=NULL){

    }

    //Rides

    FILE *fpRides;

    fpRides = fopen ("../datasetfase1/rides.csv","r");

    fgets(linha,1000,fpRides);

    while(fgets(linha,1000,fpRides)!=NULL){

    }

    return 0;
}
