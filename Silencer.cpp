#include "Silencer.h"
#include<iostream>

using namespace std;

string Silencer :: get_role()
{
  return "Silencer";
}
Silencer :: Silencer(string username)
: Mafia(username){}
