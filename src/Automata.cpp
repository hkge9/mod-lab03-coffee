#include "Automata.h"

Automata::Automata(){
  cash = 0;
  menu = {"Espresso", "Cappuccino", "Latte", "Americano", "Raf"};
  prices = {130, 150, 170, 120, 200};
  state = OFF;
}

void Automata::on(){
  if (state == OFF){
    state = WAIT;
  }
}

void Automata::off(){
  if (state == WAIT){
    state = OFF;
  }
}

int Automata::coin(int csh){
  if (state == WAIT){
    state = ACCEPT;
  }
  if (state == ACCEPT){
    cash = csh;
  }
  return cash;
}