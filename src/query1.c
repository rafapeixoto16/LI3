#include "../includes/queries.h"
#include "time.h"


// --------------------------------------------
// query1
// --------------------------------------------


char *query1(char *id,ARRAYDinamico driver ,ARRAYDinamico user , ARRAYDinamico statusD ,ARRAYDinamico statusU){

    // Medição de tempo
    /*clock_t start, end;
    double cpu_time_used;
    start = clock();
*/
    char stringR[250];
    char *lixo;
    id = strtok_r(id,"\n",&lixo);

    int numero = 0;

    if(isdigit(id[0]))
        numero=1;


    if(numero == 1){
        bool status = lookupStatusDriver(posicaoTableD(driver,id));

        if (!status)
        {
            return NULL;
        }

        DRIVERS tmp = posicaoTableD(driver,id);

        if(tmp == NULL)
        {
            return NULL;
        }

        char *nome  = lookupNomeDriver(tmp);
        bool genero = lookupGeneroDriver(tmp);
        int  idade  = lookupIdadeDriver(tmp);

        if(!nome)
        {
            return NULL;
        }

        double avaliacao      = 0.000;
        int numeroViagens     = 0;
        double totalAuferido  = 0.000;

        informacoesBasicasStatusDriver(posicaoTableSdriver(statusD,id),&totalAuferido,&avaliacao,&numeroViagens);
        double avaliacaoMedia = (double) avaliacao / (double) numeroViagens;

        snprintf(stringR, 250, "%s;%s;%d;%.3f;%i;%.3f\n",
                 nome,
                 genero==true?"M":"F",
                 idade,
                 avaliacaoMedia,
                 numeroViagens,
                 totalAuferido);

        free(nome);

        return strdup(stringR);
    }

    else {
        int i =(int )strlen(id);
        id[i]='\0';
        USERS tmp   = posicaoTableU   (user,id);
        bool status = lookupStatusUser(tmp,id);

        if  (!status){
            return NULL;
        }
        if(tmp == NULL)
        {
            return NULL;
        }
        char *nome  = lookupNomeUser  (tmp,id);
        bool genero = lookupGeneroUser(tmp,id);
        int idade   = lookupIdadeUser (tmp,id);

        if(!nome){
            return NULL;
        }

        double avaliacao      = 0.000;
        int numeroViagens     = 0;
        double totalGasto     = 0.000;

        informacoesBasicasStatusUser(posicaoTableSusers(statusU,id),id,&totalGasto,&avaliacao,&numeroViagens);

        double avaliacaoMedia = (double) avaliacao / (double) numeroViagens;

        snprintf(stringR, 250, "%s;%s;%i;%.3f;%i;%.3f\n",
                 nome,
                 genero == true?"M":"F",
                 idade,
                 avaliacaoMedia,
                 numeroViagens,
                 totalGasto);

        free(nome);

    // Medição de tempo
        /*end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Fim da Q1 - %f segundos \n", cpu_time_used);
*/
        return strdup(stringR);
    }
}