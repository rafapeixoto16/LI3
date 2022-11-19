#ifndef LI3_DRIVERS_H
#define LI3_DRIVERS_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define hashMaxDrivers 10000

#define dataAniv (09/10/2022)

/*!
 * Informaçoes do condutor (driver).
 !*/

typedef struct driver *DRIVERS;

/*!
 * Função hash que atribui uma posiçao na tabela dependendo do id.
 * @param id Id do condutor (driver).
 * @return Retorna o indice da posiçao na hashtable.
 */

unsigned int hashDrivers(char *id);

/*!
 * Inicializa a hashtable com todas as posições a NULL.
 */

void initHashTableDrivers();

/*!
 * Dá print a todos os elementos da hashtable dos condutores (drivers).
 */

void printTableDrivers();

/*!
 * Esta função cria um objeto do tipo *DRIVERS e depois adiciona-o a hashtable.
 * @param linha Recebe um linha com toda a informação do condutor (driver).
 */

void driversParsing(char *linha);

/*!
 * Busca um condutor.
 * @param id Id do condutor (driver).
 * @return Retorna um DRIVERS.
 */

DRIVERS hashTableLookupDrivers(char *id);

/*!
 * Da print de um contutor (driver).
 * @param drivers DRIVERS a dar print.
 */

void printDriver(DRIVERS drivers);

/*!
 * Adiciona um condutor (driver) a hashtable.
 * @param driver Condutor (driver) a ser adicionado.
 * @return Retorna True se conseguiu adicionar o condutor (driver),False se nao conseguiu.
 */

bool hashTableInsertDrivers(DRIVERS driver);

/*!
 * Função que dá os status de um determinado condutor.
 * @param id ID do condutor (driver).
 * @return Retorna os status do condutor (driver).
 */

char *lookupStatusDriver(char *id);

/*!
 * Função que dá o nome de um determinado condutor (driver).
 * @param id ID do condutor (driver).
 * @return Retorna o nome do condutor (driver).
 */

char *lookupNomeDriver(char *id);

/*!
 * Função que dá o genero do condutor (driver).
 * @param id ID do condutor (driver).
 * @return Retorna o genero do condutor (driver).
 */

char *lookupGeneroDriver(char *id);

/*!
 * Função que dá a idade do condutor (driver).
 * @param id ID do condutor (driver).
 * @return Retorna a idade do condutor (driver).
 */

int lookupIdadeDriver(char *id);

/*!
 * Calcula o preço de viagem.
 * @param distancia Distância em Km.
 * @param id Id do condutor (driver).
 * @return Retorna o valor da viagem.
 */

double precoViagem(int distancia,char *id);

/*!
 * Liberta a memoria usada pelo "condutores" (Drivers).
 */

void freeDrivers ();

#endif //LI3_DRIVERS_H
