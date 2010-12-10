#include <iostream>
#include <string>
#include "jogo.cpp"
#include "menu.cpp"

using namespace std;

int main()
{
  //Inicia o jogo e o menu
  Jogo * jogo = new Jogo();
  Menu menu = Menu(jogo);

  string entrada;

  //Enquanto o jogo não estiver resolvido vai apresentar o tabuleiro, o menu e pede a entrada.
  while(!jogo->is_solved()) {
    menu.mostrar();
    jogo->get_tabuleiro()->imprime_tabuleiro();

    getline(cin, entrada);

    menu.trata_entrada(entrada);
  }

  menu.mostrar_msg_de_vencedor();

  return 0;
}

