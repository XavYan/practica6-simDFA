#include "../include/DFA.hpp"

using namespace std;
DFA::DFA (void) : states_(), all_states_(0), init_(-1) {}
DFA::DFA (const set<state_t>& states) : states_ (states), all_states_(0), init_(-1){
  all_states_ = states_.size();
}

DFA::~DFA (void) { states_.clear(); }

const unsigned DFA::init (void) {
  return init_;
}

void DFA::create_dfa (const char* nombreFichero) {
  states_.clear();
  ifstream fich;
  fich.open(nombreFichero);

  if (!fich.is_open()) { cerr << "Error. El fichero no se ha podido abrir con exito.\n"; }
  assert(fich.is_open());

  //Empezamos leyendo el valor de estados totales
  fich >> (int &)all_states_;
  /*Chivato*/ cout << "Estados totales: " << all_states_ << "\n";

  //Leemos el estado de arranque del DFA
  fich >> (unsigned &)init_;
  /*Chivato*/ cout << "Estado de arranque del DFA: " << init_ << "\n";

  //Leemos, para cada estado, sus diferentes valores
  /*Chivato*/ cout << "Lectura de los valores de cada estado:\n";
  unsigned id, accepted, transition;
  char symbol;
  for (int i = 0; i < all_states_; i++) {
    //Primero el ID y si es de aceptacion
    fich >> (unsigned &)id >> (unsigned &)accepted;
    /*Chivato*/ cout << "ID: " << id << "\n";
    /*Chivato*/ cout << "Aceptado?: " << accepted << "\n";

    //Obtenemos el estado e indicamos si es de aceptacion
    state_t state(id,accepted);

    //Recogemos el numero de transiciones de cada estado
    fich >> (unsigned &)transition;
    /*Chivato*/ cout << "Numero de transiciones que tiene: " << transition << "\n";

    //Procedemos a leer los estados sucesores para cada estado
    for (int j = 0; j < transition; j++) {
      set<char> symbol_read;
      fich >> (char &)symbol;
      if (alphabet.find(symbol) == alphabet.end()) alphabet.insert(symbol);
      if (symbol_read.find(symbol) != symbol_read.end())
        cerr << "Error. Letra repetida en la definicion de las aristas del estado " << state.id()+1 << ". DFA erroneo.\n";
      assert(symbol_read.find(symbol) == symbol_read.end());
      symbol_read.insert(symbol);
      /*Chivato*/ cout << "Simbolo: " << symbol << "\n";
      fich >> (unsigned &)id;
      /*Chivato*/ cout << "ID: " << id << "\n";
      state.insert_pair(symbol, id);
    }
    states_.insert(state);
  }
  fich.close();
}

set<state_t> DFA::dead_states (void) {
  set<state_t> deadStates;
  for (set<state_t>::iterator i = states_.begin(); i != states_.end(); i++) {
    bool is_dead = true;
    for (set<pair<char,unsigned> >::iterator j = i->getNext().begin(); j != i->getNext().end(); j++) {
      if (i->id() != get<1>(*j)) { is_dead = false; break; }
    }
    if (is_dead) deadStates.insert(*i);
  }
  return deadStates;
}

const state_t DFA::find_by_id (const unsigned id) const {
  for (set<state_t>::iterator it = states_.begin(); it != states_.end(); it++) {
    if (it->id() == id) { return *it; }
  }
  return *(new state_t (-1));
}

bool DFA::chain_test (const string& chain) {
  state_t aux = find_by_id(init_);
  unsigned cid;
  for (int i = 0; i < chain.length(); i++) {
    cid = aux.find_by_letter(chain[i]);
    if (cid != -1) aux = find_by_id(cid); else return false;
  }
  if (aux.is_accept()) return true; else return false;
}

ostream& DFA::write (void) const {
  for (set<state_t>::iterator it = states_.begin(); it != states_.end(); it++) {
    it->write();
  }
  return cout;
}
