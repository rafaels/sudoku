#include <iostream>
#include <string>
#include "jogo.cpp"
#include "menu.cpp"

using namespace std;

int main()
{
  Jogo * jogo = new Jogo();
  Menu menu = Menu(jogo);

  string entrada;

  while(!jogo->is_solved()) {
    menu.mostrar();
    jogo->get_tabuleiro()->imprime_tabuleiro();

    getline(cin, entrada);

    menu.trata_entrada(entrada);
  }

  menu.mostrar_msg_de_vencedor();

  return 0;
}

