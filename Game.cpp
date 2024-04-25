#include "Game.h"
#include<iostream>
#include <cstdlib>
 const int  role  =8;

using namespace std;

bool Game :: check_num_mafia()
{
  if(curr->get_role_number(5) >= (curr->get_role_number(6)+curr->get_role_number(7)))
    return 1;
  else
    return 0;
}

bool Game ::  check_num_villager()
{
  if(curr->get_role_number(1)  >=  (curr->get_role_number(2)+curr->get_role_number(3)+curr->get_role_number(4)))
    return 1;
  else
    return 0;
}

int Game ::  change_to_number(string role_num)
{
  int num=stoi(role_num.c_str());
  if(num < 0)
  {
    MyException e("wrong number");
    throw e;
  }
  return num;
}

 void Game ::add_role(string role_name_,string role_num)
{
  for(int i=0;i < role ; i++)
    {
    if( role_name_ == curr->get_role_name(i))
      {
      int num=change_to_number(role_num);
        curr-> set_role_number(i,num);
        return ;
    }
  }
  MyException e("Wrong Role");
  throw e;
}


int Game:: check_room(string room_name)
{
  for(int i=0;i< rooms.size(); i++)
  {
    if(room_name == rooms[i]->get_room_name())
      return i;
  }
return -1;
}

void Game:: check_create_room(vector <string> commands)
{
  if(commands.size() < 3)
  {MyException e("Wrong Command");
  throw e;}
  int repeated=check_room(commands[1]);
  if(repeated!=-1)
  {MyException e("Repeated Room Name");
  throw e;}
}

 void Game :: create_room(vector <string> commands)
 { check_create_room(commands);
   int repeated=check_room(commands[1]);
   //cout<<repeated<<endl;
   if(repeated == -1)
   {
   Room* room=new Room(commands[1]);
   curr=room;
   rooms.push_back(room);
   for(int i=2;i< commands.size();i=i+2)
   {
     commands[i]=(commands[i]).substr(1,(commands[i].size()));
     add_role(commands[i],commands[i+1]);
   }
 }

 if(check_num_mafia()==0 ||  check_num_villager()==0)
    {
      MyException e("Wrong number of Mafia or Villager");
    throw e;}
 }


 void Game :: switch_room(vector <string> commands)
 {
      int ind=check_room(commands[1]);
      if(ind == 0)
      {MyException e("Invalid room name");
      throw e;}
      else
        curr=rooms[ind];
 }


 void Game :: show_Day()
 {cout<<"Day"<<curr->get_Day()<<endl;}


 void Game :: join(vector <string> commands)
 {
   int full;
   for(int i=1; i < commands.size();++i)
   {
     full= curr->add_user_name(commands[i]);
   }
   if(full == 1 )
     {
      curr->role_to_person();

      curr->inc_Day();
      show_Day();
    }
 }

void Game :: vote(vector <string> commands)
{
  curr->check_voter(commands[1]);
  //cout<<voter_index<<endl;
  curr->check_votee(commands[2],commands[1]);
}


void Game :: end_vote()
{
  if(curr->get_Day_Night() == 0)
  {curr->count_votes();
  curr->end_of_game();}
}



void Game :: detect(vector <string> commands)
{

  //if(curr->get_state_night()==1)
    //{
      bool is_detective=curr->check_detective(commands[1]);
    if(is_detective == 1)
      curr->check_suspect(commands[2]);
      curr->set_state_night(2);
    //}
      curr->check_state_night();
      curr->change_Day();
}



void Game :: heal(vector <string> commands)
{
  //if(curr->get_state_night() == 2)
    bool doctor=curr->check_doctor(commands[1]);
    //cout<<"doctor"<<doctor<<endl;
    if(doctor)
    {
      curr->save_player(commands[2]);
    }
    curr->set_state_night(3);
//}
    curr->check_state_night();
    //cout<<"state"<<curr->get_state_night()<<endl;
    curr->change_Day();

}


void Game :: silent(vector <string> commands)
{
  curr->check_state_night();
  //if(curr->get_state_night()==3)
//{
   bool silencer=curr-> is_silencer(commands[1]);
  if(silencer)
    curr->make_silent(commands[2]);
    curr->set_state_night(4);
  //}

    curr->check_state_night();
    curr->change_Day();
}


void Game:: get_room_state(vector<string> commands)
{
  cout<<"Mafia = "<<curr->Num_Mafia()<<endl;
  cout<<"Villager = "<<curr->Num_Villager()<<endl;
}

void Game ::check_delete()
{
  if(curr->get_delete()==1)
      for(int i=0;i< rooms.size();i++)
      {
        if(rooms[i]->get_room_name()== curr->get_room_name())
        {
          curr=NULL;
          rooms.erase(rooms.begin()+i);
        }
      }
}


 Game :: ~ Game()
{
  for(int i=0;i< rooms.size();i++)
    delete  rooms[i];
}
