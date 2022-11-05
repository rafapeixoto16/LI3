//
// Created by rafael on 04-11-2022.
//

#include "users.h"

struct user {
    char *username;
    char *name;
    char *gender;
    char *birth_date;
    char *account_creation;
    char *pay_method;
    char *account_status;
};

USERS hashTableUsers [hashMaxUsers];

unsigned int hashUser(char *username){
    int length = strnlen(username,150);
    unsigned int hashTableUserV = 1;
    for (int i =0;i<length;i++){
        hashTableUserV*=username[i];
        hashTableUserV=(hashTableUserV * username[i]) % hashTableUserV;
    }
    return hashTableUserV;
}

void initHashTable() {
    for (int i = 0; i < hashMaxUsers; i++) {
        hashTableUsers[i] = NULL;
    }
}

void printTableUsers() {
    for (int i = 0; i < hashMaxUsers; i++) {
        if (hashTableUsers[i] != NULL) {
            printf("\t%s\n", ((hashTableUsers[i])->username));
        } else
            printf("errou---EMPTY--------\n");
    }
}

bool hashTableInsertUsers (USERS user){
    if(user==NULL)
        return false;

    int index = hashUser(user->username);

    if(hashTableUsers[index]!=NULL)
        return false;

    hashTableUsers[index]=user;
    return true;
}

USERS hashTableLookupUsers(char *username){
    unsigned int index = hashUser(username);
    if(hashTableUsers!=NULL && strncmp(hashTableUsers[index]->username,username,hashMaxUsers)==0){
        return hashTableUsers[index];
    }
    else
        return NULL;
}

USERS hashTableDeleteUsers (char *username){
    int index = hashUser(username);
    if(hashTableUsers!=NULL && strncmp(hashTableUsers[index]->username,username,hashMaxUsers)==0){
        USERS temp=hashTableUsers[index];
        hashTableUsers[index]=NULL;
        return temp;
    }
    else
        return NULL;
}