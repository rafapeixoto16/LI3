#pragma once

#include "drivers.h"
#include "users.h"
#include "rides.h"
#include "array.h"

/*!
 * Liberta a memoria utilizada no parsing dos datasets.
 */

void freeDataset(ARRAYDinamico driver ,ARRAYDinamico ride ,ARRAYDinamico users,ARRAYDinamico statusD ,ARRAYDinamico statusU);
