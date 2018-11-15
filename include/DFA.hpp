#include "state_t.hpp"
#include <set>

class DFA {
private:
  set<state_t> states_; //conjunto de estados
  int all_states_; //cantidad de estados totales
  char* init_; //identificador del estado inicial
public:
  DFA (const set<state_t>& states);
  ~DFA (void);

  void set_init (const char* init);
  const char* init (void);
};
