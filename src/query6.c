#include "../includes/queries.h"

// --------------------------------------------
// query6
// --------------------------------------------

double query6 (char *cidade,char *dataInicio,char *dataFim,ARRAYDinamico ride){

    // Medição de tempo
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    double distanciaAtual = 0.0;
    double divide = 0.0;

    int dataInicioInt = data2Int(dataInicio);
    int dataFimInt    = data2Int(dataFim);

    int primeiraData = lookupDateRides(posicaoTableRides(ride,0));
    int ultimaData   = lookupDateRides(posicaoTableRides(ride, tamanhoOcupadoArray(ride)-1));

    verificaDataQueries(&dataInicioInt,&dataFimInt,&primeiraData,&ultimaData);

    if(dataInicioInt == -1 || dataFimInt ==-1)
        return -1;

    int tamanho = tamanhoOcupadoArray(ride);

    for (int i = procuraPosicaoInicial(ride,dataInicioInt); i < tamanho && lookupDateRides(posicaoTableRides(ride,i))<=dataFimInt; i++) {
        int dataAtual = lookupDateRides(posicaoTableRides(ride, i));
        if (dataInicioInt <= dataAtual && dataAtual <= dataFimInt) {
            char *cidadeAtual = lookupCidadeRides(posicaoTableRides(ride, i));
            if(strcmp(cidade,cidadeAtual) == 0){
                distanciaAtual += lookupDistanceRides(posicaoTableRides(ride,i));
                divide++;
            }
            free(cidadeAtual);
        }
    }

    // Medição de tempo
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Fim da Q6 - %f segundos \n", cpu_time_used);

    return divide == 0 ? -1 : (double )(distanciaAtual / divide);
}