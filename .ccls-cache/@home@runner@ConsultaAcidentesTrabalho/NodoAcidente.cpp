//
//  Acidente.cpp
//  LeCSV
//
//  Created by Márcio Sarroglia Pinho on 21/10/22.
//
#include <iostream>
#include <sstream>
using namespace std;

#include "NodoAcidente.h"

NodoAcidente::NodoAcidente(string dia, int nVeiculos, int nMotos, string TipoAcidente) {
  this->TipoAcidente = TipoAcidente;
  this->dia = dia;
  this->nVeiculos = nVeiculos;
  this->nMotos = nMotos;
  this->next = NULL;
}

string NodoAcidente::toString() {
  stringstream SS; // usado para converter inteiro para string
  string S;

  SS << "Dia: " << dia << ", ";
  SS << "Número de Veículos: " << nVeiculos << ", ";
  SS << "Número de Motos: " << nMotos << ",";
  SS << "Tipo de Acidente: " << TipoAcidente << endl;

  S = SS.str();
  return S;
}

int NodoAcidente::SomaVeiculos() {
  int somaTotal = nVeiculos + nMotos;
  return somaTotal;
}
