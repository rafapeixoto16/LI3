#include "../includes/interacaoMenu.h"
#include "../includes/printMenu.h"
#include "stdlib.h"
#include <stdio.h>
#include "../includes/parsing.h"
#include <unistd.h>
#include "../includes/funcoesMenu.h"
#include "../includes/freeDataset.h"



// --------------------------------------------
// opcoes
// --------------------------------------------

void opcoes(){
    char *dataset;

    while (true){
        clear_screen();
        char datasets[250];
        char stringD[262];
        char stringU[250];
        char stringR[250];
        printf("Insira o caminho (path) para os Dataset's: \n");
        scanf("%s",datasets);
        snprintf (stringD,262,"%s%s",datasets,"/drivers.csv");
        snprintf (stringR,250,"%s%s",datasets,"/rides.csv");
        snprintf (stringU,250,"%s%s",datasets,"/users.csv");

        if(exists(stringD) && exists(stringU) && exists(stringR)){
            clear_screen();
            printf("Path valido\n");
            sleep(1);
            dataset = strdup(datasets);
            break;
        }
        else{
            printf("Path invalido\n");
            sleep(1);
        }
    }

    clear_screen();

    //parsing do buffer
    ARRAYDinamico driver1  = arrayCreate((int)tamanhoInicialD, Driver);
    ARRAYDinamico ride1    = arrayCreate((int)tamanhoInicialR, Ride  );
    ARRAYDinamico user1    = arrayCreate((int)tamanhoInicialU, User  );
    parsing(dataset, ride1, driver1, user1);

    //parsing Status
    ARRAYDinamico statusU1 = arrayCreate((int)tamanhoInicialU, StatusUser);
    ARRAYDinamico statusD1 = arrayCreate((int)tamanhoHash(driver1),StatusDriver);
    parsingStatus(ride1,statusD1,statusU1,driver1,user1);

    //ordenaçao array rides
    ordena(ride1);

    free(dataset);

    char opcao = 0;
    char *arrayString[tamanhoArrayPaginacao];

    while(true){
        clear_screen();
        displayMenu();
        printPaginacao();
        scanf("%c", &opcao);
        char *retorno = NULL;
        switch (opcao) {
            case '1':
            {
                char string[BUFSIZ];
                clear_screen();
                printf("Insira o id do driver ou o username do User: ");
                scanf("%s", string);
                retorno = query1(string,driver1,user1,statusD1,statusU1);
                clear_screen();
                printUpper();

                if(retorno != NULL)
                    printf("      Resultado: %s",retorno);
                else
                    errorMsg(1);

                printLinha(18);
                printVoltar();
                funcaoVoltar();

                clear_screen();
                break;
            }
            case '2':{
                int i;
                clear_screen();
                printf("Insira a quantidade de condutores: ");
                scanf("%i", &i);
                retorno = query2(i,statusD1,driver1);
                clear_screen();
                string4Array(arrayString, retorno);
                printf("\n");

                if(retorno != NULL)
                    paginacao(arrayString);

                freeArray(arrayString);
                free(retorno);
                clear_screen();

                break;
            }
            case '3':{
                int i;
                clear_screen();
                printf("Insira a quantidade de utilizadores: ");
                scanf("%i", &i);
                retorno = query3(i,statusU1,user1);
                clear_screen();
                string4Array(arrayString,retorno);
                printf("\n");

                if(retorno!=NULL)
                    paginacao(arrayString);

                freeArray(arrayString);
                free(retorno);
                clear_screen();

                break;
            }
            case '4':{
                char cidade[BUFSIZ];
                clear_screen();
                printf("Insira o nome da cidade: \n");
                scanf("%s",cidade);
                funcaoCidade(cidade);
                clear_screen();
                double retornoV = query4(cidade,ride1,driver1);
                printUpper();

                if(retornoV != -1.0)
                    printf("      Resultado: %.3f\n",retornoV);

                else
                    errorMsg(4);

                printLinha(17);
                printVoltar();
                funcaoVoltar();
                clear_screen();

                break;
            }
            case '5':{
                clear_screen();
                char *dataInicio = dataMenu("Insira a data de inicio na forma DD/MM/AAAA: ");
                clear_screen();
                char *dataFim    = dataMenu("Insira a data de termino na forma DD/MM/AAAA: ");
                double retornoV  = query5(dataInicio,dataFim,ride1,driver1);
                free(dataInicio);
                free(dataFim);
                clear_screen();
                printUpper();

                if(retornoV != (-1))
                    printf("      Resultado: %.3f\n",retornoV);
                else
                    errorMsg(5);

                printLinha(17);
                printVoltar();
                funcaoVoltar();
                clear_screen();

                break;
            }
            case '6':{
                char cidade[BUFSIZ];
                char *lixo;
                clear_screen();
                printf("Insira o nome da cidade: \n");
                scanf("%s", cidade);
                printf("\n");
                clear_screen();
                char *cidadeQueries = strdup(strtok_r(cidade,"\n",&lixo));
                funcaoCidade(cidadeQueries);
                char *dataInicio = dataMenu("Insira a data de inicio na forma DD/MM/AAAA: ");
                clear_screen();
                char *dataFim    = dataMenu("Insira a data de termino na forma DD/MM/AAAA: ");
                double retorno2 = query6(cidadeQueries,dataInicio,dataFim,ride1);
                clear_screen();
                printUpper();

                if(retorno2!=-1)
                    printf("      Resultado: %.3f\n",retorno2);
                else
                    errorMsg(6);

                printLinha(17);
                printVoltar();
                funcaoVoltar();
                clear_screen();
                free(cidadeQueries);
                break;
            }
            case '7':{
                clear_screen();
                printUpper();
                printf("     Não está implementada.\n");
                sleep(2);

                clear_screen();
                break;
            }
            case '8':{
                int idade;
                clear_screen();
                bool generoBool = generoMenu();
                clear_screen();
                printf("Insira a idade dos perfies: \n");
                scanf("%i",&idade);
                retorno = query8(generoBool,idade,ride1,user1,driver1);
                clear_screen();
                string4Array(arrayString, retorno);
                printf("\n");
                if(arrayString[0]!=NULL)
                    paginacao(arrayString);
                else {
                    printUpper();
                    errorMsg(8);
                    printLinha(5);
                    printVoltar();
                    funcaoVoltar();
                }
                freeArray(arrayString);
                free(retorno);

                break;
            }
            case '9':{
                clear_screen();
                char *dataInicio  = dataMenu("Insira a data de inicio na forma DD/MM/AAAA: ");
                clear_screen();
                char *dataFim     = dataMenu("Insira a data de termino na forma DD/MM/AAAA: ");
                int dataInicioInt = data2Int(dataInicio);
                int dataFimInt    = data2Int(dataFim);
                free(dataInicio);
                free(dataFim);
                retorno   = query9(dataInicioInt,dataFimInt,ride1);
                clear_screen();
                string4Array(arrayString, retorno);
                printf("\n");
                if(arrayString[0]!=NULL)
                    paginacao(arrayString);
                else {
                    printUpper();
                    errorMsg(9);
                    printLinha(5);
                    printVoltar();
                    funcaoVoltar();
                }
                freeArray(arrayString);
                free(retorno);
                clear_screen();

                break;
            }
            case 'c': case 'C': {
                clear_screen();
                printCreditos();


                while(true){
                    char termina;
                    scanf("%c",&termina);

                    if(termina == 'v' || termina == 'V')
                        break;
                }
                clear_screen();

                break;
            }
            case 'q': case 'Q':{
                clear_screen();
                freeDataset(driver1,ride1,user1,statusD1,statusU1);
                sleep(2);
                clear_screen();
                exit(0);
            }

            default:{
                printf("Essa query nao existe.\n");}
                break;
        }
        clear_screen();
    }
}
