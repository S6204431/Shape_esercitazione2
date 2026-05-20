#ifndef MENU_H
#define MENU_H

#include "Cshape.h"
#include <iostream>
#define MAX_IN_LENGHT 10000
#define YN_WHITELIST_LENGHT 4
#define TD_WHITELIST_LENGHT 4
#define SH_WHITELIST_LENGHT 6
#define MAX_SHAPES 10



using namespace std;

const string YNWhitelist[YN_WHITELIST_LENGHT] = {"y", "n", "Y", "N"};       //yes e no
const string TDWhitelist[TD_WHITELIST_LENGHT] = {"t", "d", "T", "D"};       //text e dimension
const string SHWhitelist[SH_WHITELIST_LENGHT] = {"a", "b", "c", "A", "B", "C"};       //shapes

void PrintList(Shape** arrayPtr, int dim);
void EditPolygon(Shape** arrayPtr, int dim);
void MovePolygon(Shape** arrayPtr, int dim);
void NewPolygon(Shape** arrayPtr, int *dim);
void DeletePolygon(Shape* polygonPtr);
void EraseList(Shape** arrayPtr);

int ChoiceCheck(string question, const string whiteList[], int lenght, int nchoices);
int PolygonSelection(string question, int dim);
float EnterDim(string question);
void editDim(Shape** arrayPtr, int index);
void editPosition(Shape** arrayPtr, int index);
void editText(Shape** arrayPtr, int index);

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