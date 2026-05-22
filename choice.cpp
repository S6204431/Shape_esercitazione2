/*! \file choice.cpp
    \brief Implementation of input handling functions
    \author Alessandro Passaggio - Gregorio Bertelli
*/

#include "choice.h"
#include <iostream>

using namespace std;

/// @brief asks a question and checks if the input is in a whitelist
/// @param question the question shown to the user
/// @param whiteList array of allowed strings
/// @param lenght lenght of the whitelist array
/// @param nChoices number of valid choices
/// @return the logic index of the choice
int ChoiceCheck(string question, const string whiteList[], int lenght, int nChoices)
{
    cout << question;

    string a;
    // loop finche non trova un elemento che esiste nella whitelist
    while(true)
    {
        cin >> a;
        for(int i=0; i<lenght; i++)
        {
            if(a == whiteList[i])
            {
                //pulisco il buffer dall'invio prima di returnare
                cin.ignore(MAX_IN_LENGHT, '\n');   
                //uso il remainder: funziona per come sono ordinate le liste   
                return (i%nChoices);
            }
        }
        cout << "Error: invalid input." << endl;
    }

}

/// @brief asks the user to select an index of a polygon inside valid bounds
/// @param question the question printed to the user
/// @param dim current number of polygons
/// @return the selected valid index
int PolygonSelection(string question, int dim)
{
    cout << question;

    int a;
    while(true)
    {
        if(cin >> a)
        {
            char nextChar = cin.peek();     //senza estrarlo, controlla il carattere nel buffer di input subito successivo al primo, che è stato buttato dentro "a"
            if(nextChar != '\n' && nextChar != ' ' && nextChar != EOF)  //se non è uno stacco, quindi o un accapo o uno spazio o l'end of file...
            {
                cout << "Error: the input must be an integer: no decimals allowed." << endl;
                cin.clear();
                cin.ignore(MAX_IN_LENGHT, '\n');    //cestina il resto della riga fino all'a capo
                continue; // torna all'inizio del while
            }
            //controllo se l'indice esiste davvero
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
            cin.clear(); // resetta lo stato di errore di cin
            cin.ignore(MAX_IN_LENGHT, '\n'); // svuota il buffer
        }
    }
}

/// @brief asks the user to enter a dimension
/// @param question the question printed to the user
/// @return the dimension chosen
float EnterDim(string question)
{
    float newDim;

    while (true)
    {
        cout << question;
        if(cin >> newDim)
        {
            // se dopo il numero c'e uno spazio o un invio ed e' positivo, e' buono
            if ((cin.peek() == '\n' || cin.peek() == ' ' || cin.peek() == EOF) && newDim >= 0)
            {
                cin.ignore(MAX_IN_LENGHT, '\n'); 
                break;
            }
        }
        cout << "Error: enter a valid floating positive number.\n";
        cin.clear();
        cin.ignore(MAX_IN_LENGHT, '\n');
    }

    return newDim;
}