/*! \file menu.h
    \brief Declaration of menu interface functions
    \author Alessandro Passaggio - Gregorio Bertelli
*/

#ifndef MENU_H
#define MENU_H

#include "CShape.h"
#include "editors.h"
#include "choice.h"
#include <iostream>

#define MAX_SHAPES 10

using namespace std;

/// @name MENU FUNCTIONS
/// @{
void PrintList(Shape** arrayPtr, int dim);
void EditPolygon(Shape** arrayPtr, int dim);
void MovePolygon(Shape** arrayPtr, int dim);
void NewPolygon(Shape** arrayPtr, int *dim);
void DeletePolygon(Shape** arrayPtr, int *dim);
void DeleteList(Shape** arrayPtr, int *dim);

int menu();
/// @}

#endif