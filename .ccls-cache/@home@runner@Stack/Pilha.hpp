#ifndef PILHA_HPP
#define PILHA_HPP

class Pilha {
  int count;
  int *pilha;
  int capacidade;
  public: 
    Pilha();
    void push(int element);
    int pop();
    int top();
    int size();
    bool isEmpty();
    void clear();
};

#endif