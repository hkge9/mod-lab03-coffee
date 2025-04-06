#include <iostream>
#include <string>
#include <vector>
using namespace std;


enum STATES {
  OFF,
  WAIT,
  ACCEPT,
  CHECK,
  COOK
};

class Automata{
  private:
  int cash;
  vector <string> menu;
  vector <int> prices;
  STATES state;


  public:
  Automata();
  void on();
  void off();
  void coin (int csh);
  vector <string> getMenu();
  void cancel();
  STATES getState();
  void choice(string drink);
  void cook();
  void finish();
};