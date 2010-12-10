/*
* O Grupo é um grupo de 9 células, que pode ser a linha, a coluna ou o quadrado.
*
* has_any_repeat -> verifica se no grupo de células há alguma célula repetida.
*
* is_solved -> verifica se o jogo está resolvido.
*/
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

