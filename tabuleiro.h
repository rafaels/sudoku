/*
* O Tabuleiro é o conjunto total das células e dos grupos.
* Tem o total de 81 células, 9 colulas, 9 linhas e 9 quadrados.
* Seleciona o jogo, mostra e verifica se está resolvido.
*/

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
