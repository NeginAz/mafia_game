#include "Detective.h"
#include<iostream>

using namespace std;

string Detective :: get_role()
{
  return "Detective";
}
Detective :: Detective(string username)
: Villager(username){}
