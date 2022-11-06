//
// Created by rafael on 06-11-2022.
//
#include "queries.h"
double quary4(char *cidade) {
    double divide = 0, valor = 0.00;

    for (int i = 0; i < hashMaxRides; i++) {
        if (lookupCidadeRides(i, cidade)) {
            char *id = lookupDriverRides(i);
            int distancia = lookupDistanceRides(i);
            valor += precoViagem(distancia, id);
            divide++;
        }
    }
    return (valor/divide);
}