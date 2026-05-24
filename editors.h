/*! \file editors.h
    \brief Declaration of editing functions for polygons
    \author Alessandro Passaggio - Gregorio Bertelli
*/

#ifndef EDITORS_H
#define EDITORS_H

#include "CShape.h"
#include "choice.h"
#include <iostream>
//parametrizzazione dei limiti fisici della griglia, utili se un domani varia la grandezza.
#define GRID_X_LENGHT 100.0
#define GRID_Y_LENGHT 100.0

using namespace std;

/// @name EDIT FUNCTIONS
/// @{
int editDim(Shape** arrayPtr, int index);
int editPosition(Shape** arrayPtr, int index);
void editText(Shape** arrayPtr, int index);
/// @}

#endif