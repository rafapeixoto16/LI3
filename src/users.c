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

void initHashTable(){
    for (int i = 0; i < hashMaxUsers; i++) {
        hashTableUsers[i]=NULL;
    }
}

void