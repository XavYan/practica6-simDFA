#pragma once

#include <iostream>
#include <set>
#include <utility>

using namespace std;

class state_t {
private:
  unsigned id_; //identificador del estado
  bool accept_; //indica si es un nodo de aceptacion
  set<pair<char, unsigned> > next_; //Conjunto de estados siguientes a la arista

public:
  state_t (const unsigned id, const bool accept = false) : id_(id), accept_(accept) {}
  ~state_t (void) {}

  const unsigned id (void) const {
    return id_;
  }

  set<pair<char, unsigned> > getNext (void) const {
    return next_;
  }

  const bool is_accept (void) {
    return accept_;
  }

  void set_accept (const bool accept) {
    accept_ = accept;
  }

  //Devuelve el puntero par que contiene dicha letra. Usado para transitar entre los estados
  unsigned find_by_letter (const char c) {
    if (next_.empty()) return -1;
    for (set<pair<char,unsigned> >::iterator it = next_.begin(); it != next_.end(); it++) {
      if (get<0>(*it) == c) { return get<1>(*it); }
    }
    return -1;
  }

  void insert_pair (const char symbol, const unsigned id) {
    pair<char,unsigned> new_pair;
    get<0>(new_pair) = symbol;
    get<1>(new_pair) = id;
    next_.insert(new_pair);
  }

  const bool operator< (const state_t state) const {
    return (id() < state.id());
  }

  ostream& write (void) const {
    cout << "\t---------- ESTADO " << id_+1 << " -----------\n";
    cout << "\tEs un nodo de aceptacion?: " << accept_ << "\n";
    cout << "\tEstados conectados:\n";
    for (set<pair<char,unsigned>>::iterator it = next_.begin(); it != next_.end(); it++) {
      cout << "\tLetra: " << get<0>(*it);
      cout << "\tID: " << get<1>(*it) << "\n";
    }
    cout << "\t-------------------------------\n";
    return cout;
  }
};
