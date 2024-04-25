#include "Joker.h"
#include<iostream>
#include <string>

using namespace std;

string Joker:: get_role()
{
  return "Joker";
}
Joker :: Joker (string username)
: Player(username){}
bool Joker :: is_Mafia()
{return 0;}

bool Joker :: is_Villager()
{
  return 0;
}
