#include "../includes/array.h"
#include "../includes/statusUser.h"

struct statsU{
    char *username;
    int  viagemMaisRD;
    double scoreUserT;
    int  numeroViagem;
    int distancia;
    double dinheiroGasto;
    struct statsU  *ultimoAcesso;
    struct statsU  *next;
};

// --------------------------------------------
// lookupDistanciaUser
// --------------------------------------------


int lookupDistanciaUser(statusUSER user1){
    return user1->distancia;
}

// --------------------------------------------
// lookupViagemMRUser
// --------------------------------------------


int lookupViagemMRUser(statusUSER user1){
    return user1->viagemMaisRD;
}

// --------------------------------------------
// lookupUsernameUser
// --------------------------------------------


char *lookupUsernameUser(statusUSER user1){
    return strdup(user1->username);
}

// --------------------------------------------
// setPointer
// --------------------------------------------


void setPointer(statusUSER user1){
    user1->ultimoAcesso = user1;
}

// --------------------------------------------
// lookupMaisRecenteVisitado
// --------------------------------------------


statusUSER lookupMaisRecenteVisitado(statusUSER user1){
    return user1->ultimoAcesso;
}

// --------------------------------------------
// avancaRecenteVisitado
// --------------------------------------------


void avancaRecenteVisitado(statusUSER user1){
    user1 -> ultimoAcesso = user1 -> next;
}

// --------------------------------------------
// lookupIDcharStatusUser
// --------------------------------------------


char *lookupIDcharStatusUser(statusUSER user1){
    return strdup(user1->username);
}

// --------------------------------------------
// statusUParsing
// --------------------------------------------


statusUSER statusUParsing (void *userStatus,double dinheiroG, double score, char *username,int data,int distancia){
    ARRAYDinamico tableU = userStatus;
    statusUSER statusUser1 = malloc(sizeof (struct statsU));

    statusUser1 -> viagemMaisRD  = data;
    statusUser1 -> dinheiroGasto = dinheiroG;
    statusUser1 -> scoreUserT    = score;
    statusUser1 -> numeroViagem  = 1;
    statusUser1 -> username      = username;
    statusUser1 -> next          = posicaoTableSusers(tableU,username);
    statusUser1 -> distancia     = distancia;

    return statusUser1;
}


// --------------------------------------------
// pertencaLista
// --------------------------------------------


bool pertencaLista (statusUSER sU, char *nomeUser,double dinheiro,double scoreU,int data,int distancia){
    if(sU==NULL)
        return false;

    statusUSER tmp = sU;

    while (tmp != NULL && (strcmp( tmp->username, nomeUser) != 0) )
        tmp = tmp -> next;

    if(tmp == NULL)
        return false;

    tmp -> numeroViagem  = tmp -> numeroViagem + 1;
    tmp -> viagemMaisRD  = tmp -> viagemMaisRD > data ? tmp -> viagemMaisRD : data;
    tmp -> scoreUserT    += scoreU;
    tmp -> dinheiroGasto += dinheiro;
    tmp-> distancia       += distancia;

    return true;
}

// --------------------------------------------
// freeUserStatus
// --------------------------------------------


void freeUserStatus(statusUSER sU){
    statusUSER tmp;
    while(sU != NULL){
        tmp = sU;
        sU =  sU -> next;
        free        (tmp->username);
        free                  (tmp);
    }
}



// --------------------------------------------
// printUserStatus
// --------------------------------------------


void printUserStatus (statusUSER sU){
    statusUSER tmp=sU;
    while(tmp != NULL) {
        printf("%s ----  %f  ---- %i ----%i\n", tmp->username, tmp->dinheiroGasto, tmp->numeroViagem,tmp->distancia);
        tmp=tmp->next;
    }
}

// --------------------------------------------
// informacoesBasicasStatusUser
// --------------------------------------------

void informacoesBasicasStatusUser (statusUSER user1 ,char *username,double *dinheiro,double *avaliacao,int *nv){
    statusUSER tmp = user1;

    while (tmp != NULL && strncmp(tmp->username, username, 50) != 0) {
        tmp = tmp->next;
    }
    if(tmp==NULL)
        return;

    *dinheiro  = tmp->dinheiroGasto;
    *avaliacao = tmp->scoreUserT;
    *nv        = tmp->numeroViagem;
}

// --------------------------------------------
// quicksortDistanciaUser
// --------------------------------------------

void quicksortDistanciaUser(statusUSER *user,int tamanho){
    if(tamanho < 2) return;

    int pivot = (user[tamanho/2]->distancia);

    int i,j;

    for (i=0,j=tamanho-1;;i++,j--)
    {
        while ((user[i]->distancia) > pivot) i++;
        while ((user[j]->distancia) < pivot) j--;

        if(i>=j)
            break;

        statusUSER tmp = user[i];
        user[i] = user[j];
        user[j] = tmp;

    }
    quicksortDistanciaUser(user,i);
    quicksortDistanciaUser(&user[i],tamanho - i);
}

// --------------------------------------------
// quicksortViagemMRecente
// --------------------------------------------

void quicksortViagemMRecente(statusUSER *user,int tamanho){
    if(tamanho < 2) return;

    int pivot = (user[tamanho/2]->viagemMaisRD);

    int i,j;

    for (i=0,j=tamanho-1;;i++,j--)
    {
        while ((user[i]->viagemMaisRD) > pivot) i++;
        while ((user[j]->viagemMaisRD) < pivot) j--;

        if(i>=j)
            break;

        statusUSER tmp = user[i];
        user[i] = user[j];
        user[j] = tmp;

    }
    quicksortViagemMRecente(user,i);
    quicksortViagemMRecente(&user[i],tamanho - i);
}

