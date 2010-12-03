#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include "tabuleiro.h"

using namespace std;

//retorna um número entre 0 e o parâmetro max - 1
int random(int max)
{
  srand((unsigned)time(NULL));
 
  return int((double(rand())/RAND_MAX)*max);
}

//retorna o inteiro de um char
int chr_to_int(char chr)
{
  return (int)chr - 48;
}

Tabuleiro::Tabuleiro()
{
  //lê do arquivo a configuração inicial do jogo
  char line[83];
  FILE* file = fopen("jogos", "r");

  //o arquivo de jogos tem 150 configurações iniciais disponíveis
  int line_number = random(150);

  //lê linhas até ler a linha sorteada
  for (int i = 0; i <= line_number; i++) {
    fgets(line, sizeof(line), file);
  }

  //cria as 9 linhas, colunas e quadrados
  for (int i = 0; i < 9; i++) {
    colunas[i] = new Grupo();
    linhas[i] = new Grupo();
    quadrados[i] = new Grupo();
  }

  //cria as 81 celulas
  int valor_nova_celula;
  Celula * nova_celula;
  for (int i = 0; i < 81; i++) {
    valor_nova_celula = chr_to_int(line[i]);

    //se a célula não for vazia, cria ela como fixa
    if (valor_nova_celula) {
      nova_celula = new Celula(valor_nova_celula);
    } else { //senão, cria como mutável
      nova_celula = new Celula();
    }

    celulas[i] = nova_celula;

    //associa cada célula criada a sua linha, coluna, e quadrado, colocando no lugar certo em cada grupo
    int linha  = i / 9;
    int coluna = i % 9;
    int quadrado = (i / 27) * 3 + (coluna / 3);
    linhas[linha]->set_celula(celulas[i], coluna);
    colunas[coluna]->set_celula(celulas[i], linha);
    quadrados[quadrado]->set_celula(celulas[i], (linha % 3) * 3 + (coluna % 3));
  }
}

bool Tabuleiro::is_solved()
{
  bool solved = true;

  //o tabuleiro está resolvido quando todos os quadrados, colunas e linhas estiverem também
  int i = 0;
  while(solved && i < 9) {
    solved = solved && linhas[i]->is_solved() &&
             colunas[i]->is_solved() &&
             quadrados[i]->is_solved();

    i++;
  }

  return solved;
}

//imprime com base nos quadrados
void Tabuleiro::imprime_tabuleiro()
{
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
          cout << quadrados[i*3 + k]->get_celula(j*3 + l)->get_value();
        }
        cout << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
}

//criando um tabuleiro novo e imprimindo ele, apenas para ver funcionar
int main (int argc, char const* argv[])
{
  Tabuleiro * tabuleiro = new Tabuleiro();
  tabuleiro->imprime_tabuleiro();

  return 0;
}

