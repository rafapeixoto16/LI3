#include "../includes/queries.h"


char *query9(int dataInicio,int dataFim, ARRAYDinamico rides) {

    //Medição de tempo
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    int primeiraData = lookupDateRides(posicaoTableRides(rides, 0));
    int ultimaData = lookupDateRides(posicaoTableRides(rides, tamanhoOcupadoArray(rides) - 1));

    verificaDataQueries(&dataInicio, &dataFim, &primeiraData, &ultimaData);

    if (dataInicio == -1 || dataFim == -1)
        return NULL;


    ARRAYDinamico print = arrayCreate(5000, Ride);
    hashInitNull(print, 0);

    int tamanhoUsado = tamanhoOcupadoArray(rides);

    for (int i = procuraPosicaoInicial(rides, dataInicio);
         i < tamanhoUsado && lookupDateRides(posicaoTableRides(rides, i)) <= dataFim; i++) {
        if (lookupTipRides(posicaoTableRides(rides, i)) > 0) {
            arrayAdd(print, posicaoTableRides(rides, i), NULL);
        }
    }
    int tamanhoUsadoPrint = tamanhoOcupadoArray(print);
    quicksortDistanciaViagens(array(print), tamanhoUsadoPrint);

    for (int i = 0; i < tamanhoUsadoPrint; i++) {
        int intI = i;
        int tamanho = 1;
        for (; intI < tamanhoOcupadoArray(print) &&
               lookupDistanceRides(posicaoTableRides(print,i)) == lookupDistanceRides(posicaoTableRides(print,intI)); intI++, tamanho++);
        quicksortData(arrayPosicao(print,i), tamanho - 1);
        i = intI - 1;
    }


    for (int i = 0; i < tamanhoUsadoPrint; i++) {
        int menor = i;
        for (int intI = i;
             intI < tamanhoUsadoPrint && lookupDistanceRides(posicaoTableRides(print,i)) == lookupDistanceRides(posicaoTableRides(print,intI)) &&
             lookupDateRides(posicaoTableRides(print,i)) == lookupDateRides(posicaoTableRides(print,intI)); intI++) {
            char *viagemI = lookupIdViagem(posicaoTableRides(print,menor));
            char *viagemInt = lookupIdViagem(posicaoTableRides(print,intI));

            if ( atoi(viagemI) >  atoi(viagemInt))
                menor = intI;

            free(viagemInt);
            free(viagemI);
        }
        swap(print,i,menor);
    }

    char *output1 = malloc(250 * tamanhoUsadoPrint * sizeof(char));
    output1[0] = '\0';
    char copia1[250];

    for (int i = tamanhoUsadoPrint - 1; i >= 0; i--) {
        double valorGorjeta = lookupTipRides(posicaoTableRides(print,i));
        char *cidade = lookupCidadeRides(posicaoTableRides(print,i));
        char *idViagem = lookupIdViagem(posicaoTableRides(print,i));
        int distancia = lookupDistanceRides(posicaoTableRides(print,i));
        char *dataViagem = int2Data(lookupDateRides(posicaoTableRides(print,i)));

        snprintf(copia1, 250, "%s;%s;%i;%s;%.3f\n",
                 idViagem,
                 dataViagem,
                 distancia,
                 cidade,
                 valorGorjeta);

        strcat(output1, copia1);
        free(dataViagem);
        free(idViagem);
        free(cidade);
    }
    arrayFree(print);
    free(print);

    // Medição de tempo
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Fim da Q9 - %f segundos \n", cpu_time_used);

    return output1;
}