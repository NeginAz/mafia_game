#include "GodFather.h"
#include<iostream>

using namespace std;

string GodFather :: get_role()
{
  return "GodFather";
}
GodFather :: GodFather(string username)
: Mafia(username){}
