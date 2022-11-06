#include "parsing.h"

int main (int argc,char *argv[]){

    //Start
    //Parsing dos ficheiros(csv)
    parsing();

    //Operaçao em batch
    for (int i = 0; i <argc ; i++) {
        printf("argv[%d]= %s\n",argc,argv[i]);
    }
    return 0;
}
