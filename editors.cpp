#include "CShape.h"
#include "editors.h"
#include "choice.h"

#include <iostream>

using namespace std;

void editDim(Shape** arrayPtr, int index)
{
    float newW, newH;       //le nuove dimensioni

    while(1)
    {
        newW = EnterDim("Enter width: ");
        newH = EnterDim("Enter height: ");

        //uso i getters e i setters per confrontare con la griglia ed eventualmente modificare le dimensioni
        if ((arrayPtr[index]->GetX() + newW > GRID_X_LENGHT) || (arrayPtr[index]->GetY() + newH > GRID_Y_LENGHT))
        {
            cout << "Error: bounding box exceeds the grid. Try another value.\n";
        } else
        {
            arrayPtr[index]->SetDim(newW, newH);
            cout << "Dimentions successfully updated.\n" << endl;
            break;
        }
    }
}


void editPosition(Shape** arrayPtr, int index)
{
    float newX, newY;       //le nuove posizioni
    while(1)
    {
        newX = EnterDim("Enter x position: ");
        newY = EnterDim("Enter y position: ");

        //uso i getters e i setters per confrontare con la griglia ed eventualmente modificare le dimensioni
        if (arrayPtr[index]->GetWidth() + newX > GRID_X_LENGHT || (arrayPtr[index]->GetHeight() + newY > GRID_Y_LENGHT))
        {
            cout << "Error: bounding box exceeds the grid. Try another value.\n";
        } else
        {
            arrayPtr[index]->SetPosition(newX, newY);
            cout << "Position successfully updated.\n" << endl;
            break;
        }
    }
}


void editText(Shape** arrayPtr, int index)
{
    cout << "Enter text: ";
    char newText[MAX_IN_LENGHT];
    cin.getline(newText, MAX_IN_LENGHT);    //non posso usare cin altrimenti se ci sono spazi si ferma
    arrayPtr[index]->SetText(newText);
    cout << "Text successfully changed." << endl;
}
