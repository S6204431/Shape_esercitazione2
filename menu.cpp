#include "CShape.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include "CRightTriangle.h"
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


    if(ChoiceCheck("Want to know something specific about a polygon? [y/n] ", YNWhitelist, YN_WHITELIST_LENGHT, 2))
    {
        int j = 0;
        //gestione j>dim e j è indirizzo null
        j = PolygonSelection("Which one of the polygons in the list you want to know about?", dim);
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
        cout << "No existing polygon in list.\n";
        return;
    }

    int j = 0;

    j = PolygonSelection("Which polygon do you wanna change?", dim);

    if(ChoiceCheck(("What do you want to change? (t=text, d=dimension)"), TDWhitelist, TD_WHITELIST_LENGHT, 2))    //cioe se è t o T
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
        cout << "No existing polygon in list.\n";
        return;
    }

    int j = PolygonSelection("Which polygon do you wanna move?", dim);

    editPosition(arrayPtr, j);
          
}

void NewPolygon(Shape** arrayPtr, int *dim)
{
    int choice = ChoiceCheck(("Which shape do you want? (a=rectangle, b=rhomus, c=right_triangle)"), TDWhitelist, TD_WHITELIST_LENGHT, 3);
    int newX;
    int newY;
    int newH;
    int newW;
    string text;
    if(choice == 0) 
    {
        arrayPtr[*dim++] = new Rectangle();
        editDim(arrayPtr, *dim);
    } else if(choice == 1)
    {
        
    } else
    {

    }      
}

void DeletePolygon(Shape* polygonPtr)
{

}

void EraseList(Shape** arrayPtr)
{

}





int ChoiceCheck(string question, const string whiteList[], int lenght, int nChoices)
{
    cout << question << endl;

    string a;
    while(true)
    {
        cin >> a;
        for(int i=0; i<lenght; i++)
        {
            if(a == whiteList[i])
            {
                cin.ignore(MAX_IN_LENGHT, '\n');      
                return !(i%nChoices);
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
            char nextChar = cin.peek();     //senza estrarlo, controlla il carattere nel buffer di input subito successivo al primo, che è stato buttato dentro "a"
            if(nextChar != '\n' && nextChar != ' ' && nextChar != EOF)  //se non è uno stacco, quindi o un accapo o uno spazio o l'end of file...
            {
                cout << "Error: the input must be an integer: no decimals allowed." << endl;
                cin.clear();    //PROMEMORIA: FORSE HA SENSO METTERE IN FUNZIONE QUESTE DUE RIGHE CHE SI RIPETONO SPESSO
                cin.ignore(MAX_IN_LENGHT, '\n');    //cestina il resto della riga fino all'accapo
                continue; // torna all'inizio del while
            }
            if(a >= dim || a < 0)
            {
                cout << "Out of list dimension." << endl;
                continue;
            }else
            {
                cin.ignore(MAX_IN_LENGHT, '\n');    //per dopo, svuotiamo dall'invio il buffer di inut
                return a;
            }
                
        } else
        {
            cout << "Error: invalid input." << endl;
            cin.clear(); // Resetta lo stato di errore di cin
            cin.ignore(MAX_IN_LENGHT, '\n'); // Svuota il buffer
        }
    }
}

float EnterDim(string question)
{
    int newDim;

    while (true)
    {
        cout << question;
        cin >> newDim;
        if ((cin.peek() == '\n' || cin.peek() == ' ' || cin.peek() == EOF) && newDim >= 0) {
            cin.ignore(MAX_IN_LENGHT, '\n'); 
            break;
        }
        cout << "Error: enter a valid floating positive number.\n";
        cin.clear();
        cin.ignore(MAX_IN_LENGHT, '\n');
    }

    return newDim;
}

void editDim(Shape** arrayPtr, int index)
{
        float newW, newH;       //le nuove dimensioni

        newW = EnterDim("Enter width: ");
        newH = EnterDim("Enter height: ");

        //uso i getters e i setters per confrontare con la griglia ed eventualmente modificare le dimensioni
        if ((arrayPtr[index]->GetX() + newW > 100.0) || (arrayPtr[index]->GetY() + newH > 100.0))
        {
            cout << "Error: new bounding box exceeds the grid. No dimensions were changed.\n";
        } else
        {
            arrayPtr[index]->SetDim(newW, newH);
            cout << "Dimensions successfully updated.\n" << endl;
        }
}


void editPosition(Shape** arrayPtr, int index)
{
    float newX, newY;       //le nuove posizioni

    newX = EnterDim("Enter x position: ");
    newY = EnterDim("Enter y position: ");

    //uso i getters e i setters per confrontare con la griglia ed eventualmente modificare le dimensioni
    if ((arrayPtr[index]->GetWidth() + newX > 100.0) || (arrayPtr[index]->GetHeight() + newY > 100.0))
    {
        cout << "Error: new bounding box exceeds the grid. No dimensions were changed.\n";
    } else
    {
        arrayPtr[index]->SetPosition(newX, newY);
        cout << "Dimensions successfully updated.\n" << endl;
    }
}


void editText(Shape** arrayPtr, int index)
{
        cout << "Enter text: ";
        char newText[MAX_IN_LENGHT];
        cin.getline(newText, MAX_IN_LENGHT);    //non posso usare cin altrimenti se ci sono spazi si ferma
        arrayPtr[index]->SetText(newText);
        cout << "The text was successfully changed." << endl;
}