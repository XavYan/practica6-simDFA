
class state_t {
private:
  char* id_; //identificador del estado
  bool accept_; //indica si es un nodo de aceptacion

public:
  state_t (char* id, bool accept = false) : id_(id), accept_(accept) {}
  ~state_t (void) { id_ = NULL; }

  const char* id (void) {
    return id_;
  }

  const bool is_init (void) {
    return init_;
  }

  const bool is_last (void) {
    return last_;
  }
};
