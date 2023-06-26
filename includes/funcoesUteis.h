#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define dataDiaAtual 9
#define dataMesAtual 10
#define dataAnoAtual 2022

/*!
 * Função que converte uma data para um inteiro.
 * @param data A data.
 * @return Data como um inteiro.
 */

int data2Int(char *data);

/*!
 * Função que converte todos os caracteres de uma string para letra minuscula.
 * @param str A string.
 */

void toLowerString (char *str);

/*!
 * Função que recebe uma data e verifica se é aceitavel.
 * @param data A data.
 * @return Retorna true se for aceitavel e false caso nao seja.
 */

bool verificaDate (char *data);

/*!
 * Função que verifica se um valor é um inteiro.
 * @param val O valor.
 * @return Retorna true se for inteiro e false caso nao seja.
 */

bool isInteger(char *val);

/*!
 * Função que verifica se uma string é um inteiro.
 * @param head A string.
 * @return Retorna false caso seja um numero e true caso nao seja.
 */

bool isNumber(char *head);

/*!
 * Função que verifica se uma string tem comprimento 0.
 * @param head A string.
 * @return Retorna false caso o comprimento seja maior que 0 e true caso nao seja.
 */

bool tamanhoEqual0(char *head);

/*!
 * Função que calcula uma idade comparando a data de nascimento com a data atual.
 * @param data Data de Nascimento.
 * @return Retorna a idade.
 */

int calculaIdade(char *data);

/*!
 * Função que recebe uma data e converte o dia/mes/ano para inteiros.
 * @param string A Data.
 * @param diaAtual O dia.
 * @param mesAtual O mes.
 * @param anoAtual O ano.
 */

void DataParaIntDMA (char *string,int *diaAtual,int *mesAtual ,int *anoAtual);

/*!
 * Função que converte um username para um inteiro somando os seus caracteres.
 * @param nome O username.
 * @return Retorna o valor inteiro do username
 */

int usernameParaInt (char *nome);

/*!
 * Função que recebe um data em inteiro e retorna a idade.
 * @param aniv A data.
 * @return Retorna a idade.
 */

int calculaIdadeInt(int aniv);

/*!
 * Recebe uma data e transforma para a forma DD/MM/AAAA.
 * @param dataNum A data.
 * @return Retorna a data na forma DD/MM/AAAA.
 */

char *int2Data(int dataNum);

/*!
 * Função que avança um dia na data.
 * @param data A data.
 */

void avancaDate(int *data);

/*!
 * Função que verifica se a data é aceitavel para uma query quase nao seja altera os valors.
 * @param dataInicio Primeira data.
 * @param dataFim Segunda data.
 * @param primeiraData Data mais antiga.
 * @param ultimaData Data mais recente.
 */

void verificaDataQueries(int *dataInicio,int *dataFim ,int *primeiraData, int *ultimaData);