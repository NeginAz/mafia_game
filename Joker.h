#ifndef JOKER_H
#define JOKER_H

#include<iostream>
#include<string>
#include "Player.h"

using namespace std;

class Joker:public Player
{
public:
 virtual string get_role();
 Joker (string username);
 bool is_Mafia();
 bool is_Villager();
};
#endif
