// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

TEST(MAIN, 1)
{
  Automata m;
  EXPECT_EQ("OFF", m.getState());
}

TEST(MAIN, 2)
{
  Automata m;
  EXPECT_EQ("OFF", m.getState());
}

TEST(MAIN, 3)
{
  Automata m;
  m.on();
  EXPECT_EQ("ON", m.getState());
}

TEST(MAIN, 4)
{
  Automata m;
  m.on();
  m.off();
  EXPECT_EQ("OFF", m.getState());
}

TEST(MAIN, 5)
{
  Automata m;
  m.on();
  m.coin(10);
  EXPECT_EQ("ACCEPT", m.getState());
}

TEST(MAIN, 6)
{
  Automata m;
  m.on();
  m.coin(10);
  m.coin(10);
  EXPECT_EQ("ACCEPT", m.getState());
}

TEST(MAIN, 7)
{
  Automata m;
  m.on();
  m.coin(10);
  m.coin(10);
  m.choice("Кофе");
  // Готово
  EXPECT_EQ("WAIT", m.getState());
}

TEST(MAIN, 8)
{
  Automata m;
  m.on();
  m.coin(10);
  m.choice("Кофе");
  // Недостаточно средств
  EXPECT_EQ("CHECK", m.getState());
}

TEST(MAIN, 9)
{
  Automata m;
  m.on();
  m.coin(10);
  m.choice("Кофе");
  m.cancel();
  EXPECT_EQ("WAIT", m.getState());
}

TEST(MAIN, 10)
{
  Automata m;
  m.on();
  m.coin(10);
  m.choice("Йогурт");
  // Выбранного напитка нет в меню
  EXPECT_EQ("CHOICE", m.getState());
}
