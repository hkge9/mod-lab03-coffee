#include "Automata.h"

int main(){

  vector <string> st {"OFF", "WAIT", "ACCEPT", "CHECK", "COOK"};
  Automata coffee;
  coffee.on();
  cout << st[coffee.getState()] << endl;
  vector <string> testMenu = coffee.getMenu();
  for (string val : testMenu) {
	  cout << val << " ";
  }
  coffee.coin(200);
  cout << st[coffee.getState()] << endl;
  coffee.choice("Espresso");
  cout << st[coffee.getState()] << endl;
  coffee.cook();
  cout << st[coffee.getState()] << endl;
  coffee.off();
  cout << st[coffee.getState()] << endl;
  return 0;

}