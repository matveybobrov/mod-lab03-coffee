// Copyright 2022 UNN-IASR

#include "Automata.h"

#include <iostream>

#include <string>

#include <vector>

#include <algorithm>

Automata::Automata() {
  cash = 0;
  menu = {
    "Чай",
    "Кофе",
    "Какао"
  };
  prices = {
    10,
    15,
    20
  };
  state = STATES::OFF;
  chosen = -1;
}
void Automata::on() {
  if (state == STATES::OFF) {
    std::cout << "Включение\n";
    state = STATES::WAIT;
  }
}

void Automata::off() {
  if (state == STATES::WAIT) {
    std::cout << "Выключение\n";
    state = STATES::OFF;
  }
}

void Automata::coin(int amount) {
  if (state == STATES::WAIT || state == STATES::ACCEPT) {
    std::cout << "Пополнение...\n";
    cash += amount;
    std::cout << "Текущий баланс: " << cash << std::endl;
    state = STATES::ACCEPT;
  }
}

void Automata::getMenu() {
  std::cout << "Меню напитков:\n";
  for (size_t i = 0; i < menu.size(); ++i) {
    std::cout << i + 1 << ". " << menu[i] << " - " << prices[i] << " руб.\n";
  }
}

std::string Automata::getState() {
  switch (state) {
  case STATES::OFF:
    return "OFF";
  case STATES::WAIT:
    return "WAIT";
  case STATES::ACCEPT:
    return "ACCEPT";
  case STATES::CHECK:
    return "CHECK";
  case STATES::COOK:
    return "COOk";
  }
  return "UNKNOWN";
}

void Automata::choice(std::string choice) {
  if (state == STATES::ACCEPT) {
    std::cout << "Выбранный напиток: " << choice << std::endl;
    auto result {
      std::find(begin(menu), end(menu), choice)
    };
    chosen = result - begin(menu);
    if (result == end(menu)) {
      std::cout << "Выбранного напитка нет в меню" << std::endl;
    } else {
      std::cout << "Цена выбранного напитка: " << prices[chosen] << std::endl;
      state = STATES::CHECK;
      check();
    }
  }
}

void Automata::check() {
  if (state == STATES::CHECK) {
    if (cash < prices[chosen]) {
      std::cout << "Недостаточно средств для оплаты. Вы можете нажать"
      "кнопку отмены и вернуть деньги" << std::endl;
      return;
    }
    std::cout << "Оплата прошла успешно" << std::endl;
    cash -= prices[chosen];
    cook();
  }
}

void Automata::cancel() {
  if (state == STATES::ACCEPT || state == STATES::CHECK) {
    cash = 0;
    std::cout << "Операция отменена\n";
    state = STATES::WAIT;
  }
}

void Automata::cook() {
  if (state == STATES::CHECK) {
    std::cout << "Готовка..." << std::endl;
    state = STATES::COOK;
    std::cout << "Ваш напиток готов!" << std::endl;
    finish();
  }
}

void Automata::finish() {
  if (state == STATES::COOK) {
    state = STATES::WAIT;
  }
}
