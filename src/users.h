#ifndef LI3_USERS_H
#define LI3_USERS_H

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define hashMaxUsers 100000

/*!
 * Define a struct user.
 */

typedef struct user *USERS;

/*!
 * Função que inicia a hashtable com todas as posições a NULL.
 */

void initHashTableUsers();

/*!
 * Função que cria um objeto do tipo *USERS e depois adiciona-o á hashtable.
 * @param linha Linha com a informação do user.
 */

void userParsing(char *linha);

/*!
 * Esta função adiciona um user á hashtable.
 * @param user User a ser adicionado.
 * @return Retorna True se conseguir adicionar o user e False se não conseguir.
 */

bool hashTableInsertUsers (USERS user);

/*!
 * Função que atribui uma posição na tabela dependendo do username.
 * @param username O username.
 * @return Retorna o indice do user na hashtable.
 */

unsigned int hashUser(char *username);

/*!
 * Função que dá print em todas os usernames na hashtable.
 */

void printTableUsers();

/*!
 *
 * @param username
 * @return
 */

USERS hashTableDeleteUsers (char *username);

/*!
 * Função que vai ao indice do user na hash table e pega nos seus status.
 * @param username O username.
 * @return Retorna uma cópia dos status do user.
 */

char *lookupStatusUser(char *username);

/*!
 * Função que vai ao indice do user na hashtable e pega o seu nome.
 * @param username O username.
 * @return Retorna uma cópia do nome do user.
 */

char *lookupNomeUser(char *username);

/*!
 * Função que vai ao indice do user na hashtable e pega o seu género.
 * @param username O username.
 * @return Retorna uma cópia do género.
 */

char *lookupGeneroUser(char *username);

/*!
 * Função que vai ao indice do user na hashtable e paga na sua idade.
 * @param username O username.
 * @return Retorna uma cópia da idade.
 */

int lookupIdadeUser(char *username);


void freeUsers ();

#endif //LI3_USERS_H
