//
//  main.cpp
//  LeArquivo
//
//  Created by Márcio Sarroglia Pinho on 31/10/21.
//

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

#include "LinkedListOfString.h"

LinkedListOfString Cabecalhos;
LinkedListOfString Acidentes;

// ***********************************************************
// Esta funcao recebe a 1a. linha do CSV e separa os nomes das
// colunas colocando-os na lista "Cabecalhos"
// O retorno eh o nro de campos da linha(nro de colunas do CSV)
// ***********************************************************
int LeCabecalhos(string L)
{
    //cout << "Linha:" << L << "*"<< endl;
    stringstream S;
    S.str(L);
    string palavra;
    int cont=0;
    
    // passa em cada uma das palavras separadas do ';'
    while (getline(S, palavra, ';'))
    {
      Cabecalhos.add(palavra);
      cont++;
    }
    cout << "Nro de campos:" << cont << endl;
    return cont;
}
// ***********************************************************
// Esta funcao recebe uma linha do CSV e separa os dados das
// colunas colocando alguns deles na lista "Acidentes".
// O retorno eh o nro de campos da linha(nro de colunas do CSV)
// ***********************************************************
int DivideLinha(string L)
{
    stringstream S;
    S.str(L);
    string palavra;
    
    // Busca o indice da coluna que tem os campos de interesse
    // na lista de Cabecalhos
    int indLogradouro = Cabecalhos.indexOf("log1");
    //cout << "Indice da coluna Logradouro:"  << indLogradouro << endl;
    int indHora = Cabecalhos.indexOf("hora");
    //cout << "Indice da coluna Hora:"  << indHora << endl;
    
    int cont=0;
    string frase;
    // Passa em cada uma das palavras separadas do ';'
    // A cada passo deste laco, a variavel 'palavra' tem uma das
    // palavras da linha
    // Qdo a coluna da palavra eh igual a uma das colunas de
    // interesse, coloca a palavra na frase de saida
    while (getline(S, palavra, ';'))
    {
        if (cont == indHora) // se for a hora adiciona na
            frase = palavra;
        if (cont == indLogradouro) // se for a rua
            frase = frase + " - " + palavra;
        cont++; // conta qtos campos já foram lidos na linha
    }
    // Coloca a frase na lista de acidentes
    Acidentes.add(frase);
   
    //cout << "Nro de campos:" << cont << endl;
    return cont; // retorna o nro de palavras da linha
}

// ***********************************************************
// Abre o arquivo e processa cada uma das linhas
// ***********************************************************
void LeArquivo(const char *filename)
{
    ifstream arquivo;
    string linha;
    
    arquivo.open(filename,ios::in);
    if (!arquivo)
    {
        cout << "Erro na abertura do arquivo '" << filename << endl;
        exit(1);
    }
    // Le a linha de cabecalho
    getline(arquivo, linha);
    if (arquivo.eof())
    {
        cout << "Erro na leitura do cabecalho do arquivo" << filename << endl;
        exit(1);
    }
    
    int nroDeCampos = LeCabecalhos(linha);
    cout << "Lista de Cabecalhos:" << endl;
    Cabecalhos.ImprimeLista();

    do {
        // le uma linha do arquivo
        getline(arquivo, linha);
        if (arquivo.eof()) // fim do arquivo?
            break; // encerra o loop
        
        // divide a linha em campos e coloca os campos de interesse na lista de acidentes
        int n = DivideLinha(linha);
        
        // Caso o nro de campos da linha seja diferente do nro de
        // campos do cabecalho, a linha te erro.
        if (n!=nroDeCampos)
        {
            cout << "Linha com nro invalido de campos" << endl;
            cout << "Nro de campos lidos: " << n << endl;
            cout << "Linha lida:" << linha << endl;
            exit(1);
        }
     
    } while (true);
    cout << "Leitura concluida" << endl;
    
    cout << "Lista de Acidentes:" << endl;
    Acidentes.ImprimeLista();
    
}

int main(int argc, const char * argv[]) {
    
    LeArquivo("DezLinhas.csv");
    //LeArquivo("cat_vitimas2.csv");

    return 0;
}
