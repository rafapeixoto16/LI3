//
// Created by rafael on 06-11-2022.
//
#include "queries.h"

double query5(char *dataInicio,char *dataFim) {
    char *diaInicio, mesInicio, anoInicio, diaFim, mesFim, anoFim;
    char *temp;

    diaInicio = strtok_r(dataInicio, "/", &temp);
    mesFim    = strtok_r(NULL, "/", &temp);
    anoFim    = strtok_r(NULL,"/",&temp);
}