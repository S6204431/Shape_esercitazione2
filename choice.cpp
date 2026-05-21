#include "choice.h"
#include <iostream>

using namespace std;

int ChoiceCheck(string question, const string whiteList[], int lenght, int nChoices)
{
    cout << question;

    string a;
    while(true)
    {
        cin >> a;
        for(int i=0; i<lenght; i++)
        {
            if(a == whiteList[i])
            {
                cin.ignore(MAX_IN_LENGHT, '\n');      
                return (i%nChoices);
            }
        }
        cout << "Error: invalid input." << endl;
    }

}

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
    float newDim;

    while (true)
    {
        cout << question;
        if(cin >> newDim)
        {
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