#include <iostream>
#include <sstream>
#include "menu.h"

using namespace std;

Menu::Menu(Jogo * novo_jogo)
{
  jogo = novo_jogo;
}

void Menu::mostrar()
{
  cout << "########################################################################################################################################" << endl;
  cout << "Faça sua jogada digitando respectivamente, a linha, a coluna e o número que quer colocar. Ex.: 1 2 9 -> linha 1, coluna 2, numero 9" << endl;
  cout << "########################################################################################################################################" << endl << endl;
}

void Menu::trata_entrada(string entrada)
{
  istringstream ins;

  try {
    if (entrada != "z" && entrada != "r") { //se não for pra desfazer ou refazer, é uma jogada
      int linha, coluna, numero;
      ins.str(entrada);

      ins >> linha >> coluna >> numero;
      linha--;
      coluna--;

        if (validate_entrada(linha, coluna, numero)) {
          jogo->jogar(linha, coluna, numero);
        } else {
          cout << endl << "Faça uma jogada válida" << endl << endl;
        }
    } else {
      if (entrada == "z") {
        jogo->undo();
      } else {
        jogo->redo();
      }
    }
  } catch (char const * msg) {
    cout << endl << msg << endl << endl;
  }
}

bool Menu::validate_entrada(int linha, int coluna, int numero)
{
  bool valid = true;

  if (linha < 0 || linha > 8 || coluna < 0 || coluna > 8 || numero < 0 || numero > 9) {
    valid = false;
  }

  return valid;
}

void Menu::mostrar_msg_de_vencedor()
{
  cout << "##########################################" << endl;
  cout << "VOCÊ VENCEU!!! :D" << endl;
  cout << "VOCÊ VENCEU!!! :D" << endl;
  cout << "VOCÊ VENCEU!!! :D" << endl;
  cout << "VOCÊ VENCEU!!! :D" << endl;
  cout << "##########################################" << endl;
}
