#pragma once

#include <stdio.h>
#include <string.h>

/*!
 * Função que dá print ao display do menu.
 */

void displayMenu();

/*!
 * Função que dá print á paginação do menu.
 */

void printPaginacao();

/*!
 * Função que limpa o terminal
 */
void clear_screen();

/*!
 * Função que dá print ás diferentes mensagens de erro consoante a querry.
 * @param querry A querry.
 */

void errorMsg(int querry);

/*!
 * Função que dá print á paginação.
 * @param pag A pagina atual.
 */

void printPaginacao2(int pag,int pagMax);

/*!
 * Função que dá print aos creditos.
 */

void printCreditos();

/*!
 * Função que dá print ao voltar.
 */

void printVoltar();

/*!
 * Função que dá print a x linhas vazias.
 * @param linha Numero de linhas.
 */

void printLinha(int linha);

/*!
 * Função que dá print ao limite superior do menu.
 */

void printUpper();


/*!
 * Versao 80x24 dos prints
 */

/*!
 * Função que dá print ao display do menu 80x24.
 */

void displayMenu8024();


/*!
 * Função que dá print á paginação do menu 80x24.
 */

void printPaginacao8024();

/*!
 * Função que dá print á paginação 80x24.
 * @param pag A pagina atual.
 */


void printPaginacao28024(int pag,int pagMax);

/*!
 * Função que dá print ao voltar 80x24.
 */

void printVoltar8024();

/*!
 * Função que dá print ao limite superior do menu 80x24.
 */

void printUpper8024();