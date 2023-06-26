#include "../includes/queries.h"

// --------------------------------------------
// query5
// --------------------------------------------

double query5(char *dataInicio, char *dataFim, ARRAYDinamico ride,ARRAYDinamico driver) {
    // Medição de tempo
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    int dataInicioInt = data2Int(dataInicio);
    int dataFimInt = data2Int(dataFim);

    double precoAtual = 0.0;
    double divide = 0.0;

    int primeiraData = lookupDateRides(posicaoTableRides(ride,0));
    int ultimaData   = lookupDateRides(posicaoTableRides(ride, tamanhoOcupadoArray(ride)-1));

    verificaDataQueries(&dataInicioInt,&dataFimInt,&primeiraData,&ultimaData);

    if(dataInicioInt == -1 || dataFimInt ==-1)
        return -1;

    int tamanho = tamanhoOcupadoArray(ride);

    for (int i = procuraPosicaoInicial(ride,dataInicioInt); i < tamanho && lookupDateRides(posicaoTableRides(ride,i))<=dataFimInt; i++) {
        int dataAtual = lookupDateRides(posicaoTableRides(ride, i));

        if (dataInicioInt <= dataAtual && dataAtual <= dataFimInt) {
            char *id      = lookupDriverRides(posicaoTableRides(ride,i));
            int distancia = lookupDistanceRides(posicaoTableRides(ride,i));
            precoAtual   += precoViagem(distancia, posicaoTableD(driver,id));
            divide++;
            free(id);
        }
    }

    // Medição de tempo
     end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Fim da Q5 - %f segundos \n", cpu_time_used);

    return divide == 0? -1 : (precoAtual / divide);
}
