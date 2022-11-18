#ifndef LI3_QUERIES_H
#define LI3_QUERIES_H

#include "rides.h"
#include "users.h"
#include "drivers.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*!
 *
 * @param linhaQ
 * @return
 */

char *parsingQueries(char *linhaQ);

/*!
 *
 * @param id
 * @return
 */

char *query1(char *id);

/*!
 * Esta função vai á hashtable de "corridas" (rides) e procura na hashtable as ocorrências da cidade e faz o valor medio gasto (sem tips).
 * @param cidade Nome da cidade a procurar.
 * @return Dá return da média de dinheiro gasto na aquela cidade.
 */

double query4(char *cidade);

/*!
 * Esta função vai á hashtable de "corridas" (rides) e faz o valor médio das viagens efetuadas no intervalo de tempo dado (sem tips).
 * @param dataInicio Primeira data.
 * @param dataFim Segunda data.
 * @return Dá return do preço médio das viagens efetuadas no intervalo dado.
 */

double query5(char *dataInicio,char *dataFim);

/*!
 * Esta função recebe um ID e vai á hashtable pegar no id do condutor e na distância percorrida.
 * @param id Id do condutor (driver).
 * @return Retorna o preço da viagem de um condutor (driver).
 */

double valor(int id);

/*!
 * Esta função compara a cidade dada com as cidades de cada indice da hashtable e calcula a média da distância percorrida no intervalo de tempo dado.
 * @param cidade A cidade (city).
 * @param dataInicio Primeira data.
 * @param dataFim Segunda data.
 * @return Retorna a distância média percorrida numa dada cidade (city) num dado intervalo de tempo.
 */

double query6(char *cidade,char *dataInicio,char *dataFim);

/*!
 * Esta função converte os valores da data para inteiros.
 * @param string A data.
 * @param diaAtual O dia atual.
 * @param mesAtual O mês atual.
 * @param anoAtual O ano atual.
 */

void paraInt (char *string,int *diaAtual,int *mesAtual ,int *anoAtual );

#endif //LI3_QUERIES_H
