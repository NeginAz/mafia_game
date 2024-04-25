
#include "Game.h"
#include"MyException.h"
#include<iostream>
#include <sstream>
using namespace std;

void find_command(string str ,Game & game)
{ vector <string> commands;

  string word;
  //string prev_command;
  istringstream iss(str);
  while(iss >> word)
{
  commands.push_back(word);
}
//game.check_sequence_command(prev_command);
if(commands[0] == "Create_room")
{
  game.create_room(commands);
}
else if(commands[0] == "Switch_room")
{
  game.switch_room(commands);
}
else if(commands[0] == "Join")
{
 game.join(commands);
}
else if(commands[0] =="vote")
{
game.vote(commands);
}
else if(commands[0] == "End_vote")
{game.end_vote();}
else if(commands[0] == "Detect")
{
game.detect(commands);
}
else if (commands[0] == "Heal")
{
game.heal(commands);
}
else if(commands[0] == "Silent")
{
game.silent(commands);
}
else if(commands[0] == "Get_room_state")
{
  game.get_room_state(commands);
}
else
{
  MyException e("Wrong Command");
  throw e;
}
//prev_command=commands[0];
commands.clear();
}
int main()
{
  string str,word;
  Game game;
  while(getline(cin,str) && str.size() > 0)
  {//
    try{
      find_command(str ,game);
  }
catch(MyException &e)
{
  cout<<e.what()<<endl;
}
game.check_delete();
}
  return 0;
}
