/*
* O Jogo está relacionado com a "ação de jogar".
* Contém as pilhas das jogadas próximas e anteriores e o tabuleiro.
*
* undo-> desfaz a jogada.
* redo-> refaz a jogada desfeita.
*/

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

