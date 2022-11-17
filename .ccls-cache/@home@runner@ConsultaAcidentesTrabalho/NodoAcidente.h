//
//  NodoAcidente.hpp
//  LeCSV
//
//  Created by Márcio Sarroglia Pinho on 21/10/22.
//

#ifndef Acidente_hpp
#define Acidente_hpp


#include <iostream>
using namespace std;

class NodoAcidente{
public:
    NodoAcidente *next;
    string dia;
    int nVeiculos, nMotos, NumAcidentes;
    string TipoAcidente;
    string toString();
    NodoAcidente(string dia, int nVeiculos, int nMotos, string TipoAcidente);
    int SomaVeiculos();
};
    

#endif /* Acidente_hpp */
