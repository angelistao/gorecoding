#ifndef _NODO
#define _NODO
// ****************************
#include <iostream>
using namespace std;

class NodoSTR{
public:
  // Atributos
    string element;
    NodoSTR *next;
  // Métodos
    NodoSTR();
    NodoSTR(string i);
    NodoSTR(string i, NodoSTR *next);
    
};
#endif 
