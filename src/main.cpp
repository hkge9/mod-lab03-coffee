// Copyright 2025 9hkge

#include "Automata.h"

#include <iostream>  
#include <vector>    
#include <string>   

int main() {
  std::vector<std::string> st{"OFF", "WAIT", "ACCEPT", "CHECK", "COOK"};
  Automata coffee;

  coffee.on();
  std::cout << st[coffee.getState()] << std::endl;

  std::vector<std::string> testMenu = coffee.getMenu();
  for (const std::string& val : testMenu) {
    std::cout << val << " ";
  }
  std::cout << std::endl;

  coffee.coin(200);
  std::cout << st[coffee.getState()] << std::endl;

  coffee.choice("Espresso");
  std::cout << st[coffee.getState()] << std::endl;

  coffee.cook();
  std::cout << st[coffee.getState()] << std::endl;

  coffee.off();
  std::cout << st[coffee.getState()] << std::endl;

  return 0;
}
