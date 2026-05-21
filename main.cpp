/*! \file main.cpp
    \brief Main program, testing
    \author Alessandro Passaggio - Gregorio Bertelli
*/

#include <iostream>
#include <cmath>

#include "CShape.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include "CRightTriangle.h"
#include "menu.h"

using namespace std;

/// @brief main function
/// @return exit code
int main()
{   
    Shape* shapes[MAX_SHAPES];
    
    for (int i = 0; i < MAX_SHAPES; i++)
    {
        shapes[i] = NULL;
    }
    
    int nShapes = 0;
    int choice = -1;

    cout << "===== TEST GERARCHIA SHAPE =====" << endl;

    while(choice != 0)
    {
        choice = menu();
        switch (choice)
        {
        case 1:
            PrintList(&shapes[0], nShapes);
            break;
        case 2:
            EditPolygon(&shapes[0], nShapes);
            break;
        case 3:
            MovePolygon(&shapes[0], nShapes);
            break;
        case 4:
            NewPolygon(&shapes[0], &nShapes);
            break;
        case 5:
            DeletePolygon(&shapes[0], &nShapes);
            break;
        case 6:
            DeleteList(&shapes[0], &nShapes);
            break;
        case 0:
            cout << "\nExiting the program." << endl;
            break;
        default:
            printf("\nNot possible\n");
            exit(-1);
            break;
        }
    }

    // 5. delete shapes
    for (int i = 0; i < nShapes; i++) {
        if(shapes[i] != NULL)
        {
            delete(shapes[i]);
            shapes[i] = NULL;
        }
    }

    cout << endl << "===== FINE TEST =====" << endl;

    return 0;
}