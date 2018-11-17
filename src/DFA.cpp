#include "../include/DFA.hpp"

using namespace std;
DFA::DFA (void) : states_(), all_states_(0), init_(-1) {}
DFA::DFA (const set<state_t>& states) : states_ (states), all_states_(0), init_(0){
  all_states_ = states_.size();
}

DFA::~DFA (void) { states_.clear(); }

void DFA::set_init (const unsigned init) {
  init_ = init;
}

const unsigned DFA::init (void) {
  return init_;
}

void DFA::create_dfa (const char* nombreFichero) {
  ifstream fich;
  fich.open(nombreFichero);

  if (!fich.is_open()) { cerr << "Error. El fichero no se ha podido abrir con exito.\n"; }
  assert(fich.is_open());

  bool detector; //Detectara si ya ha leido una vez el texto
  while (!fich.eof()) {
    if (detector == true) { cerr << "Fichero mal organizado.\n"; break; }
    detector = true;

    //Empezamos leyendo el valor de estados totales
    fich >> (int &)all_states_;
    /*Chivato*/ cout << "Estados totales: " << all_states_ << "\n";

    for (int i = 0; i < all_states_; i++) {
      state_t state(i);
      states_.insert(state);
    }
    /*Chivato*/ cout << "Numero de estados totales (tamaño del conjunto): " << states_.size() << "\n";

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
        fich >> (char &)symbol;
        /*Chivato*/ cout << "Simbolo: " << symbol << "\n";
        fich >> (unsigned &)id;
        /*Chivato*/ cout << "ID: " << id << "\n";
        state.insert_pair(symbol, id);
      }
      state.dbg_write();
    }
  }
  fich.close();
}

/*state_t* DFA::find_by_id (const unsigned id) const {
  for (set<state_t>::iterator it = states_.begin(); it != states_.end(); it++) {
    if (it->id() == id) { return &(*it); }
  }
  return NULL;
}*/

ostream& DFA::dbg_write (void) const {
  for (set<state_t>::iterator it = states_.begin(); it != states_.end(); it++) {
    it->dbg_write();
  }
  return cout;
}
