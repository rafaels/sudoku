#include "tabuleiro.cpp"
#include "pilha_de_jogadas.cpp"

class Jogo {
  private:
    PilhaDeJogadas anteriores;
    PilhaDeJogadas proximas;
    Tabuleiro * tabuleiro;
    bool solved;

  public:
    Jogo();
    void jogar(int linha, int coluna, int valor);
    bool is_solved();
    void undo();
    void redo();
    Tabuleiro * get_tabuleiro();
};

