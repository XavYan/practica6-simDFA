#include "../include/DFA.hpp"

//FALTA:
// 1. SEPARAR LAS DECLARACIONES DE LAS IMPLEMENTACIONES.
// 2. HACER MAKEFILE
// 3. INTENTAR LOGRAR EL UNICO FALLO QUE ME QUEDA POR EVITAR
// 4. HACER MAIN
// 5. QUITAR CHIVATOS

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
