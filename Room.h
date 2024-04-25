#ifndef ROOM_H
#define ROOM_H
#include<iostream>
#include<string>
#include <algorithm>
#include <functional>
#include<vector>
#include <cstdlib>
#include"Player.h"
#include"Joker.h"
#include"Mafia.h"
#include"GodFather.h"
#include"Silencer.h"
#include"Detective.h"
#include"Doctor.h"
#include"RouinTan.h"
#include"Villager.h"
#include"MyException.h"

using namespace std;

class Room
{
private:
  string room_name;
  int Day_Night=0; // Day=0 , Night=1
  int Day_Num=0;
  int state_night; //3 commands in sequence
  vector <string> role_name;
  vector <int> role_number;
  vector <string> user_name;
  vector <int> player_ind;
  vector<Player*> player;
  vector <string> voters;
  vector<string> votee;
  vector<string> detect;
  vector<string>silencer;
  vector<string>doctor;
  int delete_room=0;
public:
  string get_room_name();
  Room(string room_name_);
  void set_role_number(int index,int num);
  int get_role_number(int index);
  string get_role_name(int index);
  int add_user_name(string username_);
  int all_roles();
  void alloc_role(int ind,string username);
  void set_role();
  void role_to_person();
  int rand_role(string username_);
  int get_Day();
  void  inc_Day();
  int get_Day_Night();
  void set_Day_Night();
  void check_voter(string voter);
  void check_votee(string votee,string voter);
  void count_votes();
  void make_silent(string player_);
  bool is_silencer(string silencer_name);
  void save_player(string player_);
  void check_suspect(string suspect);
  bool check_detective(string detective_);
  void dead_Day(int index);
  void Night_vote(string voter,int index);
  void kill_Night(int index);
  bool check_doctor(string doctor_);
  int Num_Mafia();
  void print_role();
  void add_votes_to_player();
  int find_voter(string voter);
  int find_player(string name);
  void set_vote_zero();
  void change_voter_vote(string voter);
  int repeated_detective(string detective_);
  int repeated_doctor(string doctor_);
  int repeated_silencer(string silencer_name);
  void show_silenced();
  void Night();
  void kill_player();
  int Num_Villager();
  void end_of_game();
  void set_state_night(int state);
  int get_state_night();
  void check_state_night();
  int num_silencer();
  int num_doctor();
  int num_detective();
  void change_Day();
   ~Room();
  int get_delete(){return delete_room;}
};
#endif
