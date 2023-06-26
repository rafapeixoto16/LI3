#include "../includes/drivers.h"
#include "../includes/array.h"


struct driver {
    char *id;
    char *name;
    char *birth_day;
    bool gender;
    char *car_class;
    int account_creation;
    bool account_status;
};


// --------------------------------------------
// driversParsing
// --------------------------------------------

void driversParsing(char *linha, void *arrayD){
    ARRAYDinamico hashtable = arrayD;
    DRIVERS driver1 = malloc(sizeof (struct driver));

    char *tail = NULL;
    int i;

    i = idDriver (strtok_r(linha,";", &tail), driver1);

    if(i)
        return;

    i = nomeDriver (strtok_r(NULL ,";", &tail), driver1);

    if(i)
        return;

    i = dataAniDriver (strtok_r(NULL ,";", &tail),driver1);

    if(i)
        return;

    i = generoDriver (strtok_r(NULL,";",&tail),driver1);

    if(i)
        return;

    i = typeCarDriver (strtok_r(NULL,";",&tail),driver1);

    if(i)
        return;

    i = licensePlateDriver(strtok_r(NULL,";",&tail),driver1);

    if(i)
        return;

    i = cidadeDriver (strtok_r(NULL,";",&tail),driver1);

    if(i)
        return;

    i = dataCriacaoDriver(strtok_r(NULL,";",&tail),driver1);

    if(i)
        return;

    i = estadoContaDriver(strtok_r(NULL,"\n",&tail),driver1);

    if(i)
        return;

    arrayAdd(hashtable,driver1, strdup(driver1->id));
}

// --------------------------------------------
// printDriver
// --------------------------------------------

void printDriver(DRIVERS drivers){
    printf("id = %s, name = %s, birth_day = %s, gender = %s, car_class = %s, accou_creation = %s, account_status = %s \n",
           drivers -> id,
           drivers -> name,
           drivers -> birth_day,
           drivers -> gender == true ? "M" : "F" ,
           drivers -> car_class,
           int2Data(drivers -> account_creation),
           drivers -> account_status == 1 ? "active" :"inactive");
}

// --------------------------------------------
// lookupStatusDriver
// --------------------------------------------

bool lookupStatusDriver(DRIVERS driver1) {
    if(driver1==NULL){
        return false;
    }

    bool retorno = driver1 -> account_status;
    return retorno;
}

// --------------------------------------------
// lookupNomeDriver
// --------------------------------------------

char *lookupNomeDriver(DRIVERS driver1){
    return strdup(driver1->name);
}

// --------------------------------------------
// lookupGeneroDriver
// --------------------------------------------

bool lookupGeneroDriver(DRIVERS driver1){
    bool retorno = driver1->gender;
    return retorno;
}

// --------------------------------------------
// lookupIdadeDriver
// --------------------------------------------

int lookupIdadeDriver(DRIVERS driver1){
    DRIVERS tmp = driver1;
    char *data = strdup(tmp->birth_day);
    int  idade = calculaIdade(data);free(data);
    return idade;
}

// --------------------------------------------
// lookupDataCriacaoDriver
// -------------------------------------------

int lookupDataCriacaoDriver(DRIVERS drivers){
    return drivers->account_creation;
}
// --------------------------------------------
// precoViagem
// --------------------------------------------

double precoViagem(int distancia,DRIVERS driver1){
    double valor=0;

    if(strcmp("basic",driver1->car_class)==0)
        valor=3.25+(double )0.62 * distancia;

    else if(strcmp("green",driver1->car_class)==0){
        valor=4.00+(double )0.79 * distancia;
    }
    else if(strcmp("premium",driver1->car_class)==0)
        valor=5.20+(double )0.94 * distancia;

    return valor;
}

// --------------------------------------------
// informacoesBasicasDriver
// --------------------------------------------

void informacoesBasicasDriver(DRIVERS driver,char *nome,bool *genero,int *idade){
    if(driver != NULL){
        *nome =  *lookupNomeDriver(driver);
        *genero = lookupGeneroDriver(driver);
        *idade = lookupGeneroDriver(driver);
    }
}

// --------------------------------------------
// idDriver
// --------------------------------------------

int idDriver(char *id,DRIVERS drivers){
    if(tamanhoEqual0 (id))
    {
        free(id);
        return 1;
    }
    id[strlen(id)] ='\0';
    drivers -> id = strdup(id);
    return 0;
}

// --------------------------------------------
// nomeDriver
// --------------------------------------------

int nomeDriver (char *nome,DRIVERS drivers){
    if(tamanhoEqual0(nome)){
        freeDriverId(drivers);
        return 1;
    }

    nome[strlen(nome)] = '\0';
    drivers -> name = strdup(nome);
    return 0;
}

// --------------------------------------------
// dataAniDriver
// --------------------------------------------

int dataAniDriver(char *data,DRIVERS drivers){
    data[strlen(data)] ='\0';

    if(!verificaDate(data)){
        freeDriverName(drivers);
        return 1;
    }

    drivers -> birth_day = strdup(data);
    return 0;
}

// --------------------------------------------
// generoDriver
// --------------------------------------------

int generoDriver(char *genero,DRIVERS drivers){
    genero[strlen(genero)] ='\0';

    if(tamanhoEqual0(genero)){
        freeDriverBirthDay(drivers);
        return 1;
    }

    drivers -> gender = strcmp("M",genero) == 0 ? true : false;
    return 0;
}

// --------------------------------------------
// typeCarDriver
// --------------------------------------------

int typeCarDriver (char *tipoCarro,DRIVERS drivers){
    tipoCarro[strlen(tipoCarro)] = '\0';
    toLowerString(tipoCarro);

    if(!(strcmp(tipoCarro,"green")==0 || strcmp(tipoCarro,"premium")==0 || strcmp(tipoCarro,"basic")==0)){
        freeDriverBirthDay(drivers);
        return 1;
    }

    drivers->car_class = strdup(tipoCarro);
    return 0;
}

// --------------------------------------------
// lincensePlateDriver
// --------------------------------------------

int licensePlateDriver (char *lincense,DRIVERS drivers){
    lincense[strlen(lincense)]='\0';

    if(tamanhoEqual0(lincense)){
        freeDriverCarClass(drivers);
        return 1;
    }
    return 0;
}

// --------------------------------------------
// cidadeDriver
// --------------------------------------------

int cidadeDriver (char *cidade,DRIVERS drivers){
    cidade[strlen(cidade)]='\0';

    if(tamanhoEqual0(cidade)){
        freeDriverCarClass(drivers);
        return 1;
    }
    return 0;
}

// --------------------------------------------
// dataCriacaoDriver
// --------------------------------------------

int dataCriacaoDriver(char *dataCriacao ,DRIVERS drivers){
    dataCriacao[strlen(dataCriacao)]='\0';

    if(!verificaDate(dataCriacao)) {
        freeDriverCity(drivers);
        return 1;
    }

    drivers -> account_creation = data2Int(dataCriacao);
    return 0;
}

// --------------------------------------------
// estadoContaDriver
// --------------------------------------------

int estadoContaDriver (char *estadoConta,DRIVERS drivers){

    if(estadoConta==NULL){
        freeAcountCreation(drivers);
        return 1;
    }

    estadoConta[strlen(estadoConta)]='\0';
    toLowerString(estadoConta);
    if(!(strcmp("active",estadoConta) == 0 || strcmp("inactive",estadoConta) == 0)){
        freeAcountCreation(drivers);
        return 1;
    }
    drivers->account_status = strcmp("active",estadoConta) == 0 ? true : false;
    return 0;
}


// --------------------------------------------
// freeDriver
// --------------------------------------------

void freeDriver (DRIVERS driver){
    free  (driver->car_class);
    free         (driver->id);
    free  (driver->birth_day);
    free       (driver->name);
    free             (driver);
}

// --------------------------------------------
// freeDriverId
// --------------------------------------------

void freeDriverId (DRIVERS drivers){
    free    (drivers->id);
    free        (drivers);
}

// --------------------------------------------
// freeDriverName
// --------------------------------------------

void freeDriverName (DRIVERS drivers){
    free    (drivers->name);
    free      (drivers->id);
    free          (drivers);
}

// --------------------------------------------
// freeDriverBirthday
// --------------------------------------------

void freeDriverBirthDay (DRIVERS drivers){
    free (drivers->birth_day);
    free      (drivers->name);
    free        (drivers->id);
    free            (drivers);
}

// --------------------------------------------
// freeDriverCarClass
// --------------------------------------------

void freeDriverCarClass (DRIVERS drivers){
    free (drivers->car_class);
    free (drivers->birth_day);
    free      (drivers->name);
    free        (drivers->id);
    free            (drivers);
}

// --------------------------------------------
// freeDriverCity
// --------------------------------------------

void freeDriverCity (DRIVERS drivers){
    free (drivers->car_class);
    free (drivers->birth_day);
    free      (drivers->name);
    free        (drivers->id);
    free            (drivers);
}

// --------------------------------------------
// freeAcountCreation
// --------------------------------------------

void freeAcountCreation (DRIVERS drivers){
    free (drivers->car_class);
    free (drivers->birth_day);
    free      (drivers->name);
    free        (drivers->id);
    free            (drivers);
}
