#include "jogo.h"

Jogo::Jogo()
{
  tabuleiro = new Tabuleiro();
  solved = false;
  anteriores = PilhaDeJogadas();
  proximas = PilhaDeJogadas();
}

//Cria a jogada

Jogada nova_jogada(int antes, int depois, Celula * celula){
  Jogada nova;
  nova.antes = antes;
  nova.depois = depois;
  nova.celula = celula;

  return nova;
}

/*
* Armazena a jogada na pilha de anteriores e esvazia a pilha de jogadas próximas.
* Seta o valor da célula e verifica se o tabuleiro foi resolvido.
*/

void Jogo::jogar(int linha, int coluna, int valor)
{
  Celula * celula = tabuleiro->get_celula(linha, coluna);
  int antes = celula->get_value();

  celula->set_value(valor);

  Jogada jogada = nova_jogada(antes, valor, celula);

  anteriores.push(jogada);
  proximas.empty();

  solved = tabuleiro->is_solved();
}

bool Jogo::is_solved()
{
  return solved;
}

/*
* Pega o valor da célula armazenada na pilha de jogadas anteriores e armazena a
* célula atual na pilha de jogadas próximas.
*/

void Jogo::undo()
{
  Jogada undoing = anteriores.pop();

  undoing.celula->set_value(undoing.antes);

  proximas.push(undoing);
}

/*
* Pega o valor da célula armazenada na pilha de jogadas próximas e armazena a
* célula atual na pilha de jogadas anteriores.
*/

void Jogo::redo(){
  Jogada redoing = proximas.pop();

  redoing.celula->set_value(redoing.depois);

  anteriores.push(redoing);
}

Tabuleiro * Jogo::get_tabuleiro()
{
  return tabuleiro;
}
