// Angela Mahlke Ranoff e Vinícius França Mibielli

#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

#include "LinkedListOfString.h"

LinkedListOfString Cabecalhos;
LinkedListOfString ListaDeRuas;
NodoAcidente *dezAcidentes[10];

// ***********************************************************
// Esta funcao recebe a 1a. linha do CSV e separa os nomes das
// colunas colocando-os na lista "Cabecalhos"
// O retorno eh o nro de campos da linha(nro de colunas do CSV)
// ***********************************************************
int LeCabecalhos(string L) {
  stringstream S;
  S.str(L);
  string palavra;
  int cont = 0;

  // passa em cada uma das palavras separadas do ';'
  while (getline(S, palavra, ';')) {
    Cabecalhos.add(palavra);
    cont++;
  }
  //cout << "Nro de campos:" << cont << endl;
  return cont;
}
// ***********************************************************
// Esta funcao recebe uma linha do CSV e separa os dados das
// colunas colocando alguns deles na lista "Acidentes".
// O retorno eh o nro de campos da linha(nro de colunas do CSV)
// ***********************************************************
int DivideLinha(string L) {
  stringstream S;
  S.str(L);
  string palavra;

  // Busca o indice da coluna que tem os campos de interesse
  // na lista de Cabecalhos

  int indLogradouro = Cabecalhos.indexOf("log1");
  int indAuto = Cabecalhos.indexOf("auto");
  int indDiaSemana = Cabecalhos.indexOf("dia_sem");
  int indMoto = Cabecalhos.indexOf("moto");
  int indTipoAcid = Cabecalhos.indexOf("tipo_acid");

  // Passa em cada uma das palavras separadas do ';'
  // A cada passo deste laco, a variavel 'palavra' tem uma das
  // palavras da linha
  // Qdo a coluna da palavra eh igual a uma das colunas de
  // interesse, coloca a palavra na frase de saida
  string NomeDaRua;
  string DiaSemana;
  string TipoAcid;
  int nVeiculos = 0;
  int nMotos = 0;
  int cont = 0;
  while (getline(S, palavra, ';')) {

    if (cont == indLogradouro)
      NomeDaRua = palavra;
    if (cont == indAuto)
      nVeiculos += atoi(palavra.c_str());
    if (cont == indDiaSemana)
      DiaSemana = palavra;
    if (cont == indMoto)
      nMotos += atoi(palavra.c_str());
    if (cont == indTipoAcid)
      TipoAcid = palavra;
    cont++; // conta qtos campos já foram lidos na linha
  }

  // Exercício C.2
  // Substitua a chamada do método a seguir pelo novo método add,
  // que recebe todos dados obtidos em uma linha
  ListaDeRuas.add(NomeDaRua, DiaSemana, nVeiculos, nMotos, TipoAcid);
  // Coloca a rua na lista de ruas

  // ListaDeRuas.addIncreasingOrder(NomeDaRua);

  // cout << "Nro de campos:" << cont << endl;
  return cont; // retorna o nro de palavras da linha
}

// ***********************************************************
// Abre o arquivo e processa cada uma das linhas
// ***********************************************************
void LeArquivo(const char *filename) {
  ifstream arquivo;
  string linha;

  arquivo.open(filename, ios::in);
  if (!arquivo) {
    cout << "Erro na abertura do arquivo '" << filename << endl;
    exit(1);
  }
  // Le a linha de cabecalho
  getline(arquivo, linha);
  if (arquivo.eof()) {

    cout << "Erro na leitura do cabecalho do arquivo" << filename << endl;
    exit(1);
  }

  int nroDeCampos = LeCabecalhos(linha);

  do {
    // le uma linha do arquivo
    getline(arquivo, linha);
    if (arquivo.eof()) // acabou o arquivo?
      break;           // encerra o loop

    // divide a linha em campos e coloca os campos de interesse na lista de
    // acidentes
    int n = DivideLinha(linha);

    // Caso o nro de campos da linha seja diferente do nro de
    // campos do cabecalho, a linha te erro.
    if (n != nroDeCampos) {
      cout << "Linha com nro invalido de campos" << endl;
      cout << "Nro de campos lidos: " << n << endl;
      cout << "Linha lida:" << linha << endl;
      exit(1);
    }

  } while (true);
  cout << "\nLeitura concluida\n" << endl;
}

int main(int argc, const char *argv[]) {

  // LeArquivo("DezLinhas.csv");
  // LeArquivo("cat_vitimas2.csv");
  LeArquivo("PequenoComRepeticoes.csv");

  int escolha = 0;

Lista:
  cout << "=================================================================="
       << endl;
  cout << "          BEM-VINDO AO MENU DE CONSULTAS DE TRÂNSITO" << endl;
  cout << "=================================================================="
       << endl;
  cout << "1- IMPRIMIR LISTA\n2- OS 20 LOGRADOUROS COM MAIS ACIDENTES\n3- DIA "
          "DA SEMANA DE UM DETERMINADO LOGRADOURO COM MAIS ACIDENTES\n4- DEZ "
          "ACIDENTES COM MAIOR NÚMERO DE VEÍCULOS\n5- TOTAL DE ACIDENTES DE "
          "MOTO\n6- REMOVER DETERMINADO TIPO DE ACIDENTE\n9- ENCERRAR PROGRAMA"
       << endl;
  cout << "=================================================================="
       << endl;
  cin >> escolha;

  switch (escolha) {
  case 1:
    system("clear");
    ListaDeRuas.ImprimeLista();
    break;
  case 2:
    system("clear");
    ListaDeRuas.VinteLogradouros();
    break;
  case 3:
    system("clear");
    cout << ListaDeRuas.DiaMaisAcid();
    break;
  case 4:
    system("clear");
    ListaDeRuas.DezAcidentes();
    break;
  case 5:
    system("clear");
    cout << "NÚMERO TOTAL DE ACIDENTES COM MOTO: "<< ListaDeRuas.getAcidentesMotos();
    break;
  case 6:
    system("clear");
    ListaDeRuas.RemoveAcidentes();
    cout << "Remoção realizada -------" << endl;
    ListaDeRuas.ImprimeLista();
    break;
  case 9:
    system("clear");
    return 0;
  default:
    system("clear");
    cout << "Opção inválida!\n";
    cout << "=============================" << endl;
    cout << "Deseja escolher outra opção?\n1- SIM\n2- NÃO\n";
    cout << "=============================" << endl;
    cin >> escolha;
    if (escolha == 1) {
      system("clear");
      goto Lista;

    } else {
      system("clear");
      return 0;
    }
  }
  return 0;
}
