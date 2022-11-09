#include <iostream>

using namespace std;

#include "Pilha.hpp"

#define FullStackException 1
#define EmptyStackException 2

Pilha::Pilha(){
  capacidade = 10;
  pilha = new int[capacidade];
  count = 0;
}

void Pilha::push(int element){
  if (count==capacidade)
    throw FullStackException;
  pilha[count] = element;
  count++;
}

//remove e retorna o elemento do topo da pilha
int Pilha::pop(){
  if (count==0)
    throw EmptyStackException;
  int num = pilha[count-1];
  count--;
  return num;
}

int Pilha::top(){
  if (count==0)
    throw EmptyStackException;
  return pilha[count-1];
}

void Pilha::clear(){
  delete[] pilha;
  pilha = new int[capacidade];
  count = 0;
}