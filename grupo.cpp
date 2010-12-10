#include <iostream>
using namespace std;

#include "grupo.h"

Grupo::Grupo()
{
}

void Grupo::set_celula(Celula * celula, int posicao)
{
  celulas[posicao] = celula;
}

Celula * Grupo::get_celula(int posicao)
{
  return celulas[posicao];
}

/*
* Preenche um vetor bool de nove posições com false 'valores_existentes',
* faz um laço para varrer o grupo de células, se a célula tiver um valor
* significativo (de 1 a 9) vou setar, no indice da célula no vetor
* 'valores_existentes', como true. Se durante o laço a posição no vetor já
* estiver setada como true, quer dizer que aquele valor já foi preenchido,
* ou seja, existe célula no grupo com valores iguais.
*/

bool Grupo::has_any_repeat()
{
  bool any_repeat = false;

  //array com as 9 posições setadas para false
  bool valores_existentes[9] = {false,false,false,false,false,false,false,false,false};

  int valor_da_celula_atual;

  for (int i = 0; i < 9; i++) {
    //valor da celula atual, subtraido UM para usar como indice no vetor 'valores_existentes'
    valor_da_celula_atual = celulas[i]->get_value() - 1;

    //se a posição já tiver sido setada, é porque há um valor repetido
    if (valores_existentes[valor_da_celula_atual]) {
      any_repeat = true;
      break;
    }

    //se a celula tiver um valor significativo (1..9), setar no array 'valores_existentes' que ele existe
    if (valor_da_celula_atual >= 0) {
      valores_existentes[valor_da_celula_atual] = true;
    }
  }

  return any_repeat;
}

/*
* Para determinar se o jogo está resolvido, é preciso verificar se há células
* repetidas no grupo, ou se há zeros.
* Varre o grupo para verificar se há alguma célula com valor igual à zero.
* Chama a função has_any_repeat.
*/

bool Grupo::is_solved()
{
  bool has_any_zero = false;

  //verifica se o grupo tem algum 0
  for(int i = 0; i < 9; i++) {
    if (celulas[i]->get_value() == 0) {
      has_any_zero = true;
      break;
    }
  }

  return (not has_any_zero) && (not has_any_repeat());
}

