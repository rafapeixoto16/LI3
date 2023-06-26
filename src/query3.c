#include "../includes/queries.h"

// --------------------------------------------
// query3
// --------------------------------------------

char *query3(int numero, ARRAYDinamico statusU, ARRAYDinamico user){
    // Medição de tempo
    /*clock_t start, end;
    double cpu_time_used;
    start = clock();
    */char *retorno = NULL;

    if(numero > tamanhoOcupadoArray(statusU))
        numero = tamanhoOcupadoArray(statusU);

    if(numero > 0 && numero <= tamanhoOcupadoArray(statusU))
    {
        int tamanho = tamanhoOcupadoArray(statusU),tamanhoOcupado = 0;
        statusUSER array[tamanho];
        int tamanhoHashTable = tamanhoHash(statusU);

        for (int i = 0; i < tamanhoHashTable && tamanhoOcupado < tamanho; i++) {
            if(posicaoTableSUsersIndex(statusU,i) != NULL) {
                setPointer(posicaoTableSUsersIndex(statusU,i));
                statusUSER user1 = lookupMaisRecenteVisitado(posicaoTableSUsersIndex(statusU,i));
                while (user1 != NULL && tamanhoOcupado < tamanho) {
                    array[tamanhoOcupado] = user1;
                    tamanhoOcupado++;
                    avancaRecenteVisitado(user1);
                    user1 = lookupMaisRecenteVisitado(user1);
                }
            }
        }

        quicksortDistanciaUser(array,tamanho);

        for (int j = 0; j < tamanho; j++) {
            int intI = j;
            int tamanhoQ = 1;
            for(;intI < tamanho && lookupDistanciaUser(array [j]) == lookupDistanciaUser(array[intI]);intI++,tamanhoQ++);
            quicksortViagemMRecente(array+j,tamanhoQ-1);
            j=intI-1;
        }

        for (int l = 0; l < tamanho; l++) {
            int maior = l;
            for (int intI = l; intI < tamanho && lookupDistanciaUser(array[l]) == lookupDistanciaUser(array[intI]) &&
                               lookupViagemMRUser(array[l]) == lookupViagemMRUser(array[intI]); intI++) {
                char *usernameMenor  = lookupUsernameUser(array[maior]);
                char *usernamePosicaoUser = lookupUsernameUser(array[intI]);

                if (strcmp(usernameMenor,usernamePosicaoUser) > 0)
                    maior = intI;

                free(usernameMenor);
                free(usernamePosicaoUser);
            }

            statusUSER tmp = array[l];
            array[l] = array[maior];
            array[maior] = tmp;
        }

        char *output1 = malloc(500 * numero * sizeof(char));
        output1[0] = '\0';
        char copia1[250];

        for(int i = 0; i < numero; i++){
            char *id   = lookupIDcharStatusUser(array[i]);
            char *nome = lookupNomeUser(posicaoTableU(user,id),id);
            int distancia = lookupDistanciaUser(array[i]);

            snprintf(copia1, 250, "%s;%s;%i\n",
                     id,
                     nome,
                     distancia);

            free(id);
            free(nome);
            strcat(output1, copia1);
        }
        retorno = output1;
    }

    // Medição de tempo
    /*end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Fim da Q3 - %f segundos \n", cpu_time_used);
    */return retorno;
}