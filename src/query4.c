#include "../includes/queries.h"

// --------------------------------------------
// query4
// --------------------------------------------


double query4 (char *cidade,ARRAYDinamico rides,ARRAYDinamico driver)
{
// Medição de tempo
    /*clock_t start, end;
    double cpu_time_used;
    start = clock();
*/
    double divide = 0, valor = 0;
    char *lixo;
    cidade = strtok_r(cidade,"\n",&lixo);

    int tamanho = tamanhoOcupadoArray(rides);

    for (int i = 0; i < tamanho; i++)
    {
        if(posicaoTableRides(rides,i)) {
            char *cidadeAtual = lookupCidadeRides(posicaoTableRides(rides, i));

            if (strcmp(cidadeAtual, cidade) == 0) {
                char *id = lookupDriverRides(posicaoTableRides(rides, i));
                int distancia = lookupDistanceRides(posicaoTableRides(rides, i));
                valor += precoViagem(distancia, posicaoTableD(driver, id));
                divide++;

                free(id);
            }
            free(cidadeAtual);
        }
    }

  // Medição de tempo
   /* end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Fim da Q4 - %f segundos \n", cpu_time_used);
*/
    return divide == 0 ? -1 : (valor/divide);
}
