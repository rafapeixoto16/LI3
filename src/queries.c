//
// Created by rafael on 06-11-2022.
//

#include "queries.h"

char *parsingQueries(char *linhaQ){
    char *save,*string;

    int query= atoi(strtok_r(linhaQ," ",&save));
    char copia[250];

    switch(query){

        /*case 1:{
            //query1
        }

        case 2:{
            //query2
        }

        case 3:{
            //query3
        }*/

        case 4:{
            char *cidade = strtok_r(NULL," ",&save);

            double retorno = query4(cidade);
            snprintf(copia,250,"%.3f",retorno);
            string= strdup(copia);
            break;
        }

        case 5:{
            char *dataInicio = strtok_r(NULL," ",&save);
            char *dataFim = strtok_r(NULL," ",&save);

            double retorno = query5(dataInicio,dataFim);
            snprintf(copia,250,"%.3f",retorno);
            string= strdup(copia);
            break;
        }

        case 6:{
            char *cidade = strtok_r(NULL," ",&save);
            char *dataInicio = strtok_r(NULL," ",&save);
            char *dataFim = strtok_r(NULL," ",&save);

            double retorno = query6(cidade,dataInicio,dataFim);
            snprintf(copia,250,"%.3f",retorno);
            string= strdup(copia);
            break;
        }

        /*case 7:{
            //query7
        }

        case 8:{
            //query8
        }

        case 9:{
            //query9
        }*/

        default:
            string= NULL;
            break;
    }
    return string;
}