#include "../includes/queries.h"

// --------------------------------------------
// parsingQueries
// --------------------------------------------


char *parsingQueries(char *linhaQ,ARRAYDinamico driver ,ARRAYDinamico user ,ARRAYDinamico ride, ARRAYDinamico statusD ,ARRAYDinamico statusU){
    char *save,*string;

    int  query = atoi(strtok_r(linhaQ," ",&save));
    char copia[250];

    switch(query){

        case 1:
        {
            char *id=strtok_r(NULL,"\n",&save);
            char *retorno = query1(id, driver, user, statusD, statusU);
            string = retorno;
            break;
        }

        case 2:
        {
            int numero    = atoi(strtok_r(NULL,"\n",&save));
            char *retorno = query2(numero,statusD,driver);
            string        = retorno;
            break;

        }

        case 3:
        {
            int numero       = atoi(strtok_r(NULL,"\n",&save));
            char *retorno    = query3(numero,statusU, user);
            string = retorno;
            break;
        }

        case 4:
        {
            char *cidade     = save;
            double retorno   = query4(cidade,ride,driver);
            if(retorno != -1){
                snprintf(copia, 250, "%.3f\n", retorno);
                string = strdup(copia);
            } else
                string = NULL;
            break;
        }

        case 5:{
            char *dataInicio = strtok_r(NULL," ",&save);
            char *dataFim    = strtok_r(NULL,"\n",&save);

            double retorno   = query5(dataInicio,dataFim,ride,driver);
            if (retorno != -1)
            {
                snprintf(copia, 250, "%.3f\n", retorno);
                string = strdup(copia);
            }
            else
                string = NULL;
            break;
        }

        case 6:{
            char *cidade     = strtok_r(NULL," ",&save);
            char *dataInicio = strtok_r(NULL," ",&save);
            char *dataFim    = strtok_r(NULL,"\n",&save);

            double retorno   = query6(cidade,dataInicio,dataFim,ride);
            if(retorno != -1){
                snprintf(copia,250,"%.3f\n",retorno);
                string= strdup(copia);
            } else
                string = NULL;
            break;
        }
        /*
            case 7:{
                //query7
            }
        */

        case 8:{
            char *genero   = strtok_r(NULL," ",&save);
            toLowerString(genero);
            int idadeConta  = atoi(strtok_r(NULL,"\n",&save));
            bool generoBool = strcmp("m", genero) == 0 ? true : false;
            char *retorno   = query8(generoBool,idadeConta,ride,user,driver);
            string = retorno;
            break;
        }

        case 9:{
            char *dataInicio = strtok_r(NULL," ",&save);
            char *dataFim    = strtok_r(NULL," ",&save);
            char *retorno= query9(data2Int(dataInicio),data2Int(dataFim),ride);
            string =retorno;
            break;
        }

        default:
            string = NULL;
            break;
    }
    return string;
}
