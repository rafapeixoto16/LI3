#include <stdbool.h>
#include "../includes/queries.h"

char *query8(bool genero,int idade,ARRAYDinamico ride,ARRAYDinamico user,ARRAYDinamico driver){
    // Medição de tempo
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    ARRAYDinamico print = arrayCreate(2500,Ride);

    int tamanhoR = tamanhoOcupadoArray(ride);

    for (int i = 0; i < tamanhoR; i++)
    {
        char *username= lookupUserRides(posicaoTableRides(ride,i));
        char *id = lookupDriverRides(posicaoTableRides(ride,i));
        if(lookupStatusDriver(posicaoTableD(driver,id)) && lookupStatusUser(posicaoTableU(user,username),username))
        {
            if (lookupGeneroDriver(posicaoTableD(driver, id)) == lookupGeneroUser(posicaoTableU(user, username), username) && lookupGeneroUser(posicaoTableU(user, username), username) == genero)
            {
                int dataCriaUser   = lookupDatacriacaoUser(posicaoTableU(user, username), username);
                int dataCriaDriver = lookupDataCriacaoDriver(posicaoTableD(driver, id));

                if (calculaIdadeInt(dataCriaUser) >= idade && calculaIdadeInt(dataCriaDriver) >= idade)
                {
                    char *idViagem = lookupIdViagem(posicaoTableRides(ride,i));
                    arrayAdd(print, posicaoTableRides(ride, i), idViagem);
                }
            }
        }
        free(username);
        free(id);
    }

    quicksortDataCreationDriver(array(print),tamanhoOcupadoArray(print),driver);

    int tamanho = tamanhoOcupadoArray(print);

    for (int i = 0; i < tamanho-1; i++) {
        int menor = i;
        int idmenor = lookupDriverIntRides(posicaoTableRides(print,menor));
        int dataMenorAtual = lookupDataCriacaoDriver(posicaoTableDriverInt(driver,idmenor));

        for (int j = i; j < tamanho && dataMenorAtual == lookupDataCriacaoDriver(posicaoTableDriverInt(driver,lookupDriverIntRides(posicaoTableRides(print,j))));j++){
            char *nomeMenor1 = lookupUserRides(posicaoTableRides(print, menor));
            char *nomePosicaoJ1 = lookupUserRides(posicaoTableRides(print, j));

            if (lookupDatacriacaoUser(posicaoTableU(user, nomeMenor1), nomeMenor1) == lookupDatacriacaoUser(posicaoTableU(user, nomePosicaoJ1), nomePosicaoJ1)) {
                if (lookupIdViagemInt(posicaoTableRides(print, menor)) > lookupIdViagemInt(posicaoTableRides(print, j))) {
                    menor = j;
                }

            } else if (lookupDatacriacaoUser(posicaoTableU(user, nomeMenor1), nomeMenor1) > lookupDatacriacaoUser(posicaoTableU(user, nomePosicaoJ1), nomePosicaoJ1)) {
                menor = j;
            }

            free(nomePosicaoJ1);
            free(nomeMenor1);
        }
        swap(print,i,menor);
    }


    char *output1 = malloc(200 * tamanho * sizeof(char));
    output1[0] = '\0';
    char copia1[250];

    for (int i = 0; i < tamanho; i++) {
        RIDES posicaoAtual = posicaoTableRides(print,i);

        char *idDriver = lookupDriverRides(posicaoAtual);
        char *nomeDriver = lookupNomeDriver(posicaoTableD(driver,idDriver));
        char *username   = lookupUserRides(posicaoAtual);
        char *nomeUser   = lookupNomeUser(posicaoTableU(user,username),username);

        snprintf(copia1, 250, "%s;%s;%s;%s\n",
                 idDriver,
                 nomeDriver,
                 username,
                 nomeUser);
        free(idDriver);
        free(nomeDriver);
        free(username);
        free(nomeUser);
        strcat(output1, copia1);
    }

    arrayFree(print);
    free(print);

    // Medição de tempo
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Fim da Q8 - %f segundos \n", cpu_time_used);

    return output1;
}