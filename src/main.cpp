// Copyright 2022 UNN-IASR

#include <iostream>

#include "Automata.h"

int main() {
  Automata m;
  m.getMenu();
  m.on();
  m.coin(10);
  m.coin(10);
  m.choice("Кофе");
  m.off();
  std::string currentState = m.getState();
  std::cout << "Текущее состояние автомата: " << currentState << std::endl;

  return 0;
}
