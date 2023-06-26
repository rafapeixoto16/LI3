#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "drivers.h"

#define tamanhoInicialR 5000000

/*!
* Define a struct ride.
*/

typedef struct ride *RIDES;

/*!
 * Recebe uma linha com a informaçao do RIDE e adicona-a se for valida.
 * @param linha Linha com a infomaçao daquela ride.
 * @param Array Array Rides.
 */

void ridesParsing (char *linha,void* arrayD);

/*!
 * Função que dá a distância de uma viagem.
 * @param ride1 Dados de um condutor (driver).
 * @return Retorna o valor da distância.
 */

int lookupDistanceRides(RIDES ride1);

/*!
* Função que dá um driver de uma determinada corrida (ride).
* @param ride1 Indereço de uma RIDE.
* @return Retorna o id do condutor (driver).
*/

char *lookupDriverRides(RIDES ride1);

/*!
* Função que dá uma cidade de uma determinada corrida (ride).
* @param ride1 Indereço de uma RIDE.
* @return Retorna a cidade.
*/

char *lookupCidadeRides (RIDES ride1);

/*!
 * Função dá uma data de uma determinada corrida (ride).
 * @param ride1 Indereço de uma RIDE.
 * @return Retorna a data.
 */

int lookupDateRides (RIDES ride1);

/*!
 * Função que procura um user de uma determinada corrida (ride).
 * @param ride1 Indereço de uma RIDE.
 * @return Retorna o username.
 */

char *lookupUserRides (RIDES ride1);

/*!
 *Liberta a memoria usado pelas "corridas" (Rides).
 */

double lookupTipRides (RIDES ride1);

/*!
 * Função que retorna o score_user de uma determinada corrida (ride).
 * @param ride1 Indereço de uma RIDE.
 * @return O valor do score_user.
 */

double lookupScoreUserRides (RIDES ride1);

/*!
 * Função que retorna o score_driver de uma determinada corrida (ride).
 * @param ride1 Indereço de uma RIDE.
 * @return O valor do score_dirver.
 */

double lookupScoreDriverRides (RIDES ride1);


/*!
 * Função que procura o id de um condutor.
 * @param ride1 O condutor.
 * @return Retorna o id na forma de um inteiro.
 */

int lookupIdViagemInt(RIDES ride1);

/*!
 * Função que procura o id de uma viagem.
 * @param rides1 Posição na tabela.
 * @return Retorna o id da viagem.
 */

char *lookupIdViagem(RIDES rides1);

/*!
 * Retorna o id driver na forma de int.
 * @param ride1 Array ride.
 * @return Retorna o id do driver.
 */

int lookupDriverIntRides(RIDES ride1);

/*!
 * Função que verifica se o id da corrida é valido.
 * @param id O id da corrida(ride).
 * @param rides A ride a adicionar.
 * @return
 */

int idRide(char *id, RIDES rides);

/*!
 * Função que verifica se a data da corrida(ride) é valida.
 * @param data A data da corrida(ride).
 * @param rides A ride a adicionar.
 * @return
 */

int dataCorridaRide (char *data, RIDES rides);

/*!
 * Função que verifica se o id é do condutor é valido.
 * @param id O id do condutor.
 * @param rides A ride a adicionar.
 * @return Retorna 0 se o adicionar e 1 caso não o adicione.
 */

int idDriverRide (char *id, RIDES rides);

/*!
 * Função que verifica se o nome do utilizador é valido.
 * @param nome O nome do user.
 * @param rides A ride a adicionar.
 * @return Retorna 0 se o adicionar e 1 caso não adicione.
 */

int nomeUserRide(char *nome, RIDES rides);

/*!
 * Função que verifica se a cidade é valida.
 * @param cidade A cidade.
 * @param rides A ride a adicionar.
 * @return Retorna 0 se o adicionar e 1 caso não adicione.
 */

int cidadeRide(char *cidade, RIDES rides);

/*!
 * Função que verifica se a distancia é valida.
 * @param distancia A distancia.
 * @param rides A ride a adicionar.
 * @return Retorna 0 se a adicionar e 1 caso não adicione.
 */

int distanciaRide(char *distancia, RIDES rides);

/*!
 * Função que verifica se a avaliação do user é valida.
 * @param scoreU A avaliação do user.
 * @param rides A ride a adicionar.
 * @return Retorna 0 se a adicionar e 1 caso não adicione.
 */

int scoreUserRide(char *scoreU,RIDES rides);

/*!
 * Função que verifica se o avaliação do condutor(driver) é valida.
 * @param scoreD A avaliação do condutor(driver).
 * @param rides A ride a adicionar.
 * @return Retorna 0 se a adicionar e 1 caso não adicione.
 */

int scoreDriverRide(char *scoreD, RIDES rides);

/*!
 * Função que verifica se o valor da tip é valido.
 * @param tip A tip.
 * @param rides A ride a adicionar.
 * @return Retorna 0 se a adicionar e 1 caso não adicione.
 */

int tipRide(char *tip, RIDES rides);

/*!
 * Função que dá free à memoria utilizada pela ride.
 * @param ride Indereço de uma RIDE.
 */

void freeRide(RIDES ride);

/*!
 * Função que dá free à memoria utilizada pela ride.
 * @param rides Indereço de uma RIDE.
 */

void printRide(RIDES rides);

/*!
 * Função que dá free à memoria utilizada pela ride.
 * @param rides Indereço de uma RIDE.
 */

void freeRideId(RIDES rides);

/*!
 * Função que dá free à memoria utilizada pela ride.
 * @param rides Indereço de uma RIDE.
 */

void freeRideDate(RIDES rides);

/*!
 * Função que dá free à memoria utilizada pela ride.
 * @param rides Indereço de uma RIDE.
 */

void freeRideDriver(RIDES rides);

/*!
 * Função que dá free à memoria utilizada pela ride.
 * @param rides Indereço de uma RIDE.
 */

void freeRideUser(RIDES rides);

/*!
 * Função que dá free à memoria utilizada pela ride.
 * @param rides Indereço de uma RIDE.
 */

void freeRideCity(RIDES rides);

/*!
 * Função que dá free à memoria utilizada pela ride.
 * @param rides Indereço de uma RIDE.
 */

void freeRideDistance(RIDES rides);

/*!
 * Função que dá free à memoria utilizada pela ride.
 * @param rides Indereço de uma RIDE.
 */

void freeRideScore_User(RIDES rides);

/*!
 * Função que dá free à memoria utilizada pela ride.
 * @param rides Indereço de uma RIDE.
 */

void freeRideScore_Driver(RIDES rides);


