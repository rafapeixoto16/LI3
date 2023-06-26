#include "../includes/funcoesUteis.h"
#include "ctype.h"

// --------------------------------------------
// dataToInt
// --------------------------------------------


int data2Int(char *data){
    char *aux;
    int dia =         atoi(strtok_r(data,"/" ,&aux));
    int mes = 100   * atoi(strtok_r(NULL,"/" ,&aux));
    int ano = 10000 * atoi(strtok_r(NULL,"/" ,&aux));

    return dia + mes + ano;
}

// --------------------------------------------
// toLowerString
// --------------------------------------------


void toLowerString(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

// --------------------------------------------
// VerificaDate
// --------------------------------------------


bool verificaDate (char *data){
    if(strlen(data) != 10)
        return false;

    if(data[2] != '/' || data[5] != '/')
        return false;

    for (int i = 0; data[i] < '\0'; i++) {
        if(isalpha(data[i]))
            return false;
    }
    char *dataV= strdup(data);
    char *aux;

    int dia =  atoi(strtok_r(dataV,"/" ,&aux));
    int mes =  atoi(strtok_r(NULL ,"/" ,&aux));
    int ano =  atoi(strtok_r(NULL ,"\0",&aux));

    if(dia > 31 || mes > 12 ||ano > 2022 ) {
        free(dataV);
        return false;
    }
    free(dataV);
    return true;
}


// --------------------------------------------
// isInteger
// --------------------------------------------

bool isInteger(char *val){
    if(!isNumber(val)){
        double valor  = atof(val);
        int truncated = (int)valor;
        return (valor == truncated);
    }
    return false;
}

// --------------------------------------------
// isnumber
// --------------------------------------------

bool isNumber(char *head){
    int i = 0;
    if(strcmp(head,"nan")==0)
        return 1;

    while(head[i] != '\0' ) {
        if (!((isdigit(head[i])) || head[i] == '.'))
            return 1;
        i++;
    }
    return 0;
}

// --------------------------------------------
// tamanhoEqual0
// --------------------------------------------

bool tamanhoEqual0(char *head){
    return strlen(head) > 0 ? false : true;
}

// --------------------------------------------
// calculaIdade
// --------------------------------------------

int calculaIdade(char *data){
    char *temp2;
    int idade;
    int dia = dataDiaAtual, mes = dataMesAtual, ano = dataAnoAtual;
    int diaAniv = atoi(strtok_r(data, "/", &temp2));
    int mesAniv = atoi(strtok_r(NULL, "/", &temp2));
    int anoAniv = atoi(strtok_r(NULL, "/", &temp2));

    idade = ano-anoAniv-1;

    if( (mesAniv<mes) || (mesAniv==mes && diaAniv<=dia))
        idade = idade + 1;

    return idade;
}


// --------------------------------------------
// DaraParaIntDMA
// --------------------------------------------

void DataParaIntDMA (char *string,int *diaAtual,int *mesAtual ,int *anoAtual ){

    char *temp;

    char *diaAtualS = strtok_r(string, "/" , &temp);
    char *mesAtualS = strtok_r(NULL, "/" , &temp);
    char *anoAtualS = strtok_r(NULL, "\0", &temp);

    *diaAtual = atoi(diaAtualS);
    *mesAtual = atoi(mesAtualS);
    *anoAtual = atoi(anoAtualS);
}

// --------------------------------------------
// usernameParaInt
// --------------------------------------------

int usernameParaInt (char *nome){
    char *nomeC = nome;
    int tamanho = 0,i=0;
    int tamanhomax =(int )strlen(nome);
    while (i<tamanhomax){
        tamanho+=(int)*nomeC;
        nomeC++;
        i++;
    }
    return tamanho;
}


// --------------------------------------------
// calculaIdadeInt
// --------------------------------------------

int calculaIdadeInt(int aniv){
    int idade;
    int dia = dataDiaAtual, mes = dataMesAtual, ano = dataAnoAtual;

    int anoAniv = aniv/10000;
    int mesAniv = (aniv - anoAniv*10000)/100;
    int diaAniv = (aniv - ((anoAniv*10000)+(mesAniv*100)));

    idade = ano-anoAniv-1;

    if(mesAniv < mes || (mesAniv == mes && diaAniv <= dia))
        idade = idade+1;

    return idade;
}

// --------------------------------------------
// int2Data
// --------------------------------------------

char *int2Data(int dataNum){
    char copia1[12];
    int dia,mes,ano;
    ano=(int)dataNum/10000;
    dataNum-=(ano*10000);
    mes=(int)dataNum/100;
    dataNum-=(mes*100);
    dia =dataNum;

    snprintf(copia1, 11, "%02d/%02d/%04d",
             dia,
             mes,
             ano);
    return strdup(copia1);
}

// --------------------------------------------
// avancaDate
// --------------------------------------------

void avancaDate(int *data){
    int dia = 0,mes = 0,ano = 0;

    ano    = (int)*data/10000;
    *data -= (ano*10000);
    mes    = (int)*data/100;
    *data -=(mes*100);
    dia    = (int )*data;

    if (dia != 31)
    {
        dia++;
    }


    else if(mes != 12)
    {
        dia =01;
        mes++;
    }

    else
    {
        dia = 01;
        mes = 01;
        ano++;
    }

    mes *= 100;
    ano *= 10000;
    *data = dia + mes + ano;
}

// --------------------------------------------
// verificaDataQueries
// --------------------------------------------

void verificaDataQueries(int *dataInicio,int *dataFim ,int *primeiraData, int *ultimaData){
    if (*dataFim < *dataInicio || *dataFim < *primeiraData || *dataInicio > *ultimaData) {
        *dataFim    = -1;
        *dataInicio = -1;
        return;
    }

    if(*dataInicio < *primeiraData )
    {
        *dataInicio = *primeiraData;
    }

    if(*dataFim > *ultimaData)
    {
        *dataFim = *ultimaData;
    }
}
