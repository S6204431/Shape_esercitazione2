#ifndef MENU_H
#define MENU_H

#include "Cshape.h"
#include <iostream>
#define MAX_IN_LENGHT 10000
#define YN_WHITELIST_LENGHT 4
#define MAX_SHAPES 10



using namespace std;

const string YNWhitelist[YN_WHITELIST_LENGHT] = {"y", "n", "Y", "N"};

void PrintList(Shape** arrayPtr, int dim);
void EditPolygon(Shape** arrayPtr, int dim);
void MovePolygon(Shape* polygonPtr);
Shape* NewPolygon();
void DeletePolygon(Shape* polygonPtr);
void EraseList(Shape** arrayPtr);

bool YNCheck(string question);
int PolygonSelection(string question, int dim);


/*template <class T>
void inputCheck(T* check)
{
    while (!(cin >> *check))
    {
        cin.clear(); // Resetta lo stato di errore di cin
        cin.ignore(MAX_IN_LENGHT, '\n'); // Svuota il buffer
        cout << "Error: invalid input.";
    }
    return;
}*/

#endif