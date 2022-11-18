//
// Created by rafael on 04-11-2022.
//

#ifndef LI3_USERS_H
#define LI3_USERS_H

#include<string.h>
#include<stdio.h>
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
 * Função que atribui uma posição na tabela dependento do username.
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

USERS hashTableLook(char *username);

/*!
 * Função que vai ao indice do username e caso
 * @param username Username a ser apagado da hashtable.
 * @return
 */

USERS hashTableDeleteUsers (char *username);

/*!
 *
 * @param id
 * @return
 */

char *lookupStatusUser(char *id);

/*!
 * F
 * @param id
 * @return
 */

char *lookupNomeUser(char *id);

/*!
 *
 * @param id
 * @return
 */

char *lookupGeneroUser(char *id);

/*!
 *
 * @param id
 * @return
 */

int lookupIdadeUser(char *id);


#endif //LI3_USERS_H
