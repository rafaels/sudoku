#include "grupo.cpp"

class Tabuleiro {
  private:
    Celula * celulas[81];
    Grupo * colunas[9];
    Grupo * linhas[9];
    Grupo * quadrados[9];
  public:
    Tabuleiro();
    bool is_solved();
    void imprime_tabuleiro();
};
