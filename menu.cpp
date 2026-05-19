#include "CShape.h"
#include "menu.hpp"
#include <iostream>

using namespace std;
void PrintList(Shape** arrayPtr, int dim) //presuppone pop e push
{
    if(*arrayPtr == NULL)
    {
        cout << "No existing polygon in list.\n";
        return;
    }
    cout << "==== PRINTING LIST ====" << endl;
    for(int i = 0; i < dim; i++)
    {
        
        arrayPtr[i]->Dump();
    }
    cout << endl << "==== END LIST ====" << endl;

    bool choice;
    cout << "Want to know something specific about a polygon? (1=yes, 0=no)" << endl;
    inputCheck(&choice);
    if(!choice)
    {
        return;
    }
    else
    {
        cout << "Which one of the polygons in the list you want to know about?" << endl;
        int j = 0;
        //gestione j>dim e j è indirizzo null
        inputCheck(&j);
        if(j >= dim || j < 0)
        {
            cout << "Out of list dimension. Returning to main menu." << endl;
            return;
        }
        /* else if((arrayPtr[j]) == NULL)
        {
            cout << "Element corresponding to this index doesn't exist yet. Returning to main menu." << endl;
            return;
        }*/ else
        {
            arrayPtr[j]->SpecificDump();
        }
    }

}

void EditPolygon(Shape** arrayPtr, int dim)
{
    if(*arrayPtr == NULL)
    {
        cout << "No existing polygon in list.\n";
        return;
    }

    int j = 0;
    cout << "Which polygon do you wanna change?" << endl;
    inputCheck(j);
    if(j >= dim)
    {
        cout << "Out of list dimension. Returning to main menu." << endl;
        return;
    } else
    {
        bool input;
        cout << "What do you want to change? (0=text, 1=dimension)" << endl;
        inputCheck(input);
        if(input==0)
        {
            char* text;
            inputCheck(text);
        }else
        {

        }
        
    }

    
}

void MovePolygon(Shape* polygonPtr)
{

}

Shape* NewPolygon()
{
    Shape* i;
    return i;
}

void DeletePolygon(Shape* polygonPtr)
{

}

void EraseList(Shape** arrayPtr)
{

}