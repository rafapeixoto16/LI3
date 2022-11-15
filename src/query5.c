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

        char  *diaAtualSq5 = strtok_r(data, "/" , &temp);
        char  *mesAtualSq5 = strtok_r(NULL, "/" , &temp);
        char  *anoAtualSq5 = strtok_r(NULL, "\0", &temp);

        int diaAtualq5 = atoi(diaAtualSq5);
        int mesAtualq5 = atoi(mesAtualSq5);
        int anoAtualq5 = atoi(anoAtualSq5);



        if(anoFim<anoAtualq5 || anoInicio>anoAtualq5){
            continue;
        }

        else if (anoInicio < anoAtualq5 && anoAtualq5 < anoFim){
            precoAtual += valor(i);
            divide++;
        }

        else if (anoInicio==anoAtualq5){
            if(mesInicio > mesAtualq5)
                ;

            else if(mesInicio<mesAtualq5) {
                precoAtual += valor(i);
                divide++;
            }

            else if(mesInicio==mesAtualq5){
                if(diaInicio>diaAtualq5)
                    ;

                else{
                    precoAtual += valor(i);
                    divide++;
                }
            }
        }


        else {

            if(mesFim < mesAtualq5)
                    ;

            else if(mesFim > mesAtualq5) {
                precoAtual += valor(i);
                divide++;
            }

            else if(mesInicio==mesAtualq5){
                if(diaFim<diaAtualq5)
                    ;

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
    char *idR     = lookupDriverRides  (id);
    int distancia = lookupDistanceRides(id);
    return precoViagem(distancia, idR);
}

