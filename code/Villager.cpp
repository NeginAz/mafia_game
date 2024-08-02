#include "Villager.h"
#include<iostream>

using namespace std;

string Villager ::  get_role()
{
  return "Villager";
}
Villager :: Villager (string username)
: Player(username){}


bool Villager:: is_Mafia()
{return 0;}

bool Villager :: is_Villager()
{
  return 1;
}
