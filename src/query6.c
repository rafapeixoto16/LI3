//
// Created by rafael on 06-11-2022.
//

#include "queries.h"

double query6(char *cidade,char *dataInicio,char *dataFim) {
    char *temp;

    int diaInicio = atoi(strtok_r(dataInicio, "/", &temp));
    int mesInicio = atoi(strtok_r(NULL, "/", &temp));
    int anoInicio = atoi(strtok_r(NULL, "/", &temp));
    int diaFim = atoi(strtok_r(dataFim, "/", &temp));
    int mesFim = atoi(strtok_r(NULL, "/", &temp));
    int anoFim = atoi(strtok_r(NULL, "/", &temp));

    double distanciaAtual = 0;
    double divide = 0;

    for (int i = 0; i < hashMaxRides; i++) {

        if(lookupCidadeRides(i,cidade)) {
            char *data = lookupDateRides(i);
            int diaAtual = atoi(strtok_r(data, "/", &temp));
            int mesAtual = atoi(strtok_r(NULL, "/", &temp));
            int anoAtual = atoi(strtok_r(NULL, "/", &temp));

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