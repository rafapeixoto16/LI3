#pragma once

#include <stdbool.h>

/*!
 * Algumas informaçoes do condutor(driver)
 */

typedef struct statsD *statusDriver;

/*!
 * Função que cria um elemento do tipo statsD.
 * @param dinheiroG Dinheiro ganho.
 * @param score Avaliação do driver.
 * @param id O Id.
 * @param viagem A viagem.
 * @return Retorna o endereço para o elemento.
 */

statusDriver statusDParsing (double dinheiroG, double score, char *id,int viagem);

/*!
 * Função que faz com que o apontador do ultimo acessado seja adicionado à lista dos status.
 * @param sD Os dados do user.
 * @param dinheiroG O dinheiro ganho.
 * @param scoreD A avaliação do driver.
 * @param data A data.
 */

void incrementaDriver(statusDriver sD,double  dinheiroG, double scoreD,int data);


/*!
 * Função que liberta a memoria utilizada pelos dodos do condutor(driver).
 * @param sD Dados do condutor(driver).
 */

void freeDriverStatus(statusDriver sD);

/*!
 * Função que dá print aos dados do condutor(driver).
 * @param sD Dados do condutor(driver).
 */

void printDriverStatus (statusDriver sD);

/*!
 *
 * Função que guarda algumas informações do condutor(driver).
 * @param driver O driver.
 * @param dinheiro O dinheiro.
 * @param avaliacao A avaliação.
 * @param nv O numero de viagens.
 */

void informacoesBasicasStatusDriver(statusDriver driver ,double *dinheiro,double *avaliacao,int *nv);

/*!
 * Função que dá o dinheiro ganho pelo condutor(driver).
 * @param driver O condutor(driver).
 * @return Retorna do dinheiro ganho pelo condutor(driver).
 */

double lookupDinheiroStatusDriver(statusDriver driver);

/*!
 * Função que dá a avaliação do condutor(driver).
 * @param driver O condutor(driver).
 * @return Retorna o score_driver do condutor(driver).
 */

double lookupAvaliacaoStatusDriver(statusDriver driver);

/*!
 * Função que dá o numero de viagem do condutor(driver).
 * @param driver O condutor(driver).
 * @return Retorna o nº de viagens do condutor(driver).
 */

int lookupNumeroVStatusDriver (statusDriver driver);

/*!
 * Função que dá a data da viagem mais recente do condutor(driver).
 * @param driver O condutor(driver).
 * @return Retorna a data da viagem mais recente do condutor(driver).
 */

int lookupDataStatusDriver (statusDriver driver);

/*!
 * Função que dá o id do condutor(driver).
 * @param driver O condutor(driver).
 * @return Retorna o id do condutor como inteiro.
 */

int lookupIdStatusDriver(statusDriver driver);

/*!
 * Função que procura o Id do condutor.
 * @param driver O condutor(driver).
 * @return Retorna o id na forma de um char.
 */

char *lookupIDcharStatus(statusDriver driver);

/*!
 * Função que procura a avaliação média do condutor.
 * @param driver O condutor(driver).
 * @return Retorna a avaliação média.
 */

double lookupAvalMedDriver(statusDriver driver);