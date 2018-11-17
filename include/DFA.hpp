#pragma once

#include <iostream>
#include <fstream>
#include <cassert>

#include "state_t.hpp"

class DFA {
private:
  set<state_t> states_; //conjunto de estados
  int all_states_; //cantidad de estados totales
  unsigned init_; //puntero del estado inicial
public:
  DFA (void);
  DFA (const set<state_t>& states);
  ~DFA (void);

  void set_init (const unsigned init);
  const unsigned init (void);

  void create_dfa (const char* nombreFichero);
  ostream& dbg_write (void) const;

private:
  //state_t* find_by_id (const unsigned id) const;
};
