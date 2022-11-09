#include "fila.h"

//construtora

#define FullQueueException 1
#define EmptyQueueException 2

FilaArray::FilaArray(){
  capacidade = 10;
  fila = new int[capacidade];
  primeiro = 0;
  ultimo = 0;
  count = 0;
}


//insere o elemento no final da fila
void FilaArray::enqueue(int element){
  //primeiro, verificar se há espaço no array
  if(count==capacidade){
    throw FullQueueException;
  } 
  fila[ultimo]=element;
  count++;
  ultimo=(ultimo+1)%capacidade;
  //pega o indice ultimo e divide pelo total de elementos
  //por exemplo, em um vetor de 10 elementos (indices de 0 a 9)
  // - se o ultimo estava na posicao 4: 5/10, o resto é 5
  // - se o ultimo estava na posicao 9: 10/10, resto é 0
}

//remove e retorna o elemento do inicio da fila
// da erro se a fila estiver vazia
int FilaArray::dequeue(){
  //primeiro verifica se a fila está vazia 
  if(count==0){
    throw EmptyQueueException;
  }
  int elem = fila[primeiro];
  count--;
  primeiro=(primeiro+1)%capacidade;
  return elem;
}

//retorna 1 se a fila estiver vazia e 0 se estiver cheia
bool FilaArray::isEmpty(){
  return count == 0;
}

//retorna mas não remover o primeiro elemento da fila
//dá erro se a fila estiver vazia
int FilaArray::head(){
  if(count == 0 ){
    throw EmptyQueueException;
  }
  return fila[primeiro];
}

int FilaArray::size(){
  return count;
}

//esvaziar fila
void FilaArray::clear(){
  delete fila;

  fila = new int[capacidade];
  primeiro=0;
  ultimo=0;
  count=0;
}

