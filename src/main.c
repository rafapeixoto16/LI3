#include "../includes/interacaoMenu.h"
#include "../includes/interpretador.h"

// --------------------------------------------
// main
// --------------------------------------------


int main (int argc,char *argv[]){
    //Start
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    if(argc == 1)
        opcoes();

    if(argc == 3)
        interpretador(argv);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo Total: %f segundos \n", cpu_time_used);

    return 0;
}
