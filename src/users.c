#include "users.h"

USERS hashTableUsers [hashMaxUsers];

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


// --------------------------------------------
// hashUser
// --------------------------------------------

unsigned int hashUser(char *username){
    unsigned int length = strnlen(username,150);
    unsigned int hashTableUserV = 0;
    for (int i =0;i<length;i++){
        hashTableUserV +=username[i];
        hashTableUserV=(hashTableUserV * username[i]) % hashTableUserV;
    }
    return hashTableUserV;
}


// --------------------------------------------
// initHashTableUsers
// --------------------------------------------

void initHashTableUsers(){
    for (int i = 0; i < hashMaxUsers; i++) {
        hashTableUsers[i]=NULL;
    }
}


// --------------------------------------------
// printTableUsers
// --------------------------------------------

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

// --------------------------------------------
// hashTableInsertUsers
// --------------------------------------------

bool hashTableInsertUsers (USERS user){
    if(user==NULL)
        return false;
    unsigned int index= hashUser(user->username);
    user->next=hashTableUsers[index];
    hashTableUsers[index]=user;
    return true;
}

// --------------------------------------------
// hashTableLookupUsers
// --------------------------------------------

USERS hashTableLookupUsers(char *username) {
    unsigned int index = hashUser(username);
    USERS tmp = hashTableUsers[index];
    while (tmp != NULL && strncmp(tmp->username, username, 50) != 0) {
        tmp = tmp->next;
    }
    return tmp;
}

// --------------------------------------------
// hashTableDeleteUsers
// --------------------------------------------

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

// --------------------------------------------
// userParsing
// --------------------------------------------

void userParsing (char *linha){

    USERS user1 = malloc(sizeof (struct user));
    char *head;
    char *tail;
    unsigned long i;

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

    head = strtok_r(NULL,"\n",&tail);
    i = strlen(head);
    head[i]='\0';
    user1->account_status= strdup(head);

    user1->next=NULL;

    bool bools =hashTableInsertUsers(user1);

    if(!bools){
        //segunda fase com tamanhos maiores
    }
}

// --------------------------------------------
// lookupStatusUser
// --------------------------------------------

char *lookupStatusUser(char *username){
    unsigned int index = hashUser(username);
    USERS tmp = hashTableUsers[index];

    while (tmp != NULL && strncmp(tmp->username, username, 50) != 0) {
        tmp = tmp->next;
    }
    return strdup(tmp->account_status);
}

// --------------------------------------------
// lookupNomeUser
// --------------------------------------------

char *lookupNomeUser(char *username){
    unsigned int index = hashUser(username);
    USERS tmp = hashTableUsers[index];

    while (tmp != NULL && strncmp(tmp->username, username, 50) != 0) {
        tmp = tmp->next;
    }
    return strdup(tmp->name);
}

// --------------------------------------------
// lookupGeneroUser
// --------------------------------------------

char *lookupGeneroUser(char *username){
    unsigned int index = hashUser(username);
    USERS tmp = hashTableUsers[index];

    while (tmp != NULL && strncmp(tmp->username, username, 50) != 0) {
        tmp = tmp->next;
    }
    return strdup(tmp->gender);
}

// --------------------------------------------
// lookupIdadeUser
// --------------------------------------------

int lookupIdadeUser(char *username){
    char *temp2;
    unsigned int index = hashUser(username);
    USERS tmp = hashTableUsers[index];

    while (tmp != NULL && strncmp(tmp->username, username, 50) != 0) {
        tmp = tmp->next;
    }
    char *data= tmp->birth_date;

    int idade;
    int dia = 9, mes = 10, ano = 2022;
    int diaAniv = atoi(strtok_r(data, "/", &temp2));
    int mesAniv = atoi(strtok_r(NULL, "/", &temp2));
    int anoAniv = atoi(strtok_r(NULL, "/", &temp2));

    idade = ano-anoAniv-1;

    if((mesAniv<mes)||(mesAniv==mes && diaAniv<=dia))
        idade = idade + 1;

    return idade;
}


void freeUsers (){
    for (int i = 0; i < hashMaxUsers; i++) {
        if (hashTableUsers[i] == NULL) {
            continue;
        }
        else{

            USERS tmp = hashTableUsers[i];
            while (tmp != NULL){

                USERS next = tmp->next;

                char *username = tmp->username;
                free        (username);

                char *accountS =tmp->account_status;
                free  (accountS);


                free          (tmp->gender);
                free      (tmp->birth_date);
                free            (tmp->name);
                free      (tmp->pay_method);
                free(tmp->account_creation);
                tmp = tmp->next;
                free            (next);
            }
        }
    }
}


