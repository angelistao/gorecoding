#ifndef CLUBE_HPP
#define CLUBE_HPP

#include <string>

class Clube {
  private:
    std::string Nome;
    int numVitorias;
    int numDerrotas;
    int numEmpates;  
    int golsFeitos;
    int golsTomados;
    int SaldoGols;
  public:
    Clube();
    Clube(std::string n);
    std::string getNome();
    int getNumVitorias();
    void setNumVitorias(int nV);
    int getNumDerrotas();
    void setNumDerrotas(int nD);
    int getNumEmpates();
    void setNumEmpates(int nE);
    void RegistraJogo(int gF, int gT);
    int getSaldoGols();
    std::string ImprimeInfo();
};

#endif 