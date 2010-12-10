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
    Celula * get_celula(int linha, int coluna);
    void imprime_tabuleiro();
};
