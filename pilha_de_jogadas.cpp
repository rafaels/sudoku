#include <iostream>
using namespace std;

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

Jogada PilhaDeJogadas::peek()
{
  if (qtd > 0) {
    return jogadas[qtd - 1];
  } else {
    throw "empty stack";
  }
}

Jogada PilhaDeJogadas::pop()
{
  Jogada poping = peek();
  qtd--;
  return poping;
}

//copy an array of jogadas into another array with same or greater size
void copy_array(Jogada * source, Jogada * dest, int source_size){
  for (int i = 0; i < source_size; i++){
    dest[i] = source[i];
  }
}

void PilhaDeJogadas::resize_jogadas()
{
  Jogada * nova_pilha = new Jogada[qtd*2];
  copy_array(jogadas, nova_pilha, qtd);
  jogadas = nova_pilha;
}

void PilhaDeJogadas::push(Jogada jogada)
{
  jogadas[qtd] = jogada;
  qtd++;

  //resize jogadas array if it's full
  if (qtd % 20 == 0 && qtd != 0) {
    resize_jogadas();
  }
}

void PilhaDeJogadas::empty()
{
  qtd = 0;
}
