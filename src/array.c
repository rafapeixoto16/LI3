#include "../includes/array.h"
#include <stdbool.h>

enum tipo{
typeDRIVERS,
typeRIDES,
typeUsers,
typeStatusD,
typeStatusU,
};


struct array {
    int size;
    int capUsed;
    TYPEarray type;
    void **array;
};

// --------------------------------------------
// arrayCreate
// --------------------------------------------


ARRAYDinamico arrayCreate(int size ,int tipo){
    ARRAYDinamico s = malloc(sizeof (struct array));
    s->size    = size;
    s->capUsed = 0;
    s->type    = tipoRetorna(tipo);
    s->array   = malloc(s->size * sizeof(void *));

    return s;
}

// --------------------------------------------
// tipoRetorna
// --------------------------------------------

TYPEarray tipoRetorna(int tipo){
    if(tipo==1)
        return typeDRIVERS;

    else if (tipo == 2)
        return typeUsers;

    else if (tipo == 3)
        return typeRIDES;

    else if(tipo == 4)
        return typeStatusU;
    else
        return typeStatusD;

}

// --------------------------------------------
// hashInitNull
// --------------------------------------------


void hashInitNull (ARRAYDinamico hash,int comeco){
    for (int i = comeco; i < hash->size; i++) {
        hash->array[i] = NULL;
    }
}

// --------------------------------------------
// hashFuncionDR
// --------------------------------------------

unsigned int hashFuncionDR (char *id) {
    return atoi(id)-1;
}

// --------------------------------------------
// arrayAdd
// --------------------------------------------

bool arrayAdd (ARRAYDinamico hash, void *dado, char *index)
{
    if(dado==NULL){
        return false;
    }

    if(hash->type == typeDRIVERS || hash->type == typeStatusD)
    {
        unsigned int posicao = hashFuncionDR(index);

        if(hash->type == typeDRIVERS)
            free(index);

        if (hash->size <= hash->capUsed) {
            hash->array = realloc(hash->array, 2 * hash->size * sizeof(void *));
            int comeco = hash->size;
            hash->size *= 2;

            hashInitNull(hash, comeco);

        }

        while (posicao >= hash->size)
        {
            hash->array = realloc(hash->array, 2 * hash->size * sizeof(void *));
            int comeco = hash->size;
            hash->size *= 2;

            hashInitNull(hash, comeco);
        }

        if (hash->array[posicao] == NULL)
        {
            hash -> array[posicao] =dado;
            hash -> capUsed++;
        }
        return true;
    }

    else if(hash->type == typeRIDES)
    {
        if(index!=NULL)
            free(index);

        if (hash->size <= hash->capUsed)
        {
            hash->array = realloc(hash->array, 2 * hash->size * sizeof(void *));
            int comeco = hash->size;
            hash->size *= 2;
            hashInitNull(hash, comeco);
        }

        hash -> array[hash->capUsed] = dado;
        hash -> capUsed++;
    }

    else if( hash->type == typeUsers || hash->type ==typeStatusU){
        hash -> capUsed ++;
        unsigned int posicao = hashLLigada (index,hash->size);
        hash->array[posicao] = dado;

        return true;
    }

    return false;
}

// --------------------------------------------
// arrayDelete
// --------------------------------------------

void arrayDelete (ARRAYDinamico hash)
{
    if(hash->type == typeDRIVERS)
    {
        DRIVERS tmp;

        for (int i = 0; i < hash->size; i++)
        {
            if(hash -> array [i] != NULL)
            {
                tmp = hash->array[i];
                freeDriver(tmp);
            }
        }
        free(hash->array);
        free(hash);
    }

    else if(hash->type == typeRIDES)
    {
        RIDES tmp;

        for (int i = 0; i < hash->size; i++)
        {
            if(hash -> array [i] != NULL)
            {
                tmp = hash->array[i];
                freeRide(tmp);
            }
        }
        free(hash->array);
        free(hash);
    }

    else if( hash->type == typeUsers)
    {
        USERS tmp;

        for (int i = 0; i < hash->size; i++)
        {
            if(hash -> array [i] != NULL)
            {
                tmp = hash -> array [i];
                freeUser(tmp);
            }
        }
        free(hash->array);
        free(hash);
    }

    else if(hash -> type == typeStatusU)
    {
        for (int i = 0; i < hash->size; i++)
        {
            if(hash -> array [i] != NULL) {
                freeUserStatus(hash->array [i]);
            }
        }

        free(hash->array);
        free(hash);
    }

    else if( hash->type == typeStatusD)
    {
        statusDriver tmp;

        for (int i = 0; i < hash->size; i++)
        {
            if(hash -> array [i] != NULL) {
                tmp = hash->array[i];
                freeDriverStatus(tmp);
            }
        }
        free(hash->array);
        free(hash);
    }
}

// --------------------------------------------
// printArray
// --------------------------------------------

void printArray (ARRAYDinamico hash){
    if(hash->type == typeRIDES) {
        RIDES tmp;
        for (int i = 0; i < hash->size; i++) {
            if(hash->array[i] == NULL){
                continue;
            }
            tmp = hash->array[i];
            printRide(tmp);

        }
    }

    else if(hash->type == typeDRIVERS) {
        DRIVERS tmp;
        for (int i = 0; i < hash->size; i++) {
            if(hash->array[i] == NULL){
                continue;
            }
            tmp = hash->array[i];
            printDriver(tmp);
        }
    }

    else if(hash->type == typeUsers) {
        USERS tmp;
        for (int i = 0; i < hash->size; i++) {
            if (hash->array[i] == NULL) {
                continue;
            }
            tmp = hash->array[i];
            printUsers(tmp);
        }
    }

    else if (hash->type == typeStatusD)
    {
        for (int i = 0; i < hash->size; i++)
        {
            if(hash->array[i] == NULL){
                continue;
            }
            printDriverStatus(hash->array[i]);
        }
    }
    else if(hash->type == typeStatusU)
    {
        for (int i = 0; i < hash->size; i++)
        {
            if(hash->array[i] == NULL){
                continue;
            }
            printUserStatus(hash->array[i]);
        }
    }
}

// --------------------------------------------
// hashLLigada
// --------------------------------------------


unsigned int hashLLigada(char *username, int size)
{
    unsigned int hashTableUserV = 5381;
    int c,i=0;

    while (i < strlen(username))
    {
        c=(int)*username;
        hashTableUserV = ((hashTableUserV << 5) + hashTableUserV) + c;
        username++;
    }
    return (hashTableUserV % size);//tamanho atual do array
}

// --------------------------------------------
// parsingStatus
// --------------------------------------------

void parsingStatus (ARRAYDinamico rides, ARRAYDinamico statusD, ARRAYDinamico statusU,ARRAYDinamico driver,ARRAYDinamico user)
{
    hashInitNull (statusD,0);
    hashInitNull (statusU,0);

    for (int i = 0; i < rides->size && rides->array[i] != NULL; i++)
    {
        char *nomeUser  = lookupUserRides(rides->array[i]);
        char *idDriver  = lookupDriverRides(rides->array[i]);
        DRIVERS driver1 = posicaoTableD(driver, idDriver);
        USERS user1 = posicaoTableU(user, nomeUser);

        if(driver1 != NULL && user1 == NULL)
        {
            bool statusDriver2 = lookupStatusDriver(posicaoTableD(driver, idDriver));
            int data = lookupDateRides(rides->array[i]);
            double scoreD = lookupScoreDriverRides(rides->array[i]);
            int distancia = lookupDistanceRides(rides->array[i]);
            unsigned int indexDriver = hashFuncionDR(idDriver);
            double dinheiroG = lookupTipRides(rides->array[i]) + precoViagem(distancia,driver->array[indexDriver]);

            if (statusDriver2)
            {
                if (statusD->array[indexDriver] == NULL)
                {
                    statusDriver statusDriver1 = statusDParsing(dinheiroG, scoreD, idDriver, data);
                    arrayAdd(statusD, statusDriver1, idDriver);
                } else if (statusD->array[indexDriver] != NULL)
                {
                    incrementaDriver(statusD->array[indexDriver], dinheiroG, scoreD, data);
                    free(idDriver);
                }
            } else
                free(idDriver);

            free(user1);
        }


        else if (driver1 != NULL && user1 != NULL)
        {
            bool statusDriver2 = lookupStatusDriver(posicaoTableD(driver, idDriver));
            bool statusUser2 = lookupStatusUser(posicaoTableU(user, nomeUser), nomeUser);
            int data = lookupDateRides(rides->array[i]);
            double scoreU = lookupScoreUserRides(rides->array[i]);
            double scoreD = lookupScoreDriverRides(rides->array[i]);
            int distancia = lookupDistanceRides(rides->array[i]);
            unsigned int indexDriver = hashFuncionDR(idDriver);
            unsigned int indexUser = hashLLigada(nomeUser, tamanhoInicialU);
            double dinheiroG = lookupTipRides(rides->array[i]) +
                               precoViagem(lookupDistanceRides(rides->array[i]),
                                           driver->array[indexDriver]);
            if (statusDriver2)
            {
                if (statusD->array[indexDriver] == NULL)
                {
                    statusDriver statusDriver1 = statusDParsing(dinheiroG, scoreD, idDriver, data);
                    arrayAdd(statusD, statusDriver1, idDriver);
                } else if (statusD->array[indexDriver] != NULL)
                {
                    incrementaDriver(statusD->array[indexDriver], dinheiroG, scoreD, data);
                    free(idDriver);
                }
            } else
                free(idDriver);
            if (statusUser2)
            {
                if (statusU->array[indexUser] != NULL &&
                    pertencaLista(statusU->array[indexUser], nomeUser, dinheiroG, scoreU, data, distancia))
                    free(nomeUser);
                else
                {
                    statusUSER statusUser1 = statusUParsing(statusU, dinheiroG, scoreU, nomeUser, data, distancia);
                    arrayAdd(statusU, statusUser1, nomeUser);
                }
            } else
                free(nomeUser);
        }
        else{
            free(nomeUser);
            free(idDriver);
        }
    }
}

// --------------------------------------------
// tamanhoHash
// --------------------------------------------

int tamanhoHash (ARRAYDinamico table){
    return table->size;
}

// --------------------------------------------
// posicaoTableD
// --------------------------------------------

DRIVERS posicaoTableD (ARRAYDinamico hash,char *id)
{
    unsigned int index = hashFuncionDR(id);
    if(index > hash->size)
        return NULL;
    if(hash->array[index]!=NULL)
        return hash->array[index];
    return NULL;
}

// --------------------------------------------
// posicaoTableDriverInt
// --------------------------------------------

DRIVERS posicaoTableDriverInt(ARRAYDinamico hash,int id){
    id--;
    if(id > hash->size)
        return NULL;
    if(hash->array[id]!=NULL)
        return hash->array[id];
    return NULL;
}

// --------------------------------------------
// posicaoTableSdriver
// --------------------------------------------


statusDriver posicaoTableSdriver(ARRAYDinamico hash,char *id)
{
    unsigned int index = hashFuncionDR(id);
    return hash->array[index];
}

// --------------------------------------------
// posicaoTableSdriverIndex
// --------------------------------------------

statusDriver posicaoTableSdriverIndex(ARRAYDinamico hash ,int index){
    return hash->array[index];
}

// --------------------------------------------
// posicaoTableU
// --------------------------------------------


USERS posicaoTableU(ARRAYDinamico hash,char *id)
{
    unsigned int index = hashLLigada(id,hash->size);
    if(hash -> array [index] == NULL){
        return NULL;
    }
    return hash -> array [index];
}

// --------------------------------------------
// posicaoTableSusers
// --------------------------------------------


statusUSER posicaoTableSusers(ARRAYDinamico hash, char *id)
{
    unsigned int index = hashLLigada(id,hash->size);
    return hash -> array [index];
}

// --------------------------------------------
// posicaoTableSUsersIndex
// --------------------------------------------


statusUSER posicaoTableSUsersIndex(ARRAYDinamico hash, int numero){
    return hash->array[numero];
}


// --------------------------------------------
// posicaoTableRides
// --------------------------------------------


RIDES posicaoTableRides(ARRAYDinamico rides,int posicao)
{
    if(posicao  >=  0)
        return rides->array[posicao] == NULL ? NULL : rides->array[posicao];
    return NULL;
}


// --------------------------------------------
// tamanhoOcupadoArray
// --------------------------------------------


int tamanhoOcupadoArray(ARRAYDinamico ride){
    return ride->capUsed;
}

// --------------------------------------------
// ordena
// --------------------------------------------


void ordena(ARRAYDinamico rideTable){
    quicksortData(rideTable->array,rideTable->capUsed);
}

// --------------------------------------------
// procuraDataBinary
// --------------------------------------------


int procuraDataBinary(ARRAYDinamico ride,int dataPesquisada,int inicio,int tamanhoMax){
    if(tamanhoMax < inicio)
        return -1;

    int k = inicio +((tamanhoMax-inicio)/2);
    if(lookupDateRides(ride -> array[k])==dataPesquisada)
        return k;
    else if(lookupDateRides(ride -> array[k]) < dataPesquisada)
        return procuraDataBinary(ride,dataPesquisada,k+1,tamanhoMax);
    else
        return procuraDataBinary(ride,dataPesquisada,inicio,k-1);
}

// --------------------------------------------
// procuraPosicaoInicial
// --------------------------------------------


int procuraPosicaoInicial(ARRAYDinamico table ,int dataPesquisada){
    int index = procuraDataBinary(table,dataPesquisada,0,table->capUsed-1);
    int datapesquisar = dataPesquisada;

    while(index == -1) {
       avancaDate(&datapesquisar);
       index = procuraDataBinary(table,datapesquisar,0,table->capUsed-1);
    }

    while(index != 0 && lookupDateRides(table->array[index]) == lookupDateRides(table->array[index-1]))
            index--;

    return index;
}

// --------------------------------------------
// quicksortDistanciaViagens
// --------------------------------------------


void quicksortDistanciaViagens(void **hash,int tamanho){
    if(tamanho < 2) return;

    int pivot = lookupDistanceRides(hash[(int )tamanho/2]);

    int i,j;

    for (i=0,j=tamanho-1;;i++,j--)
    {
        while ((int )lookupDistanceRides(hash[i]) < pivot) i++;
        while (lookupDistanceRides(hash[j]) > pivot) j--;

        if(i>=j)
            break;

        swapElem(hash,i,j);
    }
    quicksortDistanciaViagens(hash,i);
    quicksortDistanciaViagens(&hash[i],tamanho - i);
}


// --------------------------------------------
// quicksortData
// --------------------------------------------


void quicksortData(void **hash,int tamanho){
    if(tamanho < 2) return;
    int pivot = lookupDateRides(hash[tamanho/2]);
    int i,j;

    for (i=0,j=tamanho-1;;i++,j--){
        while (lookupDateRides(hash[i]) < pivot) i++;
        while (lookupDateRides(hash[j]) > pivot) j--;

        if(i >= j)
            break;

        swapElem(hash,i,j);
    }
    quicksortData(hash,i);
    quicksortData(&hash[i],tamanho - i);
}


// --------------------------------------------
// posicaoTableU
// --------------------------------------------


void quicksortIdviagem(void **hash,int tamanho){
    if(tamanho < 2) return;

    int pivot = lookupIdViagemInt(hash[tamanho/2]);
    int i,j;

    for (i=0,j=tamanho-1;;i++,j--)
    {
        while((lookupIdViagemInt(hash[i])) < pivot) i++;
        while ((lookupIdViagemInt(hash[j])) > pivot) j--;

        if(i>=j)
            break;

        swapElem(hash,i,j);
    }
    quicksortIdviagem(hash,i);
    quicksortIdviagem(&hash[i],tamanho - i);
}

// --------------------------------------------
// quicksortAvalMed
// --------------------------------------------


void quicksortAvalMed(void **array,int tamanho){
    if(tamanho < 2) return;

    double pivot = lookupAvalMedDriver(array[tamanho/2]);

    int i,j;

    for (i=0,j=tamanho-1;;i++,j--)
    {
        while ((lookupAvalMedDriver(array[i])) > pivot) i++;
        while ((lookupAvalMedDriver(array[j]))  < pivot) j--;

        if(i>=j)
            break;

        swapElem(array,i,j);
    }
    quicksortAvalMed(array,i);
    quicksortAvalMed(&array[i],tamanho - i);
}

// --------------------------------------------
// quicksortDataDriver
// --------------------------------------------


void quicksortDataDriver(void **array,int tamanho){
    if(tamanho < 2) return;

    double pivot = lookupDataStatusDriver(array[tamanho/2]);

    int i,j;

    for (i=0,j=tamanho-1;;i++,j--)
    {
        while ((lookupDataStatusDriver(array[i])) > pivot) i++;
        while ((lookupDataStatusDriver(array[j])) < pivot) j--;

        if(i>=j)
            break;

        swapElem(array,i,j);
    }
    quicksortDataDriver(array,i);
    quicksortDataDriver(&array[i],tamanho - i);
}

// --------------------------------------------
// quicksortIdStatusDriver
// --------------------------------------------


void quicksortIdStatusDriver(void **array,int tamanho){
    if(tamanho < 2) return;

    int pivot = lookupIdStatusDriver(array[tamanho/2]);

    int i,j;

    for (i=0,j=tamanho-1;;i++,j--)
    {
        while ((lookupIdStatusDriver(array[i])) < pivot) i++;
        while ((lookupIdStatusDriver(array[j])) > pivot) j--;

        if(i>=j)
            break;

        swapElem(array,i,j);
    }
    quicksortIdStatusDriver(array,i);
    quicksortIdStatusDriver(&array[i],tamanho - i);
}

// --------------------------------------------
// quicksortDataCreationDriver
// --------------------------------------------


void quicksortDataCreationDriver(void **array,int tamanho,ARRAYDinamico driver){
    if (tamanho < 2) return;

    int pivot = lookupDataCriacaoDriver(posicaoTableDriverInt(driver, lookupDriverIntRides(array[tamanho/2])));

    int i, j;
    for (i = 0, j = tamanho - 1;; i++, j--) {
        while (lookupDataCriacaoDriver(posicaoTableDriverInt(driver, lookupDriverIntRides(array[i]))) < pivot) i++;

        while (lookupDataCriacaoDriver(posicaoTableDriverInt(driver, lookupDriverIntRides(array[j]))) > pivot) j--;

        if (i >= j)
            break;

        swapElem(array,i,j);
    }
    quicksortDataCreationDriver(array, i,driver);
    quicksortDataCreationDriver(&array[i], tamanho - i,driver);
}

// --------------------------------------------
// quicksortDataCreationUser
// --------------------------------------------


void quicksortDataCreationUser (void **array,int tamanho,ARRAYDinamico user){
    if (tamanho < 2) return;

    char *username = lookupUserRides(array[tamanho/2]);
    int pivot      = lookupDatacriacaoUser(posicaoTableU(user,username),username);

    free(username);
    int i, j;
    char *username1 = NULL;

    for (i = 0, j = tamanho - 1;; i++, j--) {
        username1 = lookupDriverRides(array[i]);
        i++;
        while (lookupDatacriacaoUser(posicaoTableU(user,username1),username1 ) < pivot && i < tamanho-1) {
            i++;
            if(i < tamanho ) {
                free(username1);
                username1 = lookupDriverRides(array[i]);
            }
        }
        if(username1!=NULL)
            free(username1);

        username1 = lookupDriverRides(array[j]);
        j--;

        while (lookupDatacriacaoUser(posicaoTableU(user,username1),username1) > pivot && j > -1) {
            j--;

            if(j>=0){
                free(username1);
                username1 = lookupDriverRides(array[j]);
            }
        }

        if(username1 != NULL)
            free(username1);

        if (i >= j)
            break;

        swapElem(array,i,j);

    }
    quicksortDataCreationUser(array, i,user);
    quicksortDataCreationUser(&array[i], tamanho - i,user);
}


// --------------------------------------------
// swap
// --------------------------------------------


void swap(ARRAYDinamico array,int i,int menor){
    void *tmp = array->array[i];
    array->array[i]=array->array[menor];
    array->array[menor]= tmp;
}

// --------------------------------------------
// arrayFree
// --------------------------------------------


void arrayFree(ARRAYDinamico table){
    free(table->array);
}

// --------------------------------------------
// array
// --------------------------------------------


void *array(ARRAYDinamico table){
    return table->array;
}

// --------------------------------------------
// swapElem
// --------------------------------------------


void swapElem(void **array,int i ,int j){
    void *tmp  = array[i];
    array [i]  = array[j];
    array [j]  = tmp;
}

// --------------------------------------------
// *arrayPosicao
// --------------------------------------------

void *arrayPosicao(ARRAYDinamico table ,int i){
    return table->array+i;
}