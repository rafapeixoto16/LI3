//
// Created by rafael on 04-11-2022.
//

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
 * Funçao hash que atribui uma posiçao na tabela dependendo do id.
 * @param id Id do condutor (driver).
 * @return Retorna o indice da posiçao na hashtable.
 */

unsigned int hashDrivers(char *id);

/*!
 * Inicializa a hashtabela com todas as posiçoes a NULL.
 */

void initHashTableDrivers();

/*!
 * Da print a todos os elementos da hashtable do condutores (drivers).
 */

void printTableDrivers();

/*!
 * Esta funçao cria um objeto do tipo *DRIVERS e depois adiciona-o a hashtable.
 * @param linha Recebe um linha com toda a informação do condutor (driver).
 */

void driversParsing(char *linha);

/*!
 * Busca um condutor.
 * @param id Id do condutor (drivers).
 * @return Retorna um DRIVERS.
 */

DRIVERS hashTableLookupDrivers(char *id);

/*!
 * Da print de um driver.
 * @param drivers DRIVERS a dar print.
 */

void printDriver(DRIVERS drivers);

/*!
 * Procura um condutor (drivers) com o seu id.
 * @param i Id do condutor
 * @return re
 */
//nao usada
char *lookupDrivers(char *i);

/*!
 * Calcula o preço de viagem.
 * @param distancia Distancia em Km.
 * @param id Id do condutor.
 * @return
 */

double precoViagem(int distancia,char *id);

/*!
 * Adiciona um condutor (driver) a hashtable.
 * @param driver Condutor (driver) a ser adicionado.
 * @return Retorna True se conseguio adicionar o condutor (driver),False se nao conseguio.
 */

bool hashTableInsertDrivers(DRIVERS driver);

/*!
 * Função que dá os status de um determinado condutor
 * @param id ID do condutor
 * @return Retorna os status do condutor
 */

char *lookupStatusDriver(char *id);

/*!
 * Função que dá o nome de um determinado condutor
 * @param id ID do condutor
 * @return Retorna o nome do condutor
 */

char *lookupNomeDriver(char *id);

/*!
 * Função que dá o genero do condutor
 * @param id ID do condutor
 * @return Retorna o genero do condutor
 */

char *lookupGeneroDriver(char *id);

/*!
 * Função que dá a idade do condutor
 * @param id ID do condutor
 * @return Retorna a idade do condutor
 */

int lookupIdadeDriver(char *id);

#endif //LI3_DRIVERS_H
