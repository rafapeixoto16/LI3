//
// Created by rafael on 06-11-2022.
//

#include "queries.h"

double query5(char *dataInicio,char *dataFim) {
    char *temp;

    int diaInicio = atoi(strtok_r(dataInicio,"/",&temp));
    int mesInicio = atoi(strtok_r(NULL      ,"/",&temp));
    int anoInicio = atoi(strtok_r(NULL      ,"/",&temp));
    int diaFim    = atoi(strtok_r(dataFim   ,"/",&temp));
    int mesFim    = atoi(strtok_r(NULL      ,"/",&temp));
    int anoFim    = atoi(strtok_r(NULL      ,"/",&temp));

    double precoAtual=0;
    double divide=0;

    for (int i = 0; i < hashMaxRides; i++) {
        char *data=lookupDateRides(i);

        int diaAtual ,mesAtual ,anoAtual;
        paraInt(data,&diaAtual,&mesAtual,&anoAtual);
        free(data);


        if(anoFim < anoAtual || anoInicio > anoAtual){
            continue;
        }

        else if (anoInicio < anoAtual && anoAtual < anoFim){
            precoAtual += valor(i);
            divide++;
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
                    divide++;
                }
            }
        }
    }
    return (precoAtual/divide);
}

double valor(int id){
    char *idR      = lookupDriverRides  (id);
    int distancia  = lookupDistanceRides(id);

    double retorna = precoViagem(distancia, idR);
    free(idR);

    return retorna;
}

void paraInt (char *string,int *diaAtual,int *mesAtual ,int *anoAtual ){
    char *temp;

    char *diaAtualS = strtok_r(string, "/" , &temp);
    char *mesAtualS = strtok_r(NULL  , "/" , &temp);
    char *anoAtualS = strtok_r(NULL  , "\0", &temp);
    *diaAtual       = atoi(diaAtualS);
    *mesAtual       = atoi(mesAtualS);
    *anoAtual       = atoi(anoAtualS);

    free(diaAtual);
}