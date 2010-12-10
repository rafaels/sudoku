#include "celula.h"

Celula::Celula()
{
  value = 0;
  is_constant_flag = false;
}

Celula::Celula(int new_value)
{
  value = new_value;
  is_constant_flag = true;
}

int Celula::get_value()
{
  return value;
}

/*
* Verifica se a célula é uma constante e se o valor está entre 0-9 para
* setar o novo valor.
*/
void Celula::set_value(int new_value)
{
  if (is_constant()) {
    throw("Esta célula é uma constante!");
  }
  
  if (new_value >= 0 || new_value <= 9) {
    value = new_value;
  } else {
    throw("O novo valor deve estar entre 0-9");
  }
}

bool Celula::is_constant()
{
  return is_constant_flag;
}

