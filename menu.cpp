#include "CShape.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include "CRightTriangle.h"
#include "menu.h"
#include "choice.h"
#include "editors.h"
#include <iostream>


using namespace std;
void PrintList(Shape** arrayPtr, int dim) //presuppone pop e push
{
    if(*arrayPtr == NULL)
    {
        cout << "\n====ERROR: No existing polygon in list.====\n";
        return;
    }
    cout << "==== PRINTING LIST ====" << endl;
    for(int i = 0; i < dim; i++)
    {
        cout << "\nSHAPE NUMBER " << i;
        arrayPtr[i]->Dump();
    }
    cout << endl << "==== END LIST ====" << endl;


    if(!ChoiceCheck("Want to know something specific about a polygon? [y/n] ", YNWhitelist, YN_WHITELIST_LENGHT, YN_WHITELIST_CHOICES))
    {
        int j = 0;
        //gestione j>dim e j è indirizzo null
        j = PolygonSelection("Which one of the polygons in the list you want to know about? ", dim);
        cout << "\nSHAPE NUMBER " << j;
        arrayPtr[j]->Dump();
        arrayPtr[j]->SpecificDump();
    }
    else
    {
        return;
    }

}

void EditPolygon(Shape** arrayPtr, int dim)
{
    if(*arrayPtr == NULL)
    {
        cout << "====ERROR: No existing polygon in list.====\n";
        return;
    }

    int j = 0;

    j = PolygonSelection("Which polygon do you wanna change? ", dim);

    if(!ChoiceCheck(("What do you want to change? (t=text, d=dimension) "), TDWhitelist, TD_WHITELIST_LENGHT, TD_WHITELIST_CHOICES))    //cioe se è t o T
    {
        editText(arrayPtr, j);
        
    } else          //cioe se è d o D
    {
        editDim(arrayPtr, j);
    }        
}

void MovePolygon(Shape** arrayPtr, int dim)
{
    if(*arrayPtr == NULL)
    {
        cout << "\n====ERROR: No existing polygon in list.====\n";
        return;
    }

    int j = PolygonSelection("Which polygon do you wanna move? ", dim);

    editPosition(arrayPtr, j);
          
}

void NewPolygon(Shape** arrayPtr, int *dim)
{
    if(*dim == MAX_SHAPES)
    {
        cout << "\nImpossible to create other shapes, the array is full." << endl;
        return;
    }
    
    int choice = ChoiceCheck(("Which shape do you want? (a=rectangle, b=rhomus, c=right_triangle) "), SHWhitelist, SH_WHITELIST_LENGHT, SH_WHITELIST_CHOICES);

    if(choice == 0) 
    {
        arrayPtr[*dim] = new Rectangle();
        cout <<"A rectangle was created by default." << endl;
    } else if(choice == 1)
    {
        arrayPtr[*dim] = new Rhombus();
        cout <<"A rhombus was created by default." << endl;
    } else
    {
        arrayPtr[*dim] = new RightTriangle();
        cout <<"A right_triangle was created by default." << endl;
    }

    cout << "\nEnter position: " << endl;
    editPosition(arrayPtr, *dim);
    cout << "Enter dimensions: " << endl;
    editDim(arrayPtr, *dim);
    editText(arrayPtr, *dim);
    (*dim)++;
}

void DeletePolygon(Shape** arrayPtr, int *dim)
{
    if(*arrayPtr == NULL)
    {
        cout << "\n====ERROR: No existing polygon in list.====\n";
        return;
    }

    int j = PolygonSelection("Which polygon do you wanna delete? ", *dim);
    delete(arrayPtr[j]);
    cout << "\nShape number " << j << " deleted: shifting the other shapes order." << endl;
    for (int i = j; i < *dim - 1; i++)
    {
        arrayPtr[i] = arrayPtr[i + 1];
    }
    (*dim)--;
    arrayPtr[*dim] = NULL;
}

void DeleteList(Shape** arrayPtr, int *dim)
{
    if(*arrayPtr == NULL)
    {
        cout << "\n====ERROR: No existing polygon in list.====\n";
        return;
    }

    for (int i = 0; i < *dim; i++)
    {
        if(arrayPtr[i] != NULL)
        {
            delete(arrayPtr[i]);
            arrayPtr[i] = NULL;
        }
    }

    cout << "\nAll shapes have been deleted." << endl;

    (*dim) = 0;
}

int menu()
{
    cout << "\nSELECT YOUR CHOICE:\n" << endl;
    cout << "-Press 1 to visualize all polygons" << endl;
    cout << "-Press 2 to modify a polygon" << endl;
    cout << "-Press 3 to move a polygon" << endl;
    cout << "-Press 4 to create a polygon" << endl;
    cout << "-Press 5 to delete a polygon" << endl;
    cout << "-Press 6 to delete all polygons" << endl;
    cout << "-Press 0 to exit" << endl;

    return ChoiceCheck("Enter: ", MNWhitelist, MN_WHITELIST_LENGHT, MN_WHITELIST_CHOICES);
}