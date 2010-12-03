#include "celula.cpp"

class Grupo {
  private:
    Celula * celulas[9];
  public:
    Grupo();
    Celula * get_celula(int posicao);
    void set_celula(Celula * celula, int posicao);
    bool has_any_repeat();
    bool is_solved();
};

