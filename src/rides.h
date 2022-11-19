#ifndef RIDES_H
#define RIDES_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "drivers.h"

#define hashMaxRides 1000000

#define dataDia "9/10/2022"

/*!
* Define a struct ride.
*/

typedef struct ride *RIDES;

/*!
* Esta função transforma o id de string para um integer.
* @param id O id de condutor (driver).
* @return A localização na tabela.
*/

unsigned int hashRides(char *id);

/*!
* Função que inicia a hashtable com posições a NULL.
*/

void initHashTableRides();

/*!
* Função que dá print da hashtable com todos os seus elementos.
*/

void printTableRides();

/*!
 * Função que insere um novo elemento á hashtable.
 * @param ride Elemento a inserir.
 * @return Retorna falso se não conseguir inserir na hashtable e verdadeiro caso consiga.
 */

bool hashTableInsertRides(RIDES ride);

/*!
* Função que retorna verdadeiro ou falso.
* @param id Posição na hashtable.
* @return Retorna true se a cidade na posição da hash table é igual á do input.
*/

RIDES hashTableLookupRides(char *id);

/*!
* Função que cria um objeto do tipo *RIDES e adiciona-o á hashtable.
* @param linha Dados da corrida (ride).
*/

void ridesParsing(char *linha);

/*!
* Função que dá a distância de uma viagem.
* @param i Dados de um condutor (driver).
* @return Retorna o valor da distância.
*/

int lookupDistanceRides(int i);

/*!
* Função que dá uma determinada corrida (ride).
* @param i Posição na hashtable.
* @return Retorna o id do condutor (driver)
*/

char *lookupDriverRides(int i);

/*!
* Função que dá uma determinada cidade
* @param i Posição na hashtable.
* @return Retorna a cidade.
*/

char *lookupCidadeRides(int i);

/*!
 * Função dá uma determinada data
 * @param i Posição na hashtable
 * @return Retorna a data
 */

char *lookupDateRides(int i);

/*!
 *
 * @param id ID da corrida
 * @param avaliacaoMedia A avaliação média
 * @param numeroViagens Número de viagens
 * @param totalAuferido Valor gasto no total
 */

void lookupAvalNViagemTotAufDrivers(char *id,double *avaliacaoMedia,int *numeroViagens,double *totalAuferido);

/*!
 *
 * @param id ID da corrida
 * @param avaliacaoMedia A avaliação média
 * @param numeroViagens Número de viagens
 * @param totalGasto Valor gasto no total
 */

void lookupAvalNViagemTotGastoUser(char *id   ,double *avaliacaoMedia,int *numeroViagens,double *totalGasto);

/*!
 *Liberta a memoria usado pelas "corridas" (Rides).
 */

void freeRides ();

#endif