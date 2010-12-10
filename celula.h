/*
* A celula se refere a cada numero preenchido pelo jogo (quando o jogo é iniciado)
* ou pelo jogador durante suas jogadas.
*
* is_constant_flag -> serve para identificar se uma célula foi preenchida pelo
* jogo ou pelo jogador, se preenchida pelo jogo então é um valor constante (ou seja,
* não pode ser alterado pelo jogador)
*/

class Celula {
  private:
    int value;
    bool is_constant_flag;
  public:
    Celula();
    Celula(int new_value);
    int get_value();
    void set_value(int new_value);
    bool is_constant();
};

