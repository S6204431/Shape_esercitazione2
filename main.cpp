#include <iostream>
#include <cmath>

#include "CShape.h"
#include "CRectangle.h"
#include "CRhombus.h"
#include "CRightTriangle.h"
#include "menu.hpp"

using namespace std;

#define MAX_SHAPES 10

int main()
{   
    Shape* shapes[MAX_SHAPES];
    
    for (int i = 0; i < MAX_SHAPES; i++) {
        shapes[i] = NULL;
    }
    
    int nShapes = 0;

    cout << "===== TEST GERARCHIA SHAPE =====" << endl;

    // 1. Creazione figure
    shapes[nShapes++] = new Rectangle(0, 0, 10, -6);    //darà un perimetro di 20 dopo il clamp a 0 di -6: topologicamente è corretto anche se un segmento non racchiude alcuna area...
    shapes[nShapes++] = new Rhombus(2, 2, 3, 4);
    shapes[nShapes++] = new RightTriangle(0, 0, 10, 5);


    // 2. Impostazione testo
    shapes[0]->SetText("rettangolo");
    shapes[1]->SetText("rombo");
    shapes[2]->SetText("triangolo destro");


    // 3. Dump polimorfico
    /*cout << endl << "===== DUMP POLIMORFICO =====" << endl;

    for (int i = 0; i < nShapes; i++) {
        cout << endl << "Figura [" << i << "]" << endl;
        shapes[i]->Dump();
    }*/
   PrintList(&shapes[0], nShapes);

    // 4. Test funzione scale
    /*cout << endl << "===== DUMP RISCALATO =====" << endl;
    shapes[0]->Scale(0.5);
    shapes[1]->Scale(2.5);
    shapes[2]->Scale(-1);

    for (int i = 0; i < nShapes; i++) {
        cout << endl << "Figura [" << i << "]" << endl;
        shapes[i]->Dump();
    }*/


    // 5. delete shapes
    for (int i = 0; i < nShapes; i++) {
        if(shapes[i] != NULL)
        {
            delete(shapes[i]);
        }
    }

    cout << endl << "===== FINE TEST =====" << endl;

    return 0;
}