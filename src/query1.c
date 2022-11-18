//
// Created by rafael on 10-11-2022.
//
#include "queries.h"

char *query1(char *id){
    char stringR[250];
    char *lixo;
    id = strtok_r(id,"\n",&lixo);

    int numero = 0;
    if(isdigit(id[0]))
        numero=1;


    if(numero==1){
        char *status = lookupStatusDriver(id);

        if  ( strcmp(status,"inactive") == 0){
            free(status);
            return NULL;
        }

        if( strcmp(status,"active") == 0) {

            char *nome   = lookupNomeDriver(id);
            char *genero = lookupGeneroDriver(id);
            int  idade   = lookupIdadeDriver(id);


            double avaliacaoMedia = 0.00 ;
            int    numeroViagens  = 0    ;
            double totalAuferido  = 0.000;

            lookupAvalNViagemTotAufDrivers(id,&avaliacaoMedia,&numeroViagens,&totalAuferido);

            snprintf(stringR,250,"%s;%s;%i;%.3f;%i;%.3f",
                     nome,
                     genero,
                     idade,
                     avaliacaoMedia,
                     numeroViagens,
                     totalAuferido);


            free(nome);
            free(genero);
        }

        free   (status );
        return strdup(stringR);
    }

    else {
        char *status = lookupStatusUser(id);

        if  ( strcmp(status,"inactive") == 0){
            free(status);
            return NULL;
        }

        else if (strcmp(status,"active") == 0) {
            char *nome = lookupNomeUser(id);
            char *genero = lookupGeneroUser(id);
            int idade = lookupIdadeUser(id);
            double avaliacaoMedia = 0.000;
            int numeroViagens = 0;
            double totalGasto = 0.000;

            lookupAvalNViagemTotAufUser(id, &avaliacaoMedia, &numeroViagens, &totalGasto);

            snprintf(stringR, 250, "%s;%s;%i;%.3f;%i;%.3f",
                     nome,
                     genero,
                     idade,
                     avaliacaoMedia,
                     numeroViagens,
                     totalGasto);


            free(nome);
            free(genero);
        }

        free(status);
        return strdup(stringR);
    }
}