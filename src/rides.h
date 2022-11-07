#ifndef RIDES_H
#define RIDES_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

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
* Função que dá print da hash table com todos os seus elementos.
*/
void printTableRides();

/*!
 * Função que insere um novo elemento á hashtable.
 * @param ride
 * @return
 */
bool hashTableInsertRides(RIDES ride);

/*!
* Função que procura por um dado condutor (driver).
* @param id Id do condutor esperado.
* @return Dados do condutor (driver).
*/
RIDES hashTableLookupRides(char *id);

/*!
* Função que
* @param linha Dados do condutor (driver).
*/
void ridesParsing(char *linha);

/*!
* Função que dá a distância de uma viagem.
* @param linha Dados de um condutor (driver).
* @return Retorna o valor da distância.
*/
int lookupDistanceRides(int i);

/*!
* Função que dá uma determinada corrida (ride).
* @param i
* @return
*/
char *lookupDriverRides(int i);

/*!
* Função que
* @param i
* @param cidade
* @return
*/
bool lookupCidadeRides(int i ,char *cidade);


#endif