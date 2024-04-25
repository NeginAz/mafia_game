#ifndef GODFATHER_H
#define GODFATHER_H
class GodFather;
//class Player;
//class Mafia;

#include"Mafia.h"


class GodFather : public Mafia
{
public:
   string get_role();
   GodFather(string username);
};
#endif
