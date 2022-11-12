//
// Created by rafael on 10-11-2022.
//
#include "queries.h"

void query1(char *id,char *retorno){
    int numero=1;
    char stringR[250];

    for (int i = 0; i < strlen(id) && numero==1 ; i++) {
        if(isdigit(id[i])==1){
            continue;
        }
        else
            numero=0;
    }

    if(numero==1){
        char *status = lookupStatusDriver(id);

        if(strcmp(status,"active") == 0) {

            char *nome   = lookupNomeDriver(id);
            char *genero = lookupGeneroDriver(id);
            int  idade   = lookupIdadeDriver(id);

            double avaliacaoMedia = 0.00;
            int    numeroViagens  = 0;
            double totalAuferido  = 0.000;

            lookupAvalNViagemTotAufDrivers(id,&avaliacaoMedia,&numeroViagens,&totalAuferido);

            snprintf(stringR,250,"%s;%s;%i;%.3f;%i;%.3f",
                     nome,
                     genero,
                     idade,
                     avaliacaoMedia,
                     numeroViagens,
                     totalAuferido);

            *retorno=*stringR;
        }

        else{
            return;
        }

    }

    else{
        char *status = lookupStatusUser(id);

        if(strcmp(status,"active") == 0) {
            char *nome   = lookupNomeUser   (id);
            char *genero = lookupGeneroUser (id);
            int  idade   = lookupIdadeUser  (id);
            double avaliacaoMedia =0.000;
            int    numeroViagens  =0;
            double totalGasto     =0.000;

            lookupAvalNViagemTotAufUser(id,&avaliacaoMedia,&numeroViagens,&totalGasto);

            snprintf(stringR,250,"%s;%s;%i;%.3f;%i;%.3f",
                     nome,
                     genero,
                     idade,
                     avaliacaoMedia,
                     numeroViagens,
                     totalGasto);

            *retorno = *stringR;
        }

        else{
            return;
        }
    }
}