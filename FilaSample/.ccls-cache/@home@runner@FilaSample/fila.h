#ifndef Fila_h
#define Fila_h

class FilaArray {
  int *fila;
  int capacidade;
  int count;
  int primeiro;
  int ultimo;
  public:
    FilaArray();
    void enqueue(int element);
    int dequeue();
    bool isEmpty();
    int head();
    int size();
    void clear();
};

#endif