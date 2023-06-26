#include "../includes/parsing.h"
#include "time.h"
// --------------------------------------------
// parsing
// --------------------------------------------


void parsing (char *dataset, ARRAYDinamico ride, ARRAYDinamico drive, ARRAYDinamico user) {

    //inicializaçao das HashTables-Com valor NULL
    hashInitNull  (drive,0);
    hashInitNull  (ride ,0);
    hashInitNull  (user ,0);

    char linha[250];

    clock_t start, end;
    double cpu_time_used;
    start = clock();

    //Drivers
    FILE *fpDrivers;

    snprintf (linha,250,"%s%s",dataset,"/drivers.csv");
    fpDrivers = fopen (linha,"r");

    char *drop1 = fgets(linha,250,fpDrivers);//linha lixo

    if(drop1!=NULL) {
        while (fgets(linha, 250, fpDrivers) != NULL) {
            driversParsing(linha,drive);
        }
    }

    fclose(fpDrivers);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Parsing do Driver - %f segundos \n", cpu_time_used);

    //Rides
    FILE *fpRides;

    start = clock();
    snprintf (linha,250,"%s%s",dataset,"/rides.csv");
    fpRides = fopen (linha,"r");

    char *drop2 = fgets(linha,250,fpRides);//linha lixo


    if(drop2 != NULL ){
        while (fgets(linha, 250, fpRides) != NULL) {
            ridesParsing(linha,ride);
        }
    }

    fclose(fpRides);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Parsing do Rides - %f segundos \n", cpu_time_used);

    //Users
    FILE *fpUsers;

    snprintf (linha,250,"%s%s",dataset,"/users.csv");
    fpUsers = fopen (linha,"r");

    char *drop3 = fgets(linha,250,fpUsers);//linha lixo

    if(drop3 != NULL) {
        while (fgets(linha, 250, fpUsers) != NULL) {
            userParsing(linha,user);
        }
    }

    fclose(fpUsers);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Parsing do Users - %f segundos \n", cpu_time_used);

    printf("\n");
}