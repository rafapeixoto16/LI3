#pragma once

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define tamanhoArrayPaginacao 100000

/*!
 * @param arrayString Array de string.
 * @return Retorna o numero de paginas maximo.
 */
int Npaginas(char **arrayString);

/*!
 * Trata da pagina do array.
 * @param array Array para dar print.
 */
void paginacao(char **array);

/*!
 * Função que recebe uma string e torna-a num array de strings.
 * @param Astring O array.
 * @param string A string.
 */
void string4Array(char **Astring,char *string);

/*!
 * Função que dada uma pagina inicial e final dá print ao array.
 * @param arrayString O array.
 * @param pInicial A primeira pagina.
 * @param pFinal A ultima pagina.
 */
void printIndice(char **arrayString, int pInicial, int pFinal);

/*!
 * Função que dá free ás posições do array.
 * @param arrayString O array.
 */
void freeArray(char **arrayString);

/*!
 * Verifica se a data é valida
 * @param stringPrint String a dar print
 * @return Retorna uma data valida
 */

char *dataMenu(char *stringPrint);

/*!
 * Enquanto o input for diferente do caracter v ele continua.
 */

void funcaoVoltar();

/*!
 * Trata a string cidade para a estrutura certa.
 * @param cidade Indereço da cidade.
 */

void funcaoCidade(char *cidade);

/*!
 * Verifica se o genero é valido, enquanto nao for F / M continua a pedir para insirir.
 * @return Retorna 1 se o genero for Masculino 0 se for feminino.
 */
bool generoMenu();

/*!
 * Verifica se um ficheiro existe (csv) dentro de um path.
 * @param fname File Name.
 * @return Reforna 1 se ficheiro existe 0 caso contrario.
 */

int exists(const char *fname);

void tamanhoJanelaAtual(int *cols,int *rows);

void tamanhoJanela();

int contaElem(char **input,int pagina);