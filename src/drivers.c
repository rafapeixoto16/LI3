#include "drivers.h"

DRIVERS hashTableDrivers[hashMaxDrivers];


struct driver {
    char *id;
    char *name;
    char *birth_day;
    char *gender;
    char *car_class;
    char *license_plate;
    char *city;
    char *account_creation;
    char *account_status;
};


unsigned int hashDrivers(char *id){
    return ((atoi(id)-1));
}


void initHashTableDrivers(){
    for (int i = 0; i < hashMaxDrivers; i++) {
        hashTableDrivers[i]=NULL;
    }
}


void printTableDrivers() {
    for (int i = 0; i < hashMaxDrivers; i++) {
        if (hashTableDrivers[i] != NULL) {
            printf("\t%s\n", ((hashTableDrivers[i])->id));
        } else
            printf("errou\n");
    }
}


bool hashTableInsertDrivers(DRIVERS driver){
    if(driver==NULL) return false;
    unsigned int index = hashDrivers(((driver)->id));
    if(hashTableDrivers[index]!=NULL){
        return false;
    }
    hashTableDrivers[index]=driver;
    return true;
}


DRIVERS hashTableLookupDrivers(char *id){
    unsigned int index = hashDrivers(id);
    if(hashTableDrivers[index]!=NULL && strcmp((hashTableDrivers[index])->id,id)==0)
        return hashTableDrivers[index];
    else
        return NULL;
}


void driversParsing(char *linha){

    DRIVERS driver1 = malloc(sizeof (struct driver ));
    char *head;
    char *tail;
    unsigned long i ;

    head = strtok_r(linha,";",&tail);
    i = strlen(head);
    head[i]='\0';
    driver1->id= strdup(head);

    head = strtok_r(NULL,";",&tail);
    i = strlen(head);
    head[i]='\0';
    driver1->name= strdup(head);

    head = strtok_r(NULL,";",&tail);
    i= strlen(head);
    head[i]='\0';
    driver1->birth_day= strdup(head);

    head = strtok_r(NULL,";",&tail);
    i = strlen(head);
    head[i]='\0';
    driver1->gender= strdup(head);

    head = strtok_r(NULL,";",&tail);
    i = strlen(head);
    head[i]='\0';
    driver1->car_class= strdup(head);

    head = strtok_r(NULL,";",&tail);
    i = strlen(head);
    head[i]='\0';
    driver1->license_plate= strdup(head);

    head = strtok_r(NULL,";",&tail);
    i = strlen(head);
    head[i]='\0';
    driver1->city= strdup(head);

    head = strtok_r(NULL,";",&tail);
    i = strlen(head);
    head[i]='\0';
    driver1->account_creation= strdup(head);

    head = strtok_r(NULL,"\n",&tail);
    i = strlen(head);
    head[i]='\0';
    driver1->account_status= strdup(head);

    bool bools =hashTableInsertDrivers(driver1);

    if(!bools){}

}


void printDriver(DRIVERS drivers){
    printf("id = %s, name = %s, birth_day = %s, gender = %s, car_class = %s, license_plate = %s, city = %s, accou_creation = %s, account_status = %s \n",
           drivers -> id,
           drivers -> name,
           drivers -> birth_day,
           drivers -> gender,
           drivers -> car_class,
           drivers -> license_plate,
           drivers -> city,
           drivers -> account_creation,
           drivers -> account_status);
}


char *lookupStatusDriver(char *id){
    unsigned int index = hashDrivers(id);
    return strdup(hashTableDrivers[index]->account_status);
}


char *lookupNomeDriver(char *id){
    unsigned int index = hashDrivers(id);
    return strdup(hashTableDrivers[index]->name);
}


char *lookupGeneroDriver(char *id){
    unsigned int index = hashDrivers(id);
    return strdup(hashTableDrivers[index]->gender);
}


int lookupIdadeDriver(char *id){
    char *temp2;
    unsigned int index = hashDrivers(id);
    char *data = hashTableDrivers[index]->birth_day;

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


double precoViagem(int distancia,char *id){
    double valor=0;
    DRIVERS tmp= hashTableLookupDrivers(id);

    if(strcmp("basic",tmp->car_class)==0)
        valor=3.25+(double )0.62*distancia;

    else if(strcmp("green",tmp->car_class)==0){
        valor=4.00+(double )0.79*distancia;
    }
    else if(strcmp("premium",tmp->car_class)==0)
        valor=5.20+(double )0.94*distancia;

    return valor;
}


void freeDrivers (){
    for (int i = 0; i < hashMaxDrivers; i++) {
        free(hashTableDrivers[i]->id);
        free(hashTableDrivers[i]->car_class);
        free(hashTableDrivers[i]->name);
        free(hashTableDrivers[i]->gender);
        free(hashTableDrivers[i]->account_status);
        free(hashTableDrivers[i]->birth_day);
        free(hashTableDrivers[i]->city);
        free(hashTableDrivers[i]->license_plate);
        free(hashTableDrivers[i]->account_creation);
    }
}
