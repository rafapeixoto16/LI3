#include "../includes/parsingInput.h"
#include "../includes/queries.h"
#include <stdio.h>
#include <sys/stat.h>

// --------------------------------------------
// parsingInput
// --------------------------------------------


void parsingInput(char *input,ARRAYDinamico driver ,ARRAYDinamico user ,ARRAYDinamico ride, ARRAYDinamico statusD ,ARRAYDinamico statusU){
    char linha[300];
    char nomeFile[300];
    int contador = 1;

    FILE *fpInput= fopen(input,"r");

    while (fgets(linha, 300 ,fpInput ) != NULL) {

        char *retorno = parsingQueries(linha, driver , user ,ride, statusD , statusU);

        // Create dir if it does not exists
        struct stat st = {0};

        if (stat("Resultados", &st) == -1) {
            mkdir("Resultados", 0700);
        }

        if(retorno != NULL) {
            snprintf(nomeFile, 250, "%s%i%s", "Resultados/command", contador, "_output.txt");
            FILE *fileopen = fopen(nomeFile, "w");
            fprintf(fileopen, "%s", retorno);
            fclose(fileopen);
            free(retorno);
        }

        else {
            snprintf(nomeFile, 250, "%s%i%s", "Resultados/command", contador, "_output.txt");
            FILE *fileopen = fopen(nomeFile, "w");
            fclose(fileopen);
        }
        contador++;
    }
    fclose(fpInput);
}