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
    int index= hashUser(user->username);
    for (int i = 0; i <hashMaxUsers;i++) {
        int try = (i+index) % hashMaxUsers;
        if(hashTableUsers[try]==NULL){
            hashTableUsers[try]=user;
            return true;
        }
    }

    return false;
}

USERS hashTableLookupUsers(char *username) {
    unsigned int index = hashUser(username);
    for (int i = 0; i < hashMaxUsers; i++) {
        int try = (index + i) % hashMaxUsers;
        if (hashTableUsers[try] != NULL && strncmp(hashTableUsers[try]->username, username, hashMaxUsers) == 0) {
            return hashTableUsers[try];
        }
    }
    return NULL;
}

USERS hashTableDeleteUsers (char *username) {
    unsigned int index = hashUser(username);
    for (int i = 0; i < hashMaxUsers; i++) {
        int try = (index + i) % hashMaxUsers;
        if (hashTableUsers[try] != NULL && strncmp(hashTableUsers[try]->username, username, hashMaxUsers) == 0) {
            USERS temp=hashTableUsers[try];
            hashTableUsers[try]=NULL;
            return temp;
        }
    }
    return NULL;
}

void userParsing (char *linha){

    USERS user1 = malloc(sizeof (struct user));
    char *head;
    char *tail;
    int i;

    head = strtok_r(linha,";",&tail);
    i = strlen(head);
    head[i]='\0';
    user1->username= strdup(head);

    head = strtok_r(linha,";",&tail);
    i = strlen(head);
    head[i]='\0';
    user1->name= strdup(head);

    head = strtok_r(linha,";",&tail);
    i = strlen(head);
    head[i]='\0';
    user1->gender= strdup(head);

    head = strtok_r(linha,";",&tail);
    i = strlen(head);
    head[i]='\0';
    user1->birth_date= strdup(head);

    head = strtok_r(linha,";",&tail);
    i = strlen(head);
    head[i]='\0';
    user1->account_creation= strdup(head);

    head = strtok_r(linha,";",&tail);
    i = strlen(head);
    head[i]='\0';
    user1->pay_method= strdup(head);

    head = strtok_r(linha,";",&tail);
    i = strlen(head);
    head[i]='\0';
    user1->account_status= strdup(head);


    bool bools =hashTableInsertUsers(user1);

    if(!bools){

    }
}