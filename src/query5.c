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

    double precoAtual=0;
    double divide=0;

    for (int i = 0; i < hashMaxRides; i++) {

        char *data=lookupDateRides(i);
        int diaAtual = atoi(strtok_r(data, "/", &temp));
        int mesAtual = atoi(strtok_r(NULL, "/", &temp));
        int anoAtual = atoi(strtok_r(NULL,"/",&temp));

        if(anoFim<anoAtual || anoInicio>anoAtual){
            continue;
        }

        else if (anoInicio<anoAtual<anoInicio){
            precoAtual += valor(i);
        }

        else if (anoInicio==anoAtual){
            if(mesInicio > mesAtual)
                continue;

            else if(mesInicio<mesAtual) {
                precoAtual += valor(i);
                divide++;
            }

            else if(mesInicio==mesAtual){
                if(diaInicio>diaAtual)
                    continue;
                else{
                    precoAtual += valor(i);
                    divide++;
                }
            }
        }


        else {

            if(mesFim < mesAtual)
                continue;

            else if(mesFim > mesAtual) {
                precoAtual += valor(i);
                divide++;
            }

            else if(mesInicio==mesAtual){
                if(diaFim<diaAtual)
                    continue;
                else {
                    precoAtual += valor(i);
                    divide;
                }
            }
        }
    }

    return (precoAtual/divide);
}

double valor(int id){
    char *idR = lookupDriverRides(id);
    int distancia = lookupDistanceRides(id);
    return precoViagem(distancia, idR);
}

