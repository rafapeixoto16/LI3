#pragma once


#include <stdio.h>
#include "drivers.h"
#include "rides.h"
#include "users.h"
#include "array.h"

/*!
 * Faz o tratamento do csv.
 * @param dataset path dos datasets.
 * @param ride Indereço do array ride.
 * @param drive Indereço da hashtable drive.
 * @param user Indereço da  hashtavle user.
 */
void parsing(char *dataset, ARRAYDinamico ride, ARRAYDinamico drive, ARRAYDinamico user);