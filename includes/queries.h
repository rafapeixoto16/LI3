#pragma once

#include "rides.h"
#include "users.h"
#include "drivers.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "time.h"
#include "../includes/array.h"


/*!
 * Função que recebe uma linha e redireciona para a query predendida.
 * @param linhaQ A linha.
 * @return Retorna o resultado da query.
 */

char *parsingQueries(char *linhaQ,ARRAYDinamico driver ,ARRAYDinamico user ,ARRAYDinamico ride, ARRAYDinamico statusD ,ARRAYDinamico statusU);

/*!
 * Função que recebe um id e lista o resumo do perfil.
 * @param id O id (username ou id).
 * @return Retorna os dados do utilizador(user) ou condutor(driver)
 */

char *query1(char *id,ARRAYDinamico driver ,ARRAYDinamico user , ARRAYDinamico statusD ,ARRAYDinamico statusU);

/*!
 * Função que recebe um numero, a tabela  drivers e os seus dados.
 * @param numero Numero de condutores.
 * @param statusD Dados do condutor.
 * @param driver Tabela dos condutores.
 * @return Lista os N condutores com maior avaliação média.
 */

char *query2 (int numero,ARRAYDinamico statusD,ARRAYDinamico driver);

/*!
 * Função que recebe um numero, a tabela dos users e os seus dados.
 * @param numero Numero de users.
 * @param statusU Dados do user.
 * @param user Tabela dos users.
 * @return Lista os N utilizadores com maior distancia viajada.
 */

char *query3(int numero, ARRAYDinamico statusU, ARRAYDinamico user);

/*!
 * Esta função vai á hashtable de "corridas" (rides) e procura na hashtable as ocorrências da cidade e faz o valor medio gasto (sem tips).
 * @param cidade Nome da cidade.
 * @param rides Tabela das corridas.
 * @param driver Tabela dos condutores.
 * @return Dá return da média de dinheiro gasto na aquela cidade.
 */
double query4 (char *cidade,ARRAYDinamico rides,ARRAYDinamico driver);

/*!
 * Esta função vai á hashtable de "corridas" (rides) e faz o valor médio das viagens efetuadas no intervalo de tempo dado (sem tips).
 * @param dataInicio Primeira data.
 * @param dataFim Segunda data.
 * @param ride Tabela das corridas.
 * @param driver Tabela dos condutores.
 * @return Dá return do preço médio das viagens efetuadas no intervalo dado.
 */
double query5(char *dataInicio, char *dataFim, ARRAYDinamico ride,ARRAYDinamico driver);

/*!
 * Esta função compara a cidade dada com as cidades de cada indice da hashtable e calcula a média da distância percorrida no intervalo de tempo dado.
 * @param cidade A cidade (city).
 * @param dataInicio Primeira data.
 * @param dataFim Segunda data.
 * @return Retorna a distância média percorrida numa dada cidade (city) num dado intervalo de tempo.
 */

double query6 (char *cidade,char *dataInicio,char *dataFim,ARRAYDinamico ride);

/*!
 * Recebe o genero e idade dos perfis e lista as viagens nas quais ambos o user e driver correpondem.
 * @param genero Genero do pretendido.
 * @param idade Idade dos perfis.
 * @param ride Tabela das corridas.
 * @param user Tabela dos users.
 * @param driver Tabela dos condutores.
 * @return Lista todas as viagens nas quais o user e o condutor sao do mesmo genero e têm perfis com x ou mais anos.
 */

char *query8(bool genero,int idade,ARRAYDinamico ride,ARRAYDinamico user,ARRAYDinamico driver);

/*!
 * Recebe um intervalo de datas e lista as viagens onde o user deu gorjeta.
 * @param dataInicio Primeira data.
 * @param dataFim Segunda data.
 * @param rides Tabela das corridas
 * @return Lista as viagens nas quais o user deu gorjeta.
 */

char *query9(int dataInicio,int dataFim, ARRAYDinamico rides);

