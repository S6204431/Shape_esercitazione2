#ifndef MENU_H
#define MENU_H

#include "Cshape.h"
#include <iostream>
#define MAX_IN_LENGHT 10000

using namespace std;

void PrintList(Shape** arrayPtr, int dim);
void EditPolygon(Shape* polygonPtr);
void MovePolygon(Shape* polygonPtr);
Shape* NewPolygon();
void DeletePolygon(Shape* polygonPtr);
void EraseList(Shape** arrayPtr);
template <class T>
void inputCheck(T check)
{
    while (!(cin >> check))
    {
        cin.clear(); // Resetta lo stato di errore di cin
        cin.ignore(MAX_IN_LENGHT, '\n'); // Svuota il buffer
        cout << "Error: invalid input. Use 0 or 1: ";
    }
}

#endif