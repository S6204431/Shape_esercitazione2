#ifndef EDITORS_H
#define EDITORS_H

#include "CShape.h"
#include "choice.h"
#include <iostream>

#define GRID_X_LENGHT 100.0
#define GRID_Y_LENGHT 100.0

using namespace std;

void editDim(Shape** arrayPtr, int index);
void editPosition(Shape** arrayPtr, int index);
void editText(Shape** arrayPtr, int index);

#endif