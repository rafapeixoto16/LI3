#include "parsing.h"


void parsing(char *dataset){

    //inicializaçao das HashTables-Com valor NULL
    initHashTableDrivers ();
    initHashTableRides   ();
    initHashTableUsers   ();

    char linha[250];


    //Drivers
    FILE *fpDrivers;

    snprintf          (linha,250,"%s%s",dataset,"drivers.csv");
    fpDrivers = fopen (linha,"r");

    char *drop1 = fgets(linha,250,fpDrivers);//linha lixo

    if(drop1!=NULL) {
        while (fgets(linha, 250, fpDrivers) != NULL) {
            driversParsing(linha);
        }
    }

    //printTableDrivers();
    fclose(fpDrivers);


    //Rides
    FILE *fpRides;

    snprintf        (linha,250,"%s%s",dataset,"rides.csv");
    fpRides = fopen (linha,"r");

    char *drop2 = fgets(linha,250,fpRides);//linha lixo

    if(drop2 != NULL ){
        while (fgets(linha, 250, fpRides) != NULL) {
            ridesParsing(linha);
        }
    }

    //printTableRides();
    fclose(fpRides);


    //Users
    FILE *fpUsers;

    snprintf        (linha,250,"%s%s",dataset,"users.csv");
    fpUsers = fopen (linha,"r");

    char *drop3 = fgets(linha,250,fpUsers);//linha lixo

    if(drop3 != NULL) {
        while (fgets(linha, 250, fpUsers) != NULL) {
            userParsing(linha);
        }
    }

    //printTableUsers();
    fclose(fpUsers);

}