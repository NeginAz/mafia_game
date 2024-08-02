#ifndef SILENCER_H
#define SILENCER_H
//class Mafia;
//class Player;

#include"Mafia.h"

class Silencer : public Mafia
{
public:
  string get_role();
  Silencer(string username);
};
#endif
