#include "queries.h"

// --------------------------------------------
// query4
// --------------------------------------------

double query4 (char *cidade) {
    double divide = 0, valor = 0;
    char *lixo;
    cidade = strtok_r(cidade,"\n",&lixo);

    for (int i = 0; i < hashMaxRides; i++) {
        char *cidadeAtual = lookupCidadeRides(i);

        if (strcmp(cidadeAtual,cidade)==0) {
            char *id      = lookupDriverRides(i);
            int distancia = lookupDistanceRides(i);
            valor        += precoViagem(distancia, id);
            divide++;

            free(id);
        }

        free(cidadeAtual);
    }
    return (valor/divide);
}

