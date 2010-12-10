#include <iostream>
using namespace std;

//Estrutura de jogada, possui um valor anterior (antes), um valor posterior (depois)
//e a célula modificada
struct Jogada {
  int antes;
  int depois;
  Celula * celula;
};

#include "pilha_de_jogadas.h"

PilhaDeJogadas::PilhaDeJogadas()
{
  jogadas = new Jogada[20];
  qtd = 0;
}

//Retorna o topo da pilha, verificando se está vazia
Jogada PilhaDeJogadas::peek()
{
  if (qtd > 0) {
    return jogadas[qtd - 1];
  } else {
    throw "Pilha vazia!";
  }
}

//Retorna a ultima jogada, ou seja, a jogada do topo da pilha
Jogada PilhaDeJogadas::pop()
{
  Jogada poping = peek();
  qtd--;
  return poping;
}

//Copia o vetor de jogadas para outro vetor com outro tamanho (source_size)
void copy_array(Jogada * source, Jogada * dest, int source_size){
  for (int i = 0; i < source_size; i++){
    dest[i] = source[i];
  }
}

//Cria uma nova pilha com as jogadas da pilha anterior + a nova jogada
void PilhaDeJogadas::resize_jogadas()
{
  Jogada * nova_pilha = new Jogada[qtd*2];
  copy_array(jogadas, nova_pilha, qtd);
  jogadas = nova_pilha;
}

//Armazena a jogada na pilha
void PilhaDeJogadas::push(Jogada jogada)
{
  jogadas[qtd] = jogada;
  qtd++;

  //resize jogadas quando o vetor estiver cheio
  if (qtd % 20 == 0 && qtd != 0) {
    resize_jogadas();
  }
}

void PilhaDeJogadas::empty()
{
  qtd = 0;
}
