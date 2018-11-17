#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

#include "state_t.hpp"

class DFA {
private:
  set<state_t> states_; //conjunto de estados
  int all_states_; //cantidad de estados totales
  unsigned init_; //puntero del estado inicial
  set<char> alphabet; //alfabeto sobre el que el automata trabaja
public:
  DFA (void);
  DFA (const set<state_t>& states);
  ~DFA (void);

  const unsigned init (void);

  void create_dfa (const char* nombreFichero);
  bool chain_test (const string& chain);
  set<state_t> dead_states (void);

  ostream& write (void) const;

private:
  const state_t find_by_id (const unsigned id) const;
};
