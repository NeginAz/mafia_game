#ifndef DOCTOR_H
#define DOCTOR_H
//class Player;
//class Villager;
#include"Villager.h"



class Doctor : public Villager
{
public:
string get_role();
Doctor (string username);
};
#endif
