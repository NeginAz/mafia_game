#ifndef MAFIA_H
#define MAFIA_H

//class Player;
#include <iostream>
#include"Player.h"

#include"string"
#include"iostream"
using namespace std;

class Mafia : public Player
{

public:
  virtual string get_role();
  Mafia(string username);
  bool is_Mafia();
  bool is_Villager();
};
#endif
