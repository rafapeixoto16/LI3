#pragma once

#include "../includes/drivers.h"
#include "../includes/users.h"
#include "../includes/rides.h"
#include "../includes/statusDriver.h"
#include "../includes/statusUser.h"
#include "../includes/funcoesUteis.h"

#define Driver 1
#define User   2
#define Ride   3
#define StatusUser 4
#define StatusDriver 5

typedef enum tipo TYPEarray;

typedef struct array *ARRAYDinamico;

/*!
 * Função que cria uma array
 * @param size Tamanho da array.
 * @param type Tipo da array.
 * @return Retorna o endereço da array criada.
 */

ARRAYDinamico arrayCreate(int size ,int type);

TYPEarray tipoRetorna(int tipo);


/*!
 * Função que dá o indice do id na array
 * @param id O id.
 * @return Retorna o indice do id.
 */

unsigned int hashFuncionDR (char *id);

/*!
 * Função que inicia a array com as posições todas a NULL
 * @param hash Dados da array.
 * @param comeco Onde a nova array começa.
 */

void hashInitNull (ARRAYDinamico hash,int comeco);

/*!
 * Função que apaga um elemento da array.
 * @param hash Dados da array.
 */

void arrayDelete (ARRAYDinamico hash);

/*!
 * Função que adiciona um elemnto à array.
 * @param hash Dados da array.
 * @param dado O elemento a ser adicionado.
 * @param index O username/id.
 * @return Retorna true se conseguir adicionar e falso caso nao consiga.
 */

bool arrayAdd (ARRAYDinamico hash, void *dado, char *index);


/*!
 * Função que dá print a todos os elementos das array.
 * @param hash Dados da array.
 */

void printHashtable (ARRAYDinamico hash);

/*!
 * Função de que dá o indice do user na array.
 * @param username O username.
 * @param size O tamanho da array.
 * @return Retorna o indice do user.
 */

unsigned int hashLLigada(char *username, int size);

/*!
 * Função que dá o tamanho da array.
 * @param table Dados da array.
 * @return Retorna o tamanho da array.
 */

int tamanhoHash (ARRAYDinamico table);

/*!
 * Função que dá parsing aos dados das array.
 * @param rides A array.
 * @param statusD Dados do condutor(driver).
 * @param statusU Dados do user
 * @param driver Condutor(driver).
 * @param user User
 */

void parsingStatus (ARRAYDinamico rides, ARRAYDinamico statusD, ARRAYDinamico statusU,ARRAYDinamico driver,ARRAYDinamico user);

/*!
 * Função que recebe um id e uma tabela.
 * @param hash A tabela.
 * @param id O id.
 * @return Retorna o endereço do array na array.
 */

DRIVERS posicaoTableD (ARRAYDinamico hash,char *id);

/*!
 * Função que recebe um id e uma tabela.
 * @param hash A tabela.
 * @param id O id.
 * @return Retorna o endereço do array na array.
 */

statusDriver posicaoTableSdriver(ARRAYDinamico hash,char *id);

/*!
 * Função que recebe um id e uma tabela.
 * @param hash A tabela.
 * @param id O id.
 * @return Retorna o endereço do array na array.
 */

USERS posicaoTableU(ARRAYDinamico hash,char *id);

/*!
 * Função que recebe um id e uma tabela.
 * @param hash A tabela.
 * @param id O id.
 * @return Retorna o endereço do array na array.
 */

statusUSER posicaoTableSusers(ARRAYDinamico hash,char *id);


/*!
 * Função que recebe a tabela das corridas.
 * @param ride A corrida.
 * @return Retorna a capacidade usada.
 */

int tamanhoOcupadoArray(ARRAYDinamico ride);

/*!
 * Função que recebe uma posição e uma tabela.
 * @param rides A tabela.
 * @param posicao A posição.
 * @return Retorna o endereço do array na array.
 */

RIDES posicaoTableRides(ARRAYDinamico rides,int posicao);

/*!
 * Função que recebe uma data e uma tabela.
 * @param dataPesquisada A data.
 * @return Retorna a posição da primeira data na tabela.
 */

int procuraPosicaoInicial(ARRAYDinamico array,int dataPesquisada);

/*!
 * Função que faz pesquisa binaria pela data menor.
 * @param ride A tabela.
 * @param dataPesquisada A data.
 * @param inicio A primeira posição.
 * @param tamanhoMax A capacidade utilizada.
 * @return Retorna o indice data caso a encontre
 */

int procuraDataBinary(ARRAYDinamico ride,int dataPesquisada,int inicio,int tamanhoMax);

//!QUICK SORT


/*!
 * Função que ordena a tabela das corridas por data.
 * @param rideTable Tabela das corridas.
 */

void ordena(ARRAYDinamico rideTable);


/*!
 * Função que ordena pela distancia percorrida.
 * @param hash Array de apontadores.
 * @param tamanho O taamnho utilizado.
 */

void quicksortDistanciaViagens(void **hash,int tamanho);

/*!
 * Função que ordena a array pela data das viagens.
 * @param hash A array.
 * @param tamanho O tamanho usado.
 */

void quicksortData(void **hash,int tamanho);


/*!
 * Função que ordena pelo id de viagem.
 * @param hash Array de apontadores.
 * @param tamanho O tamanho utilizado.
 */

void quicksortIdviagem(void **hash,int tamanho);

/*!
 * Função que ordena o array com as avaliações médias.
 * @param array O array.
 * @param tamanho O tamanho ocupado.
 */

void quicksortAvalMed(void **array,int tamanho);

/*!
 * Função que ordena o array com as datas de criação.
 * @param array O array.
 * @param tamanho O tamanho ocupado.
 */

void quicksortDataDriver(void **array,int tamanho);


/*!
 * Função que ordena o array com as datas de criação.
 * @param table O array.
 * @param tamanho O tamanho ocupado.
 * @param driver1 A tabela dos condutores.
 */

void quicksortDataCreationDriver(void **table,int tamanho,ARRAYDinamico driver1);

/*!
 * Função que troca dois elementos de uma array
 * @param array O array.
 * @param i Posição a trocar.
 * @param menor Posição a trocar.
 */

void swap(ARRAYDinamico array,int i,int menor);

/*!
 * Função que dá free á memoria utilizada pelo array.
 * @param table Posição na tabela.
 */

void arrayFree(ARRAYDinamico table);

/*!
 * Retorna o array da Hashtable.
 * @param table Hastable
 * @return Retorna o array da Hashtable.
 */

void *array(ARRAYDinamico table);

/*!
 * Função que troca duas posições de um array.
 * @param array O array.
 * @param i A primeira posição.
 * @param j A segunda posição.
 */

void swapElem(void **array,int i ,int j);

/*!
 * Função que retorna o conteudo na posição index da hastable StatsUser.
 * @param hash A array StatusUser.
 * @param numero O index.
 * @return Retorna o conteudo na posição index da hastable StatsUser.
 */

statusUSER posicaoTableSUsersIndex(ARRAYDinamico hash, int numero);

/*!
 * Ordena o array com tamanho segundo o id do driver.
 * @param array O array.
 * @param tamanho Tamanho o array.
 */

void quicksortIdStatusDriver(void **array,int tamanho);

/**
 * Função que retorna o conteudo na posição index da hastable StatsDriver.
 * @param hash Hashtable.
 * @param index Posiçao da hashTable.
 * @return Retorna o conteudo na posição index da hastable StatsDriver.
 */

statusDriver posicaoTableSdriverIndex(ARRAYDinamico hash ,int index);

/**
 * Função que retorna o conteudo na posição index da hastable Driver.
 * @param hash Hastable.
 * @param id Id do driver.
 * @return Retorna o conteudo na posição index da hastable Driver.
 */

DRIVERS posicaoTableDriverInt(ARRAYDinamico hash,int id);

/**
 * Retorna o array na posicao i .
 * @param table Hastable.
 * @param i Posicao do array.
 * @return Retorna o conteudo na posição i na forma de um endereço void.
 */

void *arrayPosicao(ARRAYDinamico table ,int i);