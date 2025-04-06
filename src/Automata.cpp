// Copyright 2025 9hkge

#include "Automata.h"

#include <vector>   
#include <string>   

Automata::Automata() {
  cash = 0;
  menu = {"Espresso", "Cappuccino", "Latte", "Americano", "Raf"};
  prices = {130, 150, 170, 120, 200};
  state = OFF;
}

void Automata::on() {
  if (state == OFF) {
    state = WAIT;
  }
}

void Automata::off() {
  if (state == WAIT) {
    state = OFF;
  }
}

void Automata::coin(int csh) {
  if (state == WAIT || state == ACCEPT) {
    if (csh > 0) {
      cash += csh;
      state = ACCEPT;
    } else {
      cancel();
    }
  }
}

std::vector<std::string> Automata::getMenu() {
  std::vector<std::string> menuAndPrices;
  for (int i = 0; i < menu.size(); i++) {
    menuAndPrices.push_back(menu[i] + " " + std::to_string(prices[i]));
  }
  return menuAndPrices;
}

void Automata::cancel() {
  state = WAIT;
}

STATES Automata::getState() {
  return state;
}

void Automata::choice(std::string drink) {
  bool status = false;
  if (state == ACCEPT || state == CHECK) {
    state = CHECK;
  }

  for (int i = 0; i < menu.size(); i++) {
    if (menu[i] == drink && cash >= prices[i]) {
      cash -= prices[i];
      status = true;
    }
  }

  if (!status) {
    cancel();
  }
}

void Automata::cook() {
  if (state == CHECK) {
    state = COOK;
  }
  finish();
}

void Automata::finish() {
  if (state == COOK) {
    state = WAIT;
  }
}
