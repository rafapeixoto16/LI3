//
// Created by rafael on 06-11-2022.
//
#include "queries.h"

double query5(char *dataInicio,char *dataFim) {
    int diaInicio, mesInicio, anoInicio, diaFim, mesFim, anoFim;
    char *temp;

    diaInicio = atoi(strtok_r(dataInicio, "/", &temp));
    mesFim    = atoi(strtok_r(NULL, "/", &temp));
    anoFim    = atoi(strtok_r(NULL,"/",&temp));

}