#pragma once

#include <stdbool.h>

/*!
 * Algumas informações do user
 */

typedef struct statsU *statusUSER;

/*!
 * Função que cria um elemento do tipo statsU.
 * @param userStatus status do user.
 * @param dinheiroG O dinheiro gasto.
 * @param score A avaliação.
 * @param username O username.
 * @param data A data.
 * @param distancia A distancia.
 * @return Retorna o endereço do elemento.
 */

statusUSER statusUParsing (void *userStatus,double dinheiroG, double score, char *username,int data,int distancia);

/*!
 * Função que verifica se um dado user pertence á lista e caso pertença atualiza os seus dados
 * @param sU Os dados do user.
 * @param nomeUser O user.
 * @param dinheiro O dinheiro.
 * @param scoreU A avaliação.
 * @param data A viagem mais recente.
 * @param distancia A distancia total.
 * @return Retorna false caso o user nao esteja na lista e true caso esteja
 */

bool pertencaLista (statusUSER sU, char *nomeUser,double dinheiro,double scoreU,int data,int distancia);

/*!
 * Função que liberta a memoria utilizada pelo status do user.
 * @param sU User a dar free.
 */

void freeUserStatus(statusUSER sU);

/*!
 * Função que dá printe aos dados do user.
 * @param sU User a dar print.
 */

void printUserStatus (statusUSER sU);

/*!
 * Função que guarda a algumas informações do user
 * @param user1 User a procurar.
 * @param username Username do user.
 * @param dinheiro Dinheiro do user.
 * @param avaliacao Avaliação do user.
 * @param nv Numero de viagens do user.
 */

void informacoesBasicasStatusUser (statusUSER user1 ,char *username,double *dinheiro,double *avaliacao,int *nv);

/*!
 * Função que dá a distancia total percorrida pelo user.
 * @param user1 O user.
 * @return Retorna a dustancia percorrida.
 */

int lookupDistanciaUser(statusUSER user1);

/*!
 * Função que dá viagem mais recente do user.
 * @param user1 O user.
 * @return Retorna a data da viagem mais recente do user.
 */

int lookupViagemMRUser(statusUSER user1);

/*!
 * Função que dá o username do user.
 * @param user1 O user.
 * @return Retorna o username do user.
 */

char *lookupUsernameUser(statusUSER user1);

/*!
 * Função que poe o user apontar para o seu ultimo acesso.
 * @param user1 O user.
 */

void setPointer(statusUSER user1);

/*!
 * Função que dá o endereço do ultimo acesso do user.
 * @param user1 O user.
 * @return Retorna o endereço do ultimo acesso.
 */

statusUSER lookupMaisRecenteVisitado(statusUSER user1);

/*!
 * Função que avança na lista ligada a partir do ultimo acesso
 * @param user1 O user.
 */

void avancaRecenteVisitado(statusUSER user1);

/*!
 * Função que dá o id do user.
 * @param user1 O user.
 * @return Retorna a string do id do user.
 */

char *lookupIDcharStatusUser(statusUSER user1);

/*!
 * Função que ordena o array de distancias dos users.
 * @param user Dados dos users.
 * @param tamanho Tamanho do array.
 */

void quicksortDistanciaUser(statusUSER *user,int tamanho);

/*!
 * Função que ordena o array de viagens mais recentes.
 * @param user Dados dos users.
 * @param tamanho Tamanho do array.
 */

void quicksortViagemMRecente(statusUSER *user,int tamanho);