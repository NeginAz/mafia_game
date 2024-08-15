#include "Doctor.h"
#include<iostream>

using namespace std;

string Doctor :: get_role()
{
  return "Doctor";
}
Doctor :: Doctor (string username)
: Villager(username){}
