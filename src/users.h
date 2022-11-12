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

typedef struct user *USERS;

void initHashTableUsers();
void userParsing(char *linha);
bool hashTableInsertUsers (USERS user);
unsigned int hashUser(char *username);
void printTableUsers();
USERS hashTableLook(char *username);
USERS hashTableDeleteUsers (char *username);

char *lookupStatusUser(char *id);

char *lookupNomeUser(char *id);

char *lookupGeneroUser(char *id);

int lookupIdadeUser(char *id);


#endif //LI3_USERS_H
