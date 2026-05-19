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


    if(!DoubleChoiceCheck("Want to know something specific about a polygon? [y/n] ", YNWhitelist, YN_WHITELIST_LENGHT))
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

    j = PolygonSelection("Which polygon do you wanna change?", dim);
    if(j >= dim)
    {
        cout << "Out of list dimension. Returning to main menu." << endl;
        return;
    } else
    {
        bool input = DoubleChoiceCheck(("What do you want to change? (t=text, d=dimension)"), TDWhitelist, TD_WHITELIST_LENGHT);
        if(input==1)    //cioe se è t o T
        {
            char newText[MAX_IN_LENGHT];
            cin.getline(newText, MAX_IN_LENGHT);    //non posso usare cin altrimenti se ci sono spazi si ferma
            arrayPtr[j]->SetText(newText);
            cout << "The text was successfully changed." << endl;
            
        } else          //cioe se è d o D
        {
            float newW, newH;       //le nuove dimensioni

            while (true)
            {
                cout << "Enter new width: ";
                cin >> newW;
                if ((cin.peek() == '\n' || cin.peek() == ' ' || cin.peek() == EOF) && newW >= 0) {
                    cin.ignore(MAX_IN_LENGHT, '\n'); 
                    break;
                }
                cout << "Error: enter a valid floating positive number.\n";
                cin.clear();
                cin.ignore(MAX_IN_LENGHT, '\n');
            }
            while (true)
            {
                cout << "Enter new height: ";
                cin >> newH;
                if ((cin.peek() == '\n' || cin.peek() == ' ' || cin.peek() == EOF) && newH >= 0) {
                    cin.ignore(MAX_IN_LENGHT, '\n');
                    break;
                }
                cout << "Error: valid positive number required.\n";
                cin.clear(); cin.ignore(MAX_IN_LENGHT, '\n');
            }
            //uso i getters e i setters per confrontare con la griglia ed eventualmente modificare le dimensioni
            if ((arrayPtr[j]->GetX() + newW > 100.0) || (arrayPtr[j]->GetY() + newH > 100.0))
            {
                cout << "Error: new bounding box exceeds the grid. No dimensions were changed.\n";
            } else
            {
                arrayPtr[j]->SetDim(newW, newH);
                cout << "Dimensions successfully updated.\n" << endl;
            }
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





bool DoubleChoiceCheck(string question, const string whiteList[], int lenght)
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