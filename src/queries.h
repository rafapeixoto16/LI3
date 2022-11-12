//
// Created by rafael on 06-11-2022.
//

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



char *parsingQueries(char *linhaQ);


void query1(char *id,char *retorno);

/*!
 * Esta funçao vai a hashtable de "corridas" (rides) e procura na hashtable as ocorrencias da cidade e faz o valor medio gasto (sem tips).
 * @param cidade Nome da cidade a procurar.
 * @return Da return da media de dinheiro gasto na aquela cidade.
 */

double query4(char *cidade);


double query5(char *dataInicio,char *dataFim);
double valor(int id);

double query6(char *cidade,char *dataInicio,char *dataFim);
#endif //LI3_QUERIES_H
