#pragma once

#include <iostream>
#include <set>
#include <utility>

using namespace std;

class state_t {
private:
  unsigned id_; //identificador del estado
  bool accept_; //indica si es un nodo de aceptacion
  set<pair<char,const state_t*> > next_; //Conjunto de estados siguientes a la arista

public:
  state_t (const unsigned id, const bool accept = false) : id_(id), accept_(accept) {}
  ~state_t (void) {}

  const unsigned id (void) const {
    return id_;
  }

  const bool is_accept (void) {
    return accept_;
  }

  void set_accept (const bool accept) {
    accept_ = accept;
  }

  //Devuelve el puntero par que contiene dicha letra. Usado para transitar entre los estados
  const state_t* find_by_letter (const char c) {
    if (next_.empty()) return NULL;
    for (set<pair<char,const state_t*> >::iterator it = next_.begin(); it != next_.end(); it++) {
      if (get<0>(*it) == c) { return get<1>(*it); }
    }
    return NULL;
  }

  void insert_pair (const char symbol, const state_t* pointer_state) {
    pair<char,const state_t*> new_pair;
    get<0>(new_pair) = symbol;
    get<1>(new_pair) = pointer_state;
    next_.insert(new_pair);
  }

  const bool operator< (const state_t state) const {
    return (id() < state.id());
  }

  ostream& dbg_write (void) const {
    cout << "\t---- ESTADO " << id_ << " ----\n";
    cout << "Es un nodo de aceptacion?: " << accept_ << "\n";
    cout << "Estados conectados:\n";
    for (set<pair<char,const state_t*>>::iterator it = next_.begin(); it != next_.end(); it++) {
      cout << "Letra: " << get<0>(*it);
      cout << "\tID: " << get<1>(*it)->id() << "\n";
    }
    cout << "------------------------\n";
    return cout;
  }
};
