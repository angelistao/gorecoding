#include <iostream>
#include <sstream>

using namespace std;
#define FullQueueException 1
#define EmptyQueueException 2

#include "Fila.hpp"

Fila::Fila(){
  capacidade = 10;
  fila = new int[capacidade];
  count = 0;
  primeiro = 0;
  ultimo = 0;
}

void Fila::enqueue(int element){
  if (count==capacidade)
    throw FullQueueException;
  fila[ultimo] = element;
  count++;
  ultimo = (ultimo+1)%capacidade;
}

int Fila::dequeue(){
  //vericando se a fila está vazia
  if(count==0)
    throw EmptyQueueException;
  int elem = fila[primeiro];
  count --;
  primeiro = (primeiro+1)%capacidade;
  return elem;
}



int Fila::head(){
  if (count==0)
    throw EmptyQueueException;
  return fila[primeiro];
}

int Fila::size(){
  return this->count;
}

bool Fila::isEmpty(){
  return (count==0);
}

void Fila::clear(){
  delete[] fila;

  fila = new int[capacidade];
  count=0;
  primeiro=0;
  ultimo=0;
}

string Fila::MostraInfo(){
  stringstream ss;
  ss << "Conteúdo da fila: " << endl;
  for(int i=primeiro;i<capacidade; i++){
    ss << fila[i] << endl;
  }

  return ss.str();
}