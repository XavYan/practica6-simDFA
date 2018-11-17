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

  dfa.write();

  string s;
  cout << "Indica una cadena: ";
  cin >> s;
  cout << "Cadena aceptada: " << dfa.chain_test(s) << "\n";

  cout << "\t---- ESTADOS DE MUERTE ----\n";
  set<state_t> states = dfa.dead_states();

  if (states.size() == 0) cout << "\tNo hay estados de muerte.\n"; else {
    cout << "\tHay " << states.size() << " estado" << (states.size() > 1 ? "s" : "") << " de muerte, " << (states.size() > 1 ? "los cuales son" : "el cual es") << ": ";
    cout << "{";
    for (set<state_t>::iterator it = states.begin(); it != states.end(); it++) {
      cout << it->id() << ",";
    }
    cout << "}\n";
  }

  return 0;
}
