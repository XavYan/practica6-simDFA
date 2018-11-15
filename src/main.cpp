#include <iostream>

using namespace std;

int main (void) {

  pair<int,char> hola(4,'h');

  cout << get<0>(hola) << "," << get<1>(hola) << "\n";
  return 0;
}
