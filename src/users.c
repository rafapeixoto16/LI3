#include "../includes/users.h"
#include "../includes/array.h"

struct user {
    char *username;
    char *name;
    bool gender;
    char *birth_date;
    int account_creation;
    bool account_status;
    struct user * next;
};



// --------------------------------------------
// userParsing
// --------------------------------------------

void userParsing (char *linha,void *arrayD){
    ARRAYDinamico array = arrayD;
    USERS user1 = malloc(sizeof (struct user));

    char *tail;
    int i;

    i = usernameUser (strtok_r(linha,";",&tail),user1);

    if(i)
        return;

    i = nomeUser(strtok_r(NULL,";",&tail),user1);

    if(i)
        return;

    i = generoUser(strtok_r(NULL,";",&tail),user1);

    if(i)
        return;

    i = dataNascUser(strtok_r(NULL,";",&tail),user1);

    if(i)
        return;

    i = dataCriacaoUser(strtok_r(NULL,";",&tail),user1);

    if(i)
        return;

    i = metodoPagUser(strtok_r(NULL,";",&tail),user1);

    if(i)
        return;

    i = statusContaUser(strtok_r(NULL,"\n",&tail),user1);

    if(i)
        return;


    user1 -> next  = NULL;
    char *username1 = strdup(user1->username);
    user1 -> next = posicaoTableU(array,username1);

    arrayAdd(array,user1,username1);
    free(username1);
}


// --------------------------------------------
// printUsers
// --------------------------------------------

void printUsers(USERS users){
    USERS tmp = users;
    while(tmp != NULL) {
        printf("username= %s, name= %s, gender= %s, birth_date= %s, account_creation= %s, account_status= %s \n",
               tmp->username,
               tmp->name,
               tmp->gender == 1 ? "M":"F",
               tmp->birth_date,
               int2Data(tmp->account_creation),
               tmp->account_status == 1 ?"active":"inactive");
        tmp=tmp->next;
    }
}

// --------------------------------------------
// freeUser
// --------------------------------------------

void freeUser(USERS user){
    USERS tmp;
    while(user != NULL){
        tmp = user;
        user = user->next;
        free            (tmp->name);
        free        (tmp->username);
        free      (tmp->birth_date);
        free                  (tmp);
    }

}



// --------------------------------------------
// lookupStatusUser
// --------------------------------------------

bool lookupStatusUser (USERS user1,char *username){
    USERS tmp = user1;

    while (tmp != NULL && strncmp(tmp->username, username, 50) != 0) {
        tmp = tmp->next;
    }
    if(tmp == NULL)
        return NULL;

    bool returno = tmp->account_status;
    return returno;
}

// --------------------------------------------
// lookupNomeUser
// --------------------------------------------

 char *lookupNomeUser (USERS user1, char *id){
    USERS tmp =user1;

    while (tmp != NULL && strncmp(tmp->username, id, 50) != 0) {
        tmp = tmp->next;
    }
    return strdup(tmp->name);
}

// --------------------------------------------
// lookupGeneroUser
// --------------------------------------------

bool lookupGeneroUser (USERS user1, char *id){
    USERS tmp = user1;

    while (tmp != NULL && strncmp(tmp->username, id, 50) != 0) {
        tmp = tmp->next;
    }

    bool retorno = tmp->gender;
    return retorno;
}

// --------------------------------------------
// lookupDataCriacaoUser
// --------------------------------------------

int lookupDataCriacaoUser(USERS user1,char *id){
    USERS tmp = user1;

    while (tmp != NULL && strncmp(tmp->username, id, 50) != 0) {
        tmp = tmp->next;
    }
    int retorno = tmp->account_creation;
    free(id);
    return retorno;
}

// --------------------------------------------
// lookupIdadeUser
// --------------------------------------------

int lookupIdadeUser (USERS users,char *id){
    USERS tmp =users;

    while (tmp != NULL && strncmp(tmp->username, id, 50) != 0)
    {
        tmp = tmp->next;
    }

    if(tmp==NULL)
    {
        return -1;
    }

    char *data = strdup(tmp->birth_date);
    int idade  = calculaIdade(data);
    free(data);
    return idade;
}

// --------------------------------------------
// lookupDatacriacaoUser
// --------------------------------------------

int lookupDatacriacaoUser(USERS users,char *id){
    USERS tmp =users;

    while (tmp != NULL && strncmp(tmp->username, id, 50) != 0) {
        tmp = tmp->next;
    }

    if(tmp == NULL){
        return -1;
    }

    return tmp -> account_creation;
}

// --------------------------------------------
// informacoesBasicasUser
// --------------------------------------------

void informacoesBasicasUser(USERS user1,char *id,bool *genero,int *idade){
    USERS tmp = user1;

    while (tmp != NULL && strncmp(tmp->username, id, 50) != 0) {
        tmp = tmp->next;
    }

    if(tmp == NULL)
        return;

    *id     = *strdup(tmp->name);
    *genero = tmp->gender;
    *idade  = lookupIdadeUser(user1,id);
}

// --------------------------------------------
// usernameUser
// --------------------------------------------

int usernameUser (char *username,USERS users){
    username[strlen(username)] = '\0';

    if(tamanhoEqual0(username)) {
        free(users);
        return 1;
    }

    users -> username= strdup(username);
    return 0;
}

// --------------------------------------------
// nomeUser
// --------------------------------------------

int nomeUser(char *nome,USERS users){
    nome[strlen(nome)] = '\0';

    if(tamanhoEqual0(nome)){
        freeUserUsername(users);
        return 1;
    }

    users -> name = strdup(nome);
    return 0;
}

// --------------------------------------------
// generoUser
// --------------------------------------------

int generoUser(char *genero,USERS users){
    genero[strlen(genero)] = '\0';

    if(tamanhoEqual0(genero)){
        freeUserName(users);
        return 1;
    }

    users -> gender = strcmp("M",genero) == 0 ? 1 : 0;
    return 0;
}

// --------------------------------------------
// dataNascUser
// --------------------------------------------

int dataNascUser(char *data,USERS users){
    data[strlen(data)]='\0';

    if(!verificaDate(data)){
        freeUserName(users);
        return 1;
    }

    users->birth_date = strdup(data);
    return 0;
}

// --------------------------------------------
// dataCriacaoUser
// --------------------------------------------

int dataCriacaoUser(char *data,USERS users){
    data[strlen(data)]='\0';

    if(!verificaDate(data)){
        freeUserBirthday(users);
        return 1;
    }

    users->account_creation= data2Int(data);
    return 0;
}

// --------------------------------------------
// metodoPagUser
// --------------------------------------------

int metodoPagUser(char *metodo,USERS users){
    metodo[strlen(metodo)]='\0';

    if(tamanhoEqual0(metodo)){
        freeUserAcountCreation(users);
        return 1;
    }
    return 0;
}

// --------------------------------------------
// statusContaUser
// --------------------------------------------

int statusContaUser(char *status,USERS users){
    if(status==NULL){
        freeUserAcountCreation(users);
        return 1;
    }
    status[strlen(status)]='\0';
    toLowerString(status);
    if(!(strcmp("active",status) == 0 || strcmp("inactive",status) == 0)){
        freeUserAcountCreation(users);
        return 1;
    }
    users->account_status = strcmp("active",status) == 0 ? true : false;
    return 0;
}

// --------------------------------------------
// freeUserUsername
// --------------------------------------------

void freeUserUsername(USERS users){
    free (users->username);
    free           (users);
}

// --------------------------------------------
// freeUserName
// --------------------------------------------

void freeUserName(USERS users) {
    free     (users->name);
    free (users->username);
    free           (users);
}

// --------------------------------------------
// freeUserBirthday
// --------------------------------------------

void freeUserBirthday(USERS users){
    free (users->birth_date);
    free       (users->name);
    free   (users->username);
    free             (users);
}

// --------------------------------------------
// freeUserAcountCreation
// --------------------------------------------

void freeUserAcountCreation(USERS users){
    free (users->birth_date);
    free       (users->name);
    free   (users->username);
    free             (users);
}

