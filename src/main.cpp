#include "../include/DFA.hpp"

//ERRORES CON LAS CONSTANTES. DOS POSIBLES SOLUCIONES:
// 1. CAMBIAR LOS SET POR VECTORES
// 2. QUE EL CONJUNTO DE PARES DE CADA ESTADO, EL SEGUNDO
// VALOR DE LOS PARES SEA EL IDENTIFICADOR, EN VEZ DEL PUNTERO AL SIGUIENTE ESTADO

int main (void) {

  char nombreFichero[100];

  DFA dfa;
  cout << "Indique el nombre del fichero a cargar: ";
  cin >> nombreFichero;
  dfa.create_dfa(nombreFichero);

  //dfa.dbg_write();
  return 0;
}
