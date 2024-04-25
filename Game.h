#ifndef GAME_H
#define GAME_H

#include<iostream>
#include<vector>
#include<string>
#include"Room.h"
#include"MyException.h"

using namespace std;

class Game
{
private:
vector <Room*> rooms;
Room* curr;
public:
void  add_role(string role_name_,string role_num);
void create_room(vector <string> commands);
bool check_num_villager();
bool check_num_mafia();
void switch_room(vector <string> commands);
void join(vector <string> commands);
void show_Day();
void vote(vector <string> commands);
void  end_vote();
void detect();
void silent();
void detect(vector <string> commands);
void heal(vector <string> commands);
void  silent(vector <string> commands);
int check_room(string room_name);
int change_to_number(string role_num);
void check_create_room(vector <string> commands);
void get_room_state(vector <string> commands);
void check_delete();
 ~ Game();
};
#endif
