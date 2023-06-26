#include "../includes/queries.h"
#include "time.h"


// --------------------------------------------
// query2
// --------------------------------------------

char *query2(int numero, ARRAYDinamico statusD,ARRAYDinamico driver){
    // Medição de tempo
    /*clock_t start, end;
    double cpu_time_used;
    start = clock();
   */
   char *retorno = NULL;
   if(numero > tamanhoOcupadoArray(statusD))
       numero = tamanhoOcupadoArray(statusD);

    if(numero > 0 && numero <= tamanhoOcupadoArray(statusD)) {
        int tamanhoTable= tamanhoOcupadoArray(statusD);
        void* array[tamanhoTable];
        int index = 0;

        for (int i = 0; index < tamanhoTable; i++) {
            if (posicaoTableSdriverIndex(statusD,i) != NULL) {
                array [index] = posicaoTableSdriverIndex(statusD,i);
                index++;
            }
        }

        quicksortAvalMed(array,tamanhoTable);

        for (int j = 0; j < tamanhoTable; j++) {
            int intI = j;
            int tamanho = 1;
            for (; intI < tamanhoTable && lookupAvalMedDriver(array[j]) == lookupAvalMedDriver(array[intI]); intI++, tamanho++);
            quicksortDataDriver(array+j, tamanho-1);
            j = intI-1;
        }

        for (int j = 0; j < tamanhoTable; j++) {
            int intI = j;
            int tamanho = 1;
            for (; intI < tamanhoTable && lookupAvalMedDriver(array[j]) == lookupAvalMedDriver(array[intI]) &&
                   lookupDataStatusDriver(array[j]) == lookupDataStatusDriver(array[intI]); intI++, tamanho++);
            quicksortIdStatusDriver(array+j,tamanho-1);
            j = intI-1;
        }

        char *output1 = malloc(500 * numero * sizeof(char));
        output1[0] = '\0';
        char copia1[250];

        for (int i = 0; i < numero; i++) {
            char *id = lookupIDcharStatus(array[i]);
            char *nome = lookupNomeDriver(posicaoTableD(driver, id));
            double avaliacaoMedia = lookupAvalMedDriver(array[i]);

            snprintf(copia1, 250, "%s;%s;%.3f\n",
                     id,
                     nome,
                     avaliacaoMedia);
            free(id);
            free(nome);
            strcat(output1, copia1);
        }
        retorno = output1;
    }

    // Medição de tempo
    /*end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Fim da Q2 - %f segundos \n", cpu_time_used);
*/
    return retorno;
}
