#include "Mafia.h"
#include<iostream>

using namespace std;

string Mafia :: get_role()
{
  return "Mafia";
}
Mafia :: Mafia(string username)
  : Player(username){}

bool Mafia :: is_Mafia()
{
  return 1;
}

bool Mafia:: is_Villager()
{
  return 0;
}
