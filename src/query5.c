//
// Created by rafael on 06-11-2022.
//

#include "queries.h"

double query5(char *dataInicio,char *dataFim) {
    char *temp;

    int diaInicio = atoi(strtok_r(dataInicio, "/", &temp));
    int mesInicio = atoi(strtok_r(NULL, "/", &temp));
    int anoInicio = atoi(strtok_r(NULL,"/",&temp));
    int diaFim = atoi(strtok_r(dataFim,"/",&temp));
    int mesFim = atoi(strtok_r(NULL,"/",&temp));
    int anoFim = atoi(strtok_r(NULL,"/",&temp));

    int precoAtual=0;

    for (int i = 0; i < hashMaxRides; i++) {

        char *data=lookupDateRides(i);
        int diaAtual = atoi(strtok_r(data, "/", &temp));
        int mesAtual = atoi(strtok_r(NULL, "/", &temp));
        int anoAtual = atoi(strtok_r(NULL,"/",&temp));

        if(anoFim<anoAtual || anoInicio>anoAtual){
            continue;
        }
        else if (anoInicio<anoAtual<anoInicio){
            //todo fazer isto
        }
        else if (anoInicio==anoAtual){
            if(1);
        }
        else {
            //todo anoFim==anoAtual
        }
    }

}