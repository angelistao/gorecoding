#ifndef _NODO
#define _NODO
// ****************************
#include <iostream>
using namespace std;
#include "LinkedListOfAcidente.h"

class NodoSTR{
public:
  // Atributos
    string element;
    LinkedListOfAcidente AcidentesNaRua; // devera conter os acidentes da rua
    NodoSTR *next;
  // Métodos
    NodoSTR();
    NodoSTR(string i);
    NodoSTR(string i, NodoSTR *next);
    
};
#endif 
