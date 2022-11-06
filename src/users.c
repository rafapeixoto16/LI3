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
    struct user * next;
};

USERS hashTableUsers [hashMaxUsers];

unsigned int hashUser(char *username){
    int length = strnlen(username,150);
    unsigned int hashTableUserV = 0;
    for (int i =0;i<length;i++){
        hashTableUserV +=username[i];
        hashTableUserV=(hashTableUserV * username[i]) % hashTableUserV;
    }
    return hashTableUserV;
}

void initHashTableUsers(){
    for (int i = 0; i < hashMaxUsers; i++) {
        hashTableUsers[i]=NULL;
    }
}

void printTableUsers() {
    int j =1;
    for (int i = 0; i < hashMaxUsers; i++) {
        if (hashTableUsers[i] == NULL) {
        }
        else{
            USERS tmp = hashTableUsers[i];
            while (tmp!=NULL){
                printf("%s %d- \n",tmp->username,j);
                tmp=tmp->next;
                j++;
            }
            //printf("\n");
        }
    }
}

bool hashTableInsertUsers (USERS user){
    if(user==NULL)
        return false;
    int index= hashUser(user->username);
    user->next=hashTableUsers[index];
    hashTableUsers[index]=user;
    return true;
}


USERS hashTableLookupUsers(char *username) {
    unsigned int index = hashUser(username);
    USERS tmp = hashTableUsers[index];
    while (tmp != NULL && strncmp(tmp->username, username, 50) != 0) {
        tmp = tmp->next;
    }
    return tmp;
}

USERS hashTableDeleteUsers (char *username) {
    unsigned int index = hashUser(username);
    USERS tmp = hashTableUsers[index];
    USERS prev = NULL;
    while (tmp != NULL && strncmp(tmp->username, username, 50) != 0){
        prev=tmp;
        tmp=tmp->next;
    }
    if(tmp == NULL)
        return NULL;

    if(prev == NULL)
        hashTableUsers[index] = tmp->next;

    else{
        prev->next=tmp->next;
    }
    return tmp;
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

    head = strtok_r(NULL,";",&tail);
    i = strlen(head);
    head[i]='\0';
    user1->name= strdup(head);

    head = strtok_r(NULL,";",&tail);
    i = strlen(head);
    head[i]='\0';
    user1->gender= strdup(head);

    head = strtok_r(NULL,";",&tail);
    i = strlen(head);
    head[i]='\0';
    user1->birth_date= strdup(head);

    head = strtok_r(NULL,";",&tail);
    i = strlen(head);
    head[i]='\0';
    user1->account_creation= strdup(head);

    head = strtok_r(NULL,";",&tail);
    i = strlen(head);
    head[i]='\0';
    user1->pay_method= strdup(head);

    head = strtok_r(NULL,";",&tail);
    i = strlen(head);
    head[i]='\0';
    user1->account_status= strdup(head);

    user1->next=NULL;

    bool bools =hashTableInsertUsers(user1);

    if(!bools){

    }
}