#pragma once

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define tamanhoInicialU 1000037


/*!
 * Define a struct user.
 */

typedef struct user *USERS;


/*!
 * Função que cria um objeto do tipo *USERS e depois adiciona-o á hashtable.
 * @param linha Linha com a informação do user.
 */

void userParsing (char *linha,void *arrayD);


/*!
 * Função que vai ao indice do user na hash table e pega nos seus status.
 * @param username O username.
 * @param user1 Indereço da lista ligada dos Users.
 * @return Retorna uma cópia dos status do user.
 */

bool lookupStatusUser (USERS user1,char *username);

/*!
 * Função que vai ao indice do user na hashtable e pega o seu nome.
 * @param username O username.
 * @param user1 Indereço da lista ligada dos Users.
 * @return Retorna uma cópia do nome do user.
 */

char *lookupNomeUser(USERS user1,char *username);

/*!
 * Função que vai ao indice do user na hashtable e pega o seu género.
 * @param username O username.
 * @param user1 Indereço da lista ligada dos Users.
 * @return Retorna uma cópia do género.
 */

bool lookupGeneroUser (USERS user1,char *username);

/*!
 * Função que vai ao indice do user na hashtable e paga na sua idade.
 * @param username O username.
 * @param user1 Indereço da lista ligada dos Users.
 * @return Retorna uma cópia da idade.
 */

int lookupIdadeUser (USERS user1,char *username);

/*!
 * Recebe o id e procura a data de criaçao.
 * @param users Dados dos users.
 * @param user1 Indereço da lista ligada dos Users..
 * @return Retorna a data de criação da conta do user.
 */

int lookupDatacriacaoUser(USERS users,char *username);

/*!
 * Função que dá print á table dos users
 */

void printUsers(USERS users);

/*!
 * Função que guarda alguns dados do user.
 * @param user1 O user.
 * @param id O username.
 * @param genero O genero.
 * @param idade A idade.
 */

void informacoesBasicasUser(USERS user1, char *id, bool *genero, int *idade);

/*!
 * Função que liberta a memoria utilizada pelo user.
 */

void freeUser(USERS user);

/*!
 * Função que liberta a memoria utilizada pelo user.
 */

void freeUserUsername(USERS users);

/*!
 * Função que liberta a memoria utilizada pelo user.
 */

void freeUserName(USERS users);

/*!
 * Função que liberta a memoria utilizada pelo user.
 */

void freeUserBirthday(USERS users);

/*!
 * Liberta a memoria utilizada pela data de cração da conta do user.
 * @param users O user.
 */

void freeUserAcountCreation(USERS users);

/*!
 * Verifica se um username é valido a adiciona-o caso o seja.
 * @param username username a verificar.
 * @param users Users a ser adicionado.
 * @return Retorna 0 caso o username é valido , 1 caso contrario.
 */

int usernameUser (char *username,USERS users);

/*!
 * Verifica se um nome é valido a adiciona-o caso o seja.
 * @param nome nome a verificar.
 * @param users Users a ser adicionado.
 * @return Retorna 0 caso o name é valido , 1 caso contrario.
 */

int nomeUser(char *nome,USERS users);

/*!
 * Verifica se um genero é valido a adiciona-o caso o seja.
 * @param genero Genero a verificar.
 * @param users Users a ser adicionado.
 * @return Retorna 0 caso o genero é valido , 1 caso contrario.
 */


int generoUser(char *genero,USERS users);

/*!
 * Verifica se a data de nacismento é valida a adiciona-o caso o seja.
 * @param data data a verificar.
 * @param users Users a ser adicionado.
 * @return Retorna 0 caso a data de nascimento é valido , 1 caso contrario.
 */

int dataNascUser(char *data,USERS users);

/*!
 * Verifica se a data de criaçao da conta é valido a adiciona-o caso o seja.
 * @param data Data a verificar.
 * @param users Users a ser adicionado.
 * @return Retorna 0 caso a data de criaçao  é  valido , 1 caso contrario.
 */

int dataCriacaoUser(char *data,USERS users);

/*!
 * Verifica se o metodo de pagamento da conta é valido.
 * @param metodo Data a verificar.
 * @param users Users a ser adicionado.
 * @return Retorna 0 caso a data de criaçao  é  valido , 1 caso contrario.
 */

int metodoPagUser(char *metodo,USERS users);

/*!
 * Verifica se o metodo de pagamento da conta é valido.
 * @param metodo Data a verificar.
 * @param users Users a ser adicionado.
 * @return Retorna 0 caso a data de criaçao  é  valido , 1 caso contrario.
 */

int statusContaUser(char *status,USERS users);