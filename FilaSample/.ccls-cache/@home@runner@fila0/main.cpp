#include <iostream>
#include <cstdlib>
using namespace std;

#include "fila.h"

int main() {
  FilaArray fila;

  if(fila.isEmpty()){
    cout << "Fila vazia" << endl;
  }

  fila.enqueue(1);
  fila.enqueue(2);
  fila.enqueue(3);
  fila.enqueue(4);

  cout << "Retirando da fila: " << fila.dequeue() << endl;
  cout << "Início da fila: " << fila.head() << endl;
  cout << "Temos " << fila.size() << " elementos na fila" << endl;

  fila.clear();
  if(fila.isEmpty()){
    cout << "Fila vazia" << endl;
  }

  cout << "Temos " << fila.size() << " elementos na fila" << endl;
  fila.enqueue(4);
  cout << "Temos " << fila.size() << " elementos na fila" << endl;
  
}