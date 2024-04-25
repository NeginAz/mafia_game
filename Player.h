#ifndef PLAYRER_H
#define PLAYRER_H

#include <string>
#include <iostream>
using namespace std;

class Player
{
protected:
  string name;
  int live=1;
  int extra_live=0; // Rouintan=1
  int nodeath=0; //Doctor
  int silence=0; // Silencer
  int vote=0; //number of votes in each Day
  int kill;
public:
  virtual string get_role()=0;
  Player(string username);
  int get_silence();
  void set_silence();
  void add_vote();
  int get_vote();
  string get_name();
  void set_live();
  int get_live();
  void set_extra_live();
  int get_extra_live();
  void zero_extra_live();
  virtual bool is_Mafia()=0;
  virtual bool is_Villager()=0;
  void set_nodeath();
  int get_nodeath();
  void set_vote_to_zero();
  void set_kill();
  int get_kill();
  void zero_kill();
};
#endif
