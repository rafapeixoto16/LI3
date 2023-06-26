#include "../includes/statusDriver.h"
#include "../includes/array.h"

struct statsD{
    char *id;
    int  viagemMaisRD;
    double  scoreDriverT;
    int  numeroViagem;
    double dinheiroGanho;
};

// --------------------------------------------
// statusDParsing
// --------------------------------------------


statusDriver statusDParsing ( double dinheiroG, double score, char *id,int viagem){
    statusDriver statusDriver1 = malloc(sizeof (struct statsD));
    statusDriver1 -> id = id;
    statusDriver1 -> dinheiroGanho = dinheiroG;
    statusDriver1 -> numeroViagem = 1;
    statusDriver1 -> viagemMaisRD = viagem;
    statusDriver1 -> scoreDriverT = score;

    return statusDriver1;
}

// --------------------------------------------
// incrementaDriver
// --------------------------------------------


void incrementaDriver (statusDriver sD, double  dinheiroG, double scoreD, int data) {
        sD->dinheiroGanho =sD->dinheiroGanho + dinheiroG;
        sD->scoreDriverT += scoreD;
        sD->viagemMaisRD = sD->viagemMaisRD > data ? sD->viagemMaisRD : data;
        sD->numeroViagem++;
}

// --------------------------------------------
// freeDriverStatus
// --------------------------------------------


void freeDriverStatus(statusDriver sD){
    free(sD->id);
    free(sD);
}

// --------------------------------------------
// printDriverStatus
// --------------------------------------------


void printDriverStatus (statusDriver sD) {
    printf("%s ----  %f  ---- %i\n", sD->id, sD->dinheiroGanho,sD->numeroViagem);
}


// --------------------------------------------
// informacoesBasicasStatusDriver
// --------------------------------------------


void informacoesBasicasStatusDriver(statusDriver driver, double *dinheiro, double *avaliacao,int* nv){
    if(driver != NULL) {
        *dinheiro = lookupDinheiroStatusDriver(driver);
        *avaliacao = lookupAvaliacaoStatusDriver(driver);
        *nv = lookupNumeroVStatusDriver(driver);
    }
}

// --------------------------------------------
// lookupDinheiroStatusDriver
// --------------------------------------------


double lookupDinheiroStatusDriver(statusDriver driver){
    double dinheiro = driver->dinheiroGanho;
    return dinheiro;
}

// --------------------------------------------
// lookupAvaliacaoStatusDriver
// --------------------------------------------

double lookupAvaliacaoStatusDriver(statusDriver driver){
    double avaliacao =driver->scoreDriverT;
    return avaliacao;
}

// --------------------------------------------
// lookupNumeroVStatusDriver
// --------------------------------------------

int lookupNumeroVStatusDriver (statusDriver driver){
    int nv= driver->numeroViagem;
    return nv;
}

// --------------------------------------------
// lookupDataStatusDriver
// --------------------------------------------

int lookupDataStatusDriver (statusDriver driver){
    return driver->viagemMaisRD;
}

// --------------------------------------------
// lookupIdStatusDriver
// --------------------------------------------

int lookupIdStatusDriver(statusDriver driver){
    return atoi(driver->id);
}

// --------------------------------------------
// lookupIDcharStatus
// --------------------------------------------

char *lookupIDcharStatus(statusDriver driver){
    return strdup(driver->id);
}

// --------------------------------------------
// lookupAvalMedDriver
// --------------------------------------------

double lookupAvalMedDriver(statusDriver driver){
    double aval = lookupAvaliacaoStatusDriver(driver);
    int nviagem = lookupNumeroVStatusDriver(driver);
    return (double)aval/(double)nviagem;
}

