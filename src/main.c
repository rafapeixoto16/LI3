#include <stdio.h>
int main (){
    printf("aqui");
    FILE *fpDrivers;
    fpDrivers = fopen ("dataset/drivers.cvs","r");
    char linha[500];
    int n =fgets(linha,500,fpDrivers);
    if (n!=NULL)
        printf("d");
    return 0;
}