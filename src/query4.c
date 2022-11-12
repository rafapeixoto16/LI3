//
// Created by rafael on 06-11-2022.
//
#include "queries.h"


double query4 (char *cidade) {
    double divide = 0, valor = 0;
    char *lixo;
    cidade = strtok_r(cidade,"\n",&lixo);

    for (int i = 0; i < hashMaxRides; i++) {
        char *cidadeAtual = lookupCidadeRides(i);
        if (strcmp(cidadeAtual,cidade)==0) {
            char *id = lookupDriverRides(i);
            int distancia = lookupDistanceRides(i);
            valor += precoViagem(distancia, id);
            divide++;
        }
    }
    return (valor/divide);
}

