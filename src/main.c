#include "parsing.h"
#include "parsingInput.h"

int main (int argc,char *argv[]){
    //Start

    char *dataset=argv[1];
    char *input =argv[2];

    if(argc<2){
        printf("Argumentos insufecientes\n");
        return 0;
    }

    if(dataset==NULL || input==NULL)
        //segunda fase
        return 0;

    //Parsing dos ficheiros(csv)
    parsing(dataset);

    //Parsing do Input (input.txt)
    parsingInput(input);

    //Free dataset
    freeDataset();

    return 0;
}
