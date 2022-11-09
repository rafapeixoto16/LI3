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
 * @param ride Elemento a inserir
 * @return Retorna falso se não conseguir inserir na hashtable e verdadeiro caso consiga
 */

bool hashTableInsertRides(RIDES ride);

/*!
* Função que procura por um dado condutor (driver).
* @param id Id do condutor esperado.
* @return Dados da corrida (ride).
*/

RIDES hashTableLookupRides(char *id);

/*!
* Função que cria um objeto do tipo *RIDES e adiciona-o á hashtable
* @param linha Dados da corrida (ride).
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
* @param i Posição na hashtable.
* @return Retorna o id do condutor (driver)
*/

char *lookupDriverRides(int i);

/*!
* Função que retorna verdadeiro ou falso.
* @param i Posição na hashtable.
* @param cidade Uma cidade.
* @return Retorna true se a cidade na posição da hash table é igual á do input.
*/

bool lookupCidadeRides(int i ,char *cidade);


#endif