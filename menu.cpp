#include "CShape.h"
#include "menu.h"
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


    if(!YNCheck("Want to know something specific about a polygon? [y/n] "))
    {
        return;
    }
    else
    {
        int j = 0;
        //gestione j>dim e j è indirizzo null
        j = PolygonSelection("Which one of the polygons in the list you want to know about?", dim);
        arrayPtr[j]->Dump();
        arrayPtr[j]->SpecificDump();
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

    PolygonSelection("Which polygon do you wanna change?", dim);
    if(j >= dim)
    {
        cout << "Out of list dimension. Returning to main menu." << endl;
        return;
    } else
    {
        bool input;
        cout << "What do you want to change? (0=text, 1=dimension)" << endl;
        
        if(input==0)
        {
            char* text;
            
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





bool YNCheck(string question)
{
    cout << question << endl;

    string a;
    while(true)
    {
        cin >> a;
        for(int i=0; i<YN_WHITELIST_LENGHT; i++)
        {
            if(a == YNWhitelist[i])
            {
                return !(i%2);
            }
        }
        cout << "Error: invalid input." << endl;
    }

}

int PolygonSelection(string question, int dim)
{
    cout << question << endl;

    int a;
    while(true)
    {
        if(cin >> a)
        {
            if(a >= dim || a < 0)
            {
                cout << "Out of list dimension." << endl;
                continue;;
            }else
            {
                return a;
            }
                
        }else
        {
            cout << "Error: invalid input." << endl;
            cin.clear(); // Resetta lo stato di errore di cin
            cin.ignore(MAX_IN_LENGHT, '\n'); // Svuota il buffer
        }
    }
}