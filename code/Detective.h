#ifndef DETECTIVE_H
#define DETECTIVE_H
//class Player;
//class Villager;

#include"Villager.h"


class Detective : public Villager
{
public:
string get_role();
Detective(string username);
};
#endif
