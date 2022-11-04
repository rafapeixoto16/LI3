#include <stdio.h>
int main (){
    printf("aqui");
    FILE *fpDrivers;
    fpDrivers = fopen ("../datasetfase1/drivers.csv","r");
    char linha [1000];
    fgets(linha,1000,fpDrivers);
    return 0;
}