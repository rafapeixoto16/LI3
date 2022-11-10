#include "parsing.h"

int main (int argc,char *argv[]){
    //Start

    char *dataset=argv[1];
    char *input =argv[2];

    if(argc<2){
        printf("argumentos insufecientes\n");
        return 0;
    }

    if(dataset==NULL)
        return 1;

    //Parsing dos ficheiros(csv)
    parsing(dataset);

    //Operaçao em batch

    return 0;
}
