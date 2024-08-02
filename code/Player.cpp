#include"Player.h"

//string Player :: get_role(){};
int Player :: get_silence()
{return silence;}
void Player :: set_silence()
{
  if(silence==0)
    silence=1;
  else
    silence=0;
}
void Player :: add_vote()
  {vote ++ ;}
int Player :: get_vote()
{
  return vote;
}
void Player :: set_vote_to_zero()
{
  vote=0;
}
Player :: Player(string username)
{name=username;}
string Player :: get_name(){
  return name;
}
void Player :: set_live()
{live=0;
}
 void Player :: set_nodeath()
 {
   if(nodeath==1)
     nodeath=0;
  else
    nodeath=1;
 }
int Player :: get_nodeath()
{
  return nodeath;
}
int Player :: get_live()
{return live;}


void Player :: set_extra_live()
{extra_live=1;}
void Player :: zero_extra_live()
{extra_live=0;}

int Player :: get_extra_live()
{
  return extra_live;
}


int Player :: get_kill()
{return kill;}

void Player :: set_kill()
{
  kill=1;
}

void Player :: zero_kill()
{
  kill=0;
}
