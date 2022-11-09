#ifndef FILA_HPP
#define FILA_HPP

class Fila {
  int *fila;
  int capacidade;
  int count;
  int primeiro;
  int ultimo;
  public:
    Fila();
    void enqueue(int element);
    int dequeue();
    bool isEmpty();
    int head();
    int size();
    void clear();
    string MostraInfo();
};

#endif