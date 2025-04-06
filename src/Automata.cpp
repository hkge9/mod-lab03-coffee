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

void Automata::coin(int csh) {
    if (state == WAIT || state == ACCEPT) {
        if (csh > 0) {
            cash += csh;
            state = ACCEPT;
        }
        else {
            cancel();
        }
    }
  
}

vector <string> Automata::getMenu(){
  vector <string> menuAndPrices;
  for (int i=0; i<menu.size();i++){
    menuAndPrices.push_back(menu[i] + " " + to_string(prices[i]));
  }
 return menuAndPrices;
}

void Automata::cancel() {
    state = WAIT;
}