#include <iostream>
#include <cstdlib>
using namespace std;

#include "Fila.hpp"

int main() {
  Fila fila;

  fila.enqueue(2);
  fila.enqueue(4);
  fila.enqueue(6);
  fila.enqueue(8);
  fila.enqueue(10);
  fila.enqueue(12);
  fila.enqueue(14);
  fila.enqueue(16);
  fila.enqueue(18);
  fila.enqueue(20);

  fila.dequeue();
  fila.dequeue();

  if(fila.isEmpty()==false)
    cout << "Fila possui " << fila.size() << " elementos." << endl;

  cout << "Primeiro elemento da fila é o " << fila.head() << endl;
  cout << fila.MostraInfo() << endl;
}