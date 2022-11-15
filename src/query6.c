//
// Created by rafael on 06-11-2022.
//

#include "queries.h"

double query6(char *cidade,char *dataInicio,char *dataFim) {
    char *temp,*lixo;
    dataFim= strtok_r(dataFim,"\n",&lixo);

    int diaInicio = atoi(strtok_r(dataInicio, "/", &temp));
    int mesInicio = atoi(strtok_r(NULL      , "/", &temp));
    int anoInicio = atoi(strtok_r(NULL      , "/", &temp));
    int diaFim    = atoi(strtok_r(dataFim   , "/", &temp));
    int mesFim    = atoi(strtok_r(NULL      , "/", &temp));
    int anoFim    = atoi(strtok_r(NULL      , "/", &temp));

    double distanciaAtual = 0;
    double divide = 0;

    for (int i = 0; i < hashMaxRides; i++) {
        char *cidadeAtual = lookupCidadeRides(i);
        if(strcmp(cidadeAtual,cidade)==0) {
            char *data = lookupDateRides(i);

            char *diaAtualS = strtok_r(data, "/" , &temp);
            char *mesAtualS = strtok_r(NULL, "/" , &temp);
            char *anoAtualS = strtok_r(NULL, "\0", &temp);

            int diaAtual = atoi(diaAtualS);
            int mesAtual = atoi(mesAtualS);
            int anoAtual = atoi(anoAtualS);

            if (anoFim < anoAtual || anoInicio > anoAtual) {
                continue;
            }

            else if (anoInicio < anoAtual && anoAtual < anoInicio) {
                distanciaAtual += lookupDistanceRides(i);
                divide++;
            }

            else if (anoInicio == anoAtual) {

                if (mesInicio > mesAtual)
                    continue;

                else if (mesInicio < mesAtual) {
                    distanciaAtual += lookupDistanceRides(i);
                    divide++;
                }

                else if (mesInicio == mesAtual) {
                    if (diaInicio > diaAtual)
                        continue;
                    else {
                        distanciaAtual += lookupDistanceRides(i);
                        divide++;
                    }
                }
            }

            else {

                if (mesFim < mesAtual)
                    continue;

                else if (mesFim > mesAtual) {
                    distanciaAtual += lookupDistanceRides(i);
                    divide++;
                }

                else if (mesInicio == mesAtual) {
                    if (diaFim < diaAtual)
                        continue;
                    else {
                        distanciaAtual += lookupDistanceRides(i);
                        divide++;
                    }
                }
            }
        }
    }
    return (distanciaAtual/divide);
}