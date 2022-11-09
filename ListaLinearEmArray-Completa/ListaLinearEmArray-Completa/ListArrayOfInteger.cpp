#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

#define TAM_MAX 10

// ******************************************
//  Classe ListArrayOfInteger
// ******************************************


class ListArrayOfInteger {
    private:
        int *data;
        int count;
        int tamVet;
    public:
        ListArrayOfInteger();
        ListArrayOfInteger(int tam);
        void clear();
        bool isEmpty();
        int size();
        void add(int element);
        int get(int index);
        void setCapacity(int newCapacity);
        int set(int index, int element);
        bool contains(int element);
        void add(int index, int element);
        bool remove(int element);
        int removeByIndex(int index);
        int indexOf(int element);
        bool containsRecursivo(int element);
        bool containsRecursivoAux(int element, int i);
        int* subList (int fromIndex , int toIndex);
        string toString();
        void printList();
        void reverse();
        int countOccurrences(int element);
        void addIncreasingOrder(int element);

};

/**
 * Construtor da lista.
 */
ListArrayOfInteger::ListArrayOfInteger() {
    tamVet = TAM_MAX;
    count = 0;
    data = new int[tamVet]; //data = (int*) malloc( sizeof(int) * tamVet );
}

/**
 * Construtor da lista.
 * @param tam tamanho inicial a ser alocado para data
 */
ListArrayOfInteger::ListArrayOfInteger(int tam) {
    if (tam<=0)
        tamVet = TAM_MAX;
    else {
        tamVet = tam;
    }
    data = new int[tamVet]; // data = (int*) malloc( sizeof(int) * tamVet );
    count = 0;
}

/**
 * Esvazia a lista.
 */
void ListArrayOfInteger::clear(){
    tamVet = TAM_MAX;
    count = 0;
    delete[] data; // Libera os dados da lista antiga - free(data);
    data =  new int[tamVet]; // Aloca a lista nova - data = (int*) malloc( sizeof(int) * tamVet );
}

/**
 * Retorna true se a lista nao contem elementos.
 * @return true se a lista nao contem elementos
 */
bool ListArrayOfInteger::isEmpty(){
    return count==0;
}

/**
 * Retorna o numero de elementos armazenados na lista.
 * @return o numero de elementos da lista
 */
int ListArrayOfInteger::size(){
    return count;
}

/**
 * Adiciona um elemento ao final da lista.
 * @param element elemento a ser adicionado ao final da lista
 */
void ListArrayOfInteger::add(int element) {
    if (count == tamVet)
        setCapacity(tamVet * 2);

    data[count] = element;
    count++;
}

/**
 * Retorna o elemento de uma determinada posicao da lista.
 * @param index a posicao da lista
 * @return o elemento da posicao especificada
 * @throws exception se (index < 0 || index >= size())
 */
int ListArrayOfInteger::get(int index) {
    if (index<0 || index>=count) {
        throw 0;
    }
    return data[index];
}

/**
 * Cria uma string com os elementos da lista separados por
 * virgula.
 * @return string com os elementos da lista
 */
string ListArrayOfInteger::toString()
{
    stringstream SS; // usado para converter inteiro para string

    for(int i=0; i<count-1; i++) {
        SS << data[i] << ", ";
    }
    SS << data[count-1];

    string S;
    S = SS.str();
    return S;
}

// Redefine o tamanho do array data que armazena os elementos da lista.
// Copia os dados do array antigo para o array novo.
// Caso o array novo seja menor, os dados excedentes serao perdidos.
// Ao final do metodo, os dados do array antigo sao liberados.
void ListArrayOfInteger::setCapacity(int newCapacity) {
        if (newCapacity != tamVet) {
            int min = 0;
            int *newData = new int[newCapacity]; // int *newData = (int*) malloc( sizeof(int) * newCapacity );
            if (tamVet < newCapacity) {
                min = tamVet;
            } else {
                min = newCapacity;
            }
            if (count >= min)
                count = min;
            for (int i = 0; i < min; i++) {
                newData[i] = data[i];
            }
            delete[] data; // Libera os dados da lista antiga - free(data);
            data = newData;
            tamVet = newCapacity;
        }
}

void ListArrayOfInteger::printList() {
    for(int i=0; i<count; i++) {
        cout << data[i] << endl;
    }
}

/**
 * Substitui o elemento armazenado em uma determinada posicao da lista pelo
 * elemento passado por parametro, retornando o elemento que foi substituido.
 * @param index a posicao da lista
 * @param element o elemento a ser armazenado na lista
 * @return o elemento armazenado anteriormente na posicao da lista
 * @throws exception se (index < 0 || index >= size())
 */
int ListArrayOfInteger::set(int index, int element) {
        if ((index < 0) || (index >= size())) {
            throw 0;
        }
        int aux = data[index];
        data[index] = element;
        return aux;
}

/**
 * Procura pelo elemento passado por parametro na lista e retorna true se a
 * lista contem este elemento.
 * @param element o elemento a ser procurado
 * @return true se a lista contem o elemento passado por parametro
 */
bool ListArrayOfInteger::contains(int element) {
        for (int i = 0; i < count; i++) {
            if (data[i]==element) {
                return true;
            }
        }
        return false; // Neste ponto, não achou, retorna falso
}



////////////////////////////////////////////
// PARA FAZER JUNTO COM A PROFESSORA
////////////////////////////////////////////

/**
 * Insere um elemento em uma determinada posicao da lista
 * @param index a posicao da lista onde o elemento sera inserido
 * @param element elemento a ser inserido
 * @throws exception se (index < 0 || index > size())
 */
void ListArrayOfInteger::add(int index, int element) {
        // Primeiro verifica index eh valido
        if (index < 0 || index > size())
            throw 0; // erro

        // Verifica se tem espaco em "data"
        if (count == tamVet)
            setCapacity(tamVet*2);

        for(int i=count; i>index; i--)
            data[i] = data[i-1];

        data[index] = element; // insere o elemento
        count++; // atualiza o contador
}

/**
 * Remove a primeira ocorrencia do elemento na lista, se estiver presente
 * @param element o elemento a ser removido
 * @return true se a lista contem o elemento especificado
 */
bool ListArrayOfInteger::remove(int element) {
        for (int i=0; i<count; i++) {
            if (element==data[i]) { // se achou element
                // Faz a remocao
                for (int j=i; j<count-1; j++) {
                    data[j] = data[j+1];
                }
                data[count-1] = NULL; // opcional
                count--; // atualiza o contador
                return true;
            }
        }

        return false;
}



////////////////////////////////////////////
// EXERCICIOS: Implemente os metodos conforme
// a documentacao e indique a notacao O().
////////////////////////////////////////////

/**
 * Remove o elemento de uma determinada posicao da lista
 * @param index a posição da lista
 * @return o elemento que foi removido da lista
 * @throws exception se (index < 0 || index >= size())
 */
int ListArrayOfInteger::removeByIndex(int index) {
        // Primeiro verifica se index eh valido
          if (index < 0 || index >= size()) {
            throw 0;
        }

        // Guarda o elemento da posicao index em uma variavel
         int aux = data[index];

        // Remove o elemento da posicao index
        for (int i = index; i < count - 1; i++) {
            data[i] = data[i + 1];
        }

        // Atualiza o count
        count--;

        // Retorna o elemento removido
        return aux;
}

/**
 * Retorna o indice da primeira ocorrencia do elemento na lista, ou -1 se a
 * lista nao contem o elemento
 * @param element o elemento a ser buscado
 * @return o indice da primeira ocorrencia do elemento na lista, ou -1 se a
 * lista nao contem o elemento
 */
int ListArrayOfInteger::indexOf(int element) {
        // apresente a implementacao
        // [5,6,7,2,1,9,4]
        //  0 1 2 3 4 5 6
        // Procura elemento no array, se achar retorna o índice
        for (int i = 0; i < count; i++) {
            if (data[i]==element) {
                return i;
            }
        }
        // Neste ponto, não achou: retorna -1
        return -1;
 }

/**
 * Procura pelo elemento passado por parametro na lista e retorna true se a
 * lista contem este elemento.
 * @param element o elemento a ser procurado
 * @return true se a lista contem o elemento passado por parametro
 */
bool ListArrayOfInteger::containsRecursivo(int element) {
    return containsRecursivoAux(element, 0);
}
bool ListArrayOfInteger::containsRecursivoAux(int element, int i) {
        if (i>=count)
            return false;
        else if (data[i]==element)
            return true;
        else
            return containsRecursivoAux(element,i+1);
}

/**
 * Retorna um arranjo que contem os elementos da lista original entre
 * fromIndex (inclusivo) e toIndex (exclusivo).
 * @param fromIndex posicao a partir da qual os elementos serao inseridos no
 * arranjo a ser retornado
 * @param toIndex indica a posicao final dos elementos que devem ser inseridos
 * @return Um arranjo com um subconjunto dos elementos da lista.
 * @throws exception se (fromIndex < 0 || toIndex > size)
 * @throws exception se (fromIndex > toIndex)
 */
int* ListArrayOfInteger::subList (int fromIndex , int toIndex) {
        // [15,11,12,53,34,25,86,97,18,39]
        //   0  1  2  3  4 5  6  7   8  9
        // lista.subList(2,7) -> [12,53,34,25,86]

        // Primeiro verifica se os índices são válidos
        if (fromIndex < 0 || toIndex > size())
            throw 0; // erro
        if (fromIndex >= toIndex)
            throw 0; //erro

        // Cria o vetor auxiliar
        int *vetAux = new int[toIndex-fromIndex];

        // Copia os elementos para o vetor auxiliar
        int j=0;
        for(int i=fromIndex; i<toIndex; i++) {
             vetAux[j] = data[i];
             j++;
        }

        // Retorna o vetor auxiliar
        return vetAux;
}

/**
 * Inverte o conteudo da lista.
 */
void ListArrayOfInteger::reverse() {
        //  0 1 2 3 4 5 6 7 8 9
        // [4,3,2,1, , , , , , ] data
        // count=4
        // for(int i=0, f=count-1; i<count/2; i++,j--)
        if (count>1) {
            int j = count-1;
            for(int i=0; i<count/2; i++) {
                int aux = data[i];
                data[i] = data[j];
                data[j] = aux;
                j--;
            }
        }
}


/**
 * Conta o numero de ocorrencias do elemento passado
 * por parametro
 * @param element elemento a ser procurado para contar
 * as ocorrencias
 * @return numeros de ocorrencias de element
 */
 int ListArrayOfInteger::countOccurrences(int element) {
        // data [3,6,2,3,7,4,6,3,8, , , , , ]
        // count = 9
        // lista.countOccurrences(3) -> 3
        // lista.countOccurrences(8) -> 1

        int contador = 0;

        // Percorre a lista e procura por element,
        // sempre que encontrar element, incrementa
        // contador
        for(int i=0; i<count; i++) {
            if (data[i]== element) {
                contador++;
            }
        }

        return contador;
}


// [8,10,11,12,,,]
void ListArrayOfInteger::addIncreasingOrder(int element) {

}


// ******************************************
//  main
// ******************************************
int main()
{
        ListArrayOfInteger lista;

        lista.add(2);
        lista.add(4);
        lista.add(6);
        lista.add(8);
        lista.add(10);
        lista.add(0,0);
        lista.add(1,1);

        cout << "Elemento armazenado na primeira posicao da lista: " << lista.get(0) << endl;
        cout << "Elemento armazenado na ultima posicao da lista: " << lista.get(lista.size()-1) << endl;

        cout << lista.toString() << endl;

        cout << "remove 7? " << lista.remove(7) << endl;
        cout << "remove index 2: " << lista.removeByIndex(2) << endl;

        lista.set(0,10);

        cout << endl;
        cout << "Lista contem 10? " << lista.contains(10) << endl;
        cout << "Lista contem 20? " << lista.contains(20) << endl;


        cout << "Lista contem 8? " << lista.containsRecursivo(8) << endl;
        cout << "Lista contem 88? " << lista.containsRecursivo(88) << endl;


        lista.printList();
        int *a = lista.subList(1,4);
        cout << "SubList(1,4)" << endl;
        for(int i=0; i<3; i++) {
            cout << "a[" << i << "]=" << a[i] << endl;
        }
}
