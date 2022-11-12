//
// Created by rafael on 11-11-2022.
//

#include "parsingInput.h"
#include "queries.h"
#include <stdio.h>

void parsingInput(char *input){
    char linha[250];
    char nomeFile[250];
    int contador=1;

    FILE *fpInput= fopen(input,"r");

    while (fgets(linha, 250,fpInput ) != NULL) {

        char *retorno = parsingQueries(linha);
        if(retorno!=NULL) {
            snprintf(nomeFile, 250, "%s%i%s", "resultados/command", contador, "_output");
            FILE *fileopen = fopen(nomeFile, "w");
            fprintf(fileopen, "%s", retorno);
            fclose(fileopen);
        }
        else{
            snprintf(nomeFile, 250, "%s%i%s", "resultados/command", contador, "_output.txt");
            FILE *fileopen = fopen(nomeFile, "w");
            fprintf(fileopen, "%s", "Ainda nao defenida");
            fclose(fileopen);
        }
        contador++;
    }
}