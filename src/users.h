//
// Created by rafael on 04-11-2022.
//

#ifndef LI3_USERS_H
#define LI3_USERS_H
#include<string.h>
#define hashMaxUsers 100000

typedef struct user *USERS;

void initHashTable();
void userParsing(char *linha);

#endif //LI3_USERS_H
