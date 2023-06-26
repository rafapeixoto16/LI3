#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define tamanhoInicialD 10000

/*!
 * Informaçoes do condutor (driver).
 !*/

typedef struct driver *DRIVERS;


/*!
 * Esta função cria um objeto do tipo *DRIVERS e depois adiciona-o a array se for valido.
 * @param linha Recebe um linha com toda a informação do condutor (driver).
 * @param arrayD Hashtable Driver.
 */

void driversParsing(char *linha,void *arrayD);


/*!
 * Da print de um contutor (driver).
 * @param drivers DRIVERS a dar print.
 */

void printDriver(DRIVERS drivers);


/*!
 * Função que dá os status de um determinado condutor.
 * @param driver1 Driver a qual queremos a informaçao.
 * @return Retorna os status do condutor (driver).
 */

bool lookupStatusDriver(DRIVERS driver1);

/*!
 * Função que dá o nome de um determinado condutor (driver).
 * @param driver1 Driver a qual queremos a informaçao.
 * @return Retorna o nome do condutor (driver).
 */

char *lookupNomeDriver(DRIVERS driver1);

/*!
 * Função que dá o genero do condutor (driver).
 * @param driver1 Driver a qual queremos a informaçao.
 * @return Retorna o genero do condutor (driver).
 */

bool lookupGeneroDriver(DRIVERS driver1);

/*!
 * Função que dá a idade do condutor (driver).
 * @param driver1 Driver a qual queremos a informaçao.
 * @return Retorna a idade do condutor (driver).
 */

int lookupIdadeDriver(DRIVERS driver1);

/*!
 * Função que procura a data de criação de um determinado driver.
 * @param drivers Posição do driver.
 * @return Retorna a data de criação.
 */

int lookupDataCriacaoDriver(DRIVERS drivers);

/*!
 * Calcula o preço de viagem.
 * @param distancia Distância em Km.
 * @param driver1 Driver ao qual queremos a informaçao.
 * @return Retorna o valor da viagem.
 */

double precoViagem(int distancia,DRIVERS driver1);

/*!
 * Liberta a memoria usada pelo "condutores" (Drivers).
 */

void freeDriver (DRIVERS driver);

/*!
 * Liberta a memoraria usada pelo id dos condutores(drivers).
 */

void freeDriverId (DRIVERS drivers);

/*!
 * Liberta a memoria usada pelo nome dos condutores(drivers).
 */

void freeDriverName (DRIVERS drivers);

/*!
 * Liberta a memoria utilizada pela data de nascimento dos condutores(drivers).
 */

void freeDriverBirthDay (DRIVERS drivers);

/*!
 * Liberta a memoria utilizada pela classe do carro dos condutores(drivers).
 */

void freeDriverCarClass (DRIVERS drivers);

/*!
 * Liberta a memoria utilizada pela cidade dos condutores(drivers).
 * @param drivers
 */

void freeDriverCity  (DRIVERS drivers);

/*!
 * Função que recebe um condutor(driver) e pega o seu nome, genero e idade.
 * @param driver condutor(driver).
 * @param nome Nome do condutor(driver).
 * @param genero Genero do condutor(driver).
 * @param idade Idade do condutor(driver).
 */

void informacoesBasicasDriver(DRIVERS driver,char *nome,bool *genero,int *idade);

/*!
 * Função que liberta a memoria utilizada pelo driver até á data de criação.
 * @param drivers O driver.
 */

void freeAcountCreation (DRIVERS drivers);

/*!
 * Verifica se o Id é valido e adiciona-o caso o seja.
 * @param id ID do driver.
 * @param drivers Driver a ser adicionado o id.
 * @return Retorna 0 caso seja valido ,1 caso contrario
 */

int idDriver(char *id,DRIVERS drivers);

/*!
 * Verifica se o Nome é valido e adiciona-o caso o seja.
 * @param nome nome do driver.
 * @param drivers Driver a ser adicionado o nome.
 * @return Retorna 0 caso seja valido ,1 caso contrario
 */

int nomeDriver (char *nome,DRIVERS drivers);

/*!
 * Verifica se a data de nascimento é valida e adiciona-a caso o seja.
 * @param data data de nascimento driver.
 * @param drivers Driver a ser adicionado a data.
 * @return Retorna 0 caso seja valido ,1 caso contrario
 */

int dataAniDriver(char *data,DRIVERS drivers);

/*!
 * Verifica se o genero é valido e adiciona-o caso o seja.
 * @param genero genero do driver.
 * @param drivers Driver a ser adicionado o genero.
 * @return Retorna 0 caso seja valido ,1 caso contrario
 */

int generoDriver(char *genero,DRIVERS drivers);

/*!
 * Verifica se o tipo de carro  é valido e adiciona-o caso o seja.
 * @param tipoCarro genero do driver.
 * @param drivers Driver a ser adicionado o tipo de carro.
 * @return Retorna 0 caso seja valido ,1 caso contrario.
 */

int typeCarDriver(char *tipoCarro,DRIVERS drivers);

/*!
 * Verifica se o licensa do carro é valida.
 * @param lincense licensa do carro do driver.
 * @param drivers Driver.
 * @return Retorna 0 caso seja valido ,1 caso contrario.
 */

int licensePlateDriver (char *lincense,DRIVERS drivers);

/*!
 * Verifica se a cidade é valida.
 * @param cidade Cidade do driver.
 * @param drivers Driver.
 * @return Retorna 0 caso seja valido ,1 caso contrario.
 */

int cidadeDriver (char *cidade,DRIVERS drivers);

/*!
 * Verifica se a data de criaçao da conta  é valida e adiciona-a caso o seja.
 * @param dataCriacao  data de criaçao da conta .
 * @param drivers Driver a ser adicionado a data de criaçao da conta .
 * @return Retorna 0 caso seja valido ,1 caso contrario.
 */

int dataCriacaoDriver(char *dataCriacao ,DRIVERS drivers);

/*!
 * Verifica se o estado de conta é valido e adiciona-o caso o seja.
 * @param estadoConta estado de conta da conta .
 * @param drivers Driver a ser adicionado o estado de conta.
 * @return Retorna 0 caso seja valido ,1 caso contrario.
 */

int estadoContaDriver (char *estadoConta,DRIVERS drivers);