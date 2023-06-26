#include "../includes/interpretador.h"
#include "../includes/parsing.h"
#include "../includes/freeDataset.h"
#include "../includes/parsingInput.h"


void interpretador(char *argv[]){
    char *dataset=argv[1];
    char *input =argv[2];

    //Criaçao dos array
    ARRAYDinamico driveTable = arrayCreate( tamanhoInicialD,Driver);
    ARRAYDinamico rideTable  = arrayCreate( tamanhoInicialR,Ride  );
    ARRAYDinamico userTable  = arrayCreate( tamanhoInicialU,User  );

    //Parsing dos ficheiros (csv)
    parsing (dataset,rideTable,driveTable,userTable);

    //Stats Users Drivers
    ARRAYDinamico statusD = arrayCreate(tamanhoHash(driveTable),StatusDriver);
    ARRAYDinamico statusU = arrayCreate(tamanhoHash(userTable) ,StatusUser  );

    //Ordena o array Rides
    ordena(rideTable);

    //Parsing do Status
    parsingStatus(rideTable, statusD, statusU,driveTable,userTable);

    //Parsing do Input (input.txt)
    parsingInput (input,driveTable,userTable,rideTable,statusD,statusU);

    //Free dataset
    freeDataset(driveTable,rideTable,userTable,statusD,statusU);
}