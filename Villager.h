#ifndef VILLAGER_H
#define VILLAGER_H

#include"Player.h"
#include <string>

class Villager : public Player
{
public:
  virtual string get_role();
  Villager(string username);
  bool is_Mafia();
  bool is_Villager();
};
#endif
