#include "sys/ioctl.h"
#include "../includes/funcoesMenu.h"
#include "stdlib.h"
#include "../includes/funcoesUteis.h"
#include "../includes/printMenu.h"
#include "string.h"
#include "ctype.h"

#define tamanhoPrint 20

// --------------------------------------------
// Npaginas
// --------------------------------------------

int Npaginas(char **arrayString){
    int i = 0;
    while(arrayString[i] != NULL) i++;
    int n =i%20 == 0 ? i/20:(int )i/20+1;

    if(n*tamanhoPrint > tamanhoArrayPaginacao)
        n--;

    return n;
}


// --------------------------------------------
// paginacao
// --------------------------------------------

void paginacao(char** input){
    int pagina = 1,tmp, paginasMax = Npaginas(input);
    char string[BUFSIZ];

    while(true){
        if(input[0]==NULL){
            printf("     Zero elementos\n\n");
            printVoltar();
            funcaoVoltar();
            break;
        }
        printUpper();
        printIndice(input, tamanhoPrint * pagina - tamanhoPrint, tamanhoPrint * pagina - 1);
        printf("\n");
        printPaginacao2(pagina, paginasMax);

        scanf("%s",string);
        if((strcmp(string,"A") == 0 || strcmp(string,"a") == 0)) {
            if(pagina > 1)
                pagina--;

        }
        else if ((strcmp(string,"P") == 0 || strcmp(string,"p") == 0)) {
            if (pagina < paginasMax)
                pagina++;

        }
        else if (isInteger(string)){
            tmp = atoi(string);
            if (tmp >= 0 && tmp <= paginasMax)
                pagina = tmp;
            else if (tmp>pagina)
                pagina = paginasMax;
            else
                pagina = 0;
        }
        else if (strcmp(string,"V") == 0 || strcmp(string,"v") == 0)
            break;

        else printf("Opção Incorreta.\n");

        if (pagina < 1)
            pagina = 1;

        if (pagina >= paginasMax)
            pagina = paginasMax;

        clear_screen();
    }
}

// --------------------------------------------
// string4Array
// --------------------------------------------

void string4Array(char **Astring,char *string){
    int i = 0;
    char *tail;
    for (int j = 0; j < 100000; j++) {
        Astring [j] = NULL;
    }

    while (string != NULL){
        if(i>99999)
            break;
        char *head = strtok_r(string,"\n",&tail);
        if(head == NULL)
            break;
        string=tail;
        Astring[i]= strdup(head);
        i++;
    }
}

// --------------------------------------------
// printIndice
// --------------------------------------------

void printIndice(char **arrayString, int pInicial, int pFinal){
    int i = pInicial;
    for (; i <= pFinal && arrayString[i] != NULL; i++) {
        printf("    %s\n",arrayString[i]);
    }
}

// --------------------------------------------
// freeArray
// --------------------------------------------

void freeArray(char **arrayString){
    int i = 0;
    while(arrayString[i] != NULL) {
        free(arrayString[i]);
        i++;
    }
}

// --------------------------------------------
// dataMenu
// --------------------------------------------

char *dataMenu(char *stringPrint){
    char *lixo,data[BUFSIZ],*string=NULL;
    data[0]='\0';

    while (!verificaDate(data)){
        if(string != NULL){
            free(string);
            printf("Data invalida\n");
            lixo = NULL;
            data[0]='\0';
        }
        printf("%s\n",stringPrint);
        scanf("%s", data);
        printf("\n");
        string = strdup(strtok_r(data,"\n",&lixo));
        clear_screen();
    }
    return string;
}

// --------------------------------------------
// generoMenu
// --------------------------------------------

bool generoMenu(){
    char genero[100];

    while (strcmp("M",genero)!=0 && strcmp("F",genero)!=0 ){
        genero[0]='\0';
        clear_screen();
        printf("Insira o genero do user e condutor (F/M): \n");
        scanf("%s",genero);
        genero[1]='\0';
        genero[0]= toupper(genero[0]);
    }
    return strcmp("M",genero) == 0 ? 1 : 0;
}

// --------------------------------------------
// funcaoVoltar
// --------------------------------------------

void funcaoVoltar(){
    while(true){
        char termina;
        scanf("%c",&termina);

        if(termina =='v' || termina =='V')
            break;
    }
}

// --------------------------------------------
// funcaoCidade
// --------------------------------------------

void funcaoCidade(char *cidade){
    if (cidade != NULL){
        toLowerString(cidade);
        cidade[0] = toupper(cidade[0]);
    }
}

// --------------------------------------------
// exists
// --------------------------------------------

int exists(const char *fname)
{
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}

// --------------------------------------------
// tamanhoJanela
// --------------------------------------------

void tamanhoJanela(){
    clear_screen();

    int cols = 0;
    int rows = 0;
    tamanhoJanela(&cols,&rows);
}

// --------------------------------------------
// tamanhoJanelaAtual
// --------------------------------------------

void tamanhoJanelaAtual(int *cols,int *rows){
    struct winsize size;
    ioctl(1,TIOCGWINSZ,&size);
    *cols = size.ws_col;
    *rows = size.ws_row;

}