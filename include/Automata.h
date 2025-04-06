// Copyright 2025 9hkge

#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <iostream>
#include <string>
#include <vector>

enum STATES {
  OFF,
  WAIT,
  ACCEPT,
  CHECK,
  COOK
};

class Automata {
 public:
  Automata();
  void on();
  void off();
  void coin(int csh);
  std::vector<std::string> getMenu();
  void cancel();
  STATES getState();
  void choice(std::string drink);
  void cook();
  void finish();

 private:
  int cash;
  std::vector<std::string> menu;
  std::vector<int> prices;
  STATES state;
};

#endif  // INCLUDE_AUTOMATA_H_
