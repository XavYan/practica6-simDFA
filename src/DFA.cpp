#include <iostream>
#include "../include/DFA.hpp"

using namespace std;

DFA::DFA (const set<state_t>& states) : states_ (), all_states_(0), init_(NULL){
  for (set<state_t>::iterator it = states.begin(); it != states.end(); it++) {
    states_.insert(*it);
    all_states_++;
  }
}
