#include <sstream>
#include "Clube.hpp"

Clube::Clube(){
  
}

Clube::Clube(std::string n){
  this->Nome = n;
  this->numVitorias = 0;
  this->numDerrotas = 0;
  this->numEmpates = 0;
  this->golsFeitos = 0;
  this->golsTomados = 0;
  this->SaldoGols = 0;
}

std::string Clube::getNome(){
  return this->Nome;
}

int Clube::getNumVitorias(){
  return this->numVitorias;
}

void Clube::setNumVitorias(int nV){
  this->numVitorias = nV;
}

int Clube::getNumDerrotas(){
  return this->numDerrotas;
}

void Clube::setNumDerrotas(int nD){
  this->numDerrotas = nD;
}

int Clube::getNumEmpates(){
  return this->numEmpates;
}

void Clube::setNumEmpates(int nE){
  this->numEmpates = nE;
}

void Clube::RegistraJogo(int gF, int gT){
  golsFeitos = gF;
  golsTomados = gT;
  
  if(golsFeitos > golsTomados)
    numVitorias++;
  else if (golsFeitos < golsTomados)
    numDerrotas++;
  else if (golsFeitos == golsTomados)
    numEmpates++;  
}


int Clube::getSaldoGols(){
  SaldoGols = golsFeitos - golsTomados;
  return this->SaldoGols;
}

std::string Clube::ImprimeInfo(){
  std::stringstream ss;
  
  ss << "Nome do Clube: " << this->getNome() << std::endl;
  ss << "Número de Vitórias: " << this->getNumVitorias() << std::endl;
  ss << "Número de Derrotas: " << this->getNumDerrotas() << std::endl;
  ss << "Número de Empates: " << this->getNumEmpates() << std::endl;
  ss << "Saldo de gols: " << getSaldoGols() << std::endl;

  return ss.str();
}

