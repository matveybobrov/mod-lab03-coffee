#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <iostream>

#include <string>

#include <vector>

enum class STATES {
  OFF,
  WAIT,
  ACCEPT,
  CHECK,
  COOK
};

class Automata {
  private: int cash;
  std::vector < std::string > menu;
  std::vector < int > prices;
  STATES state;
  int chosen;

  public: Automata();
  void on();
  void off();
  void coin(int);
  void getMenu();
  std::string getState();
  void choice(std::string);
  void check();
  void cancel();
  void cook();
  void finish();
};

#endif