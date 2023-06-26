#include "../includes/freeDataset.h"
#include "time.h"

// --------------------------------------------
// freeDataset
// --------------------------------------------


void freeDataset(ARRAYDinamico driver, ARRAYDinamico ride, ARRAYDinamico user,ARRAYDinamico statusD,ARRAYDinamico statusU){
    clock_t start, end;
    double cpu_time_used;

    printf("\n");

    start = clock();
    arrayDelete (driver);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("FreeDataset do Driver - %f segundos \n", cpu_time_used);

    start = clock();
    arrayDelete (ride);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("FreeDataset das Viagens - %f segundos \n", cpu_time_used);

    start = clock();
    arrayDelete (user);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("FreeDataset do User - %f segundos \n", cpu_time_used);

    start = clock();
    arrayDelete (statusU);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("FreeDataset do status do User - %f segundos \n", cpu_time_used);

    start = clock();
    arrayDelete (statusD);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("FreeDataset do status do Driver - %f segundos \n", cpu_time_used);

}