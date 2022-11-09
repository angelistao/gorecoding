#include <iostream>
#include "Clube.hpp"

using namespace std;

int main() {
  Clube i("Internacional");

  i.RegistraJogo(2, 0);
  i.RegistraJogo(2, 1);

  Clube R("Real Madrid");

  R.RegistraJogo(3, 0);
  R.RegistraJogo(4, 2);

  cout << i.ImprimeInfo() << endl;
  cout << R.ImprimeInfo() << endl;
  
  
  
}