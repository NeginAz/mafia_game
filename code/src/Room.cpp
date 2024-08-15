#include "Room.h"
#include<iostream>
#include <algorithm>
#include <functional>

const int JOKER=0;
const int VILLAGER=1;
const int DETECTIVE=2;
const int DOCTOR=3;
const int ROUINTAN=4;
const int MAFIA=5;
const int GODFATHER=6;
const int SILENCER=7;


using namespace std;

void Room :: set_state_night(int state)
{
  state_night=state;
}

int Room :: get_state_night()
{return state_night;}


string Room ::  get_room_name()
{
  return room_name;
}


Room ::Room (string room_name_)
{
  room_name=room_name_;
  role_name.push_back("Joker");role_name.push_back("Villager");role_name.push_back("Detective");role_name.push_back("Doctor");role_name.push_back("RouinTan");
  role_name.push_back("Mafia");role_name.push_back("GodFather");role_name.push_back("Silencer");
  for(int i=0;i<8;i++)
    role_number.push_back(0);
}



void Room :: set_role_number(int index,int num)
{
  role_number[index]=num;
}

int Room :: get_role_number(int index)
{
  return role_number[index];
}



string Room :: get_role_name(int index)
{
  return role_name[index];
}

int Room :: all_roles()
{
  int sum=0;
  for(int i=0;i<8;++i)
  {
    sum=sum + role_number[i];
  }
  return sum;
}



int Room :: add_user_name(string username_)
{
  if(user_name.size() == all_roles())
  {
    MyException e("many users");
    throw e;
  }
  if(user_name.size() < all_roles())
  {  user_name.push_back(username_);
    //cout<<"size"<<user_name.size()<<endl;
  }
  if(user_name.size() == all_roles())
    return 1;
  else if(user_name.size() < all_roles())
    return 0;
}



int Room :: rand_role(string username_)
{
 int set=0;
 srand(1000000);
 while(set==0)
 {
   int ind=rand() % 8;
   if(role_number[ind] > 0)
    {
      role_number[ind] = role_number[ind] -1;
      set=1;
      return ind;
     }
 }
}


void Room :: alloc_role(int ind,string username)
{
  if(ind==JOKER)
  {Joker* joker=new Joker(username);
    player.push_back (joker);
  }
  else if(ind==VILLAGER)
  {Villager* villager=new  Villager(username);
    player.push_back (villager);}
  else if(ind==DETECTIVE)
  {Detective* detective=new  Detective(username);
    player.push_back (detective);}
  else if(ind==DOCTOR)
    {Doctor* doctor=new  Doctor(username);
      player.push_back (doctor);}
  else if(ind==ROUINTAN)
  {
    RouinTan* rouintan=new RouinTan(username);
    rouintan->set_extra_live();
    player.push_back(rouintan);
  }
  else if(ind==MAFIA)
  {Mafia* mafia=new  Mafia(username);
    player.push_back (mafia);}
  else if(ind==GODFATHER)
    {GodFather* godfather=new  GodFather(username);
      player.push_back (godfather);}
  else if(ind==SILENCER)
      {Silencer* silencer=new  Silencer(username);
        player.push_back (silencer);}
}


void Room :: set_role()
{
  for(int i=0; i < (user_name).size() ; i++ )
  {
    alloc_role(player_ind[i],user_name[i]);
  }
}


void Room :: print_role()
{
  for(int i=0;i<player.size();i++)
    cout<<player[i]->get_name()<<" is "<<player[i]->get_role()<<endl;
}



void Room :: role_to_person()
{
  for(int i=0 ;i < (user_name).size() ; i++)
  {
    int ind=rand_role(user_name[i]);
    player_ind.push_back(ind);
  }
  set_role();
  print_role();
}


int Room :: get_Day()
{return Day_Num;}



void Room :: inc_Day()
{Day_Num=Day_Num+1;}



int Room:: get_Day_Night()
{return Day_Night;}


void  Room:: set_Day_Night()
{
  if(Day_Night==0)
    Day_Night=1;
  else
    Day_Night=0;
}




int Room :: Num_Mafia()
{ int num_mafia=0;
  for(int i=0; i< player.size();i++)
  {
    if(player[i]->is_Mafia() == 1 && player[i]->get_live()>0)
      num_mafia++;
  }
  return num_mafia;
}



 int Room :: Num_Villager()
 {
   int num_villager=0;
     for(int i=0; i< player.size();i++)
     {
       if(player[i]->is_Villager() == 1 && player[i]->get_live()>0)
         num_villager++;
     }
     return num_villager;
 }




void Room ::end_of_game()
{
  if(Num_Mafia()== 0)
    {cout<<"victory"<<endl;
  delete_room=1;}
  if(Num_Mafia() >=  Num_Villager())
    {cout<<"Loose"<<endl;
    delete_room=1;
  }
}




void Room ::  kill_Night(int index)
{
  cout<<"Mafia try to kill "<< player[index]->get_name()<<endl;
  player[index]->set_kill();
}




void Room :: Night_vote(string voter,int index)
{
  if(voter == player[index]->get_name() && voters.size() <= Num_Mafia() && player[index]->is_Mafia()==1)
  {
     change_voter_vote(voter);
  }
  else if(player[index]->is_Mafia()==0)
  {
    cout<<"This user can not vote"<<endl;}
}


int Room :: find_player(string name)
{
  for(int i=0;i<player.size();i++)
    {
      if(player[i]->get_name() == name && player[i]->get_live()>0)
        return i;
    }
  return -1;
}


int Room :: find_voter(string voter)
{
  for(int i=0;i<voters.size();i++)
  {if(voter== voters[i])
      return i;}
      return -1;
}


void Room :: change_voter_vote(string voter)
{
  int index_voter=find_voter(voter);
  if(index_voter==-1)
    { voters.push_back(voter);
    }
  else
  {voters.erase(voters.begin()+index_voter);
    votee.erase(votee.begin()+index_voter);
    voters.push_back(voter);  }
}



void Room :: check_voter(string voter)
{
    int ind=find_player(voter);
    if(ind==-1)
    {
      MyException e ("User not Joined");
      throw e;
    }
    if(get_Day_Night() == 0) //Day
    {
      if(player[ind]->get_silence() ==1)
      {MyException e("This user has been silenced before");
        throw e;}
        if(player[ind]->get_silence()==0)
            change_voter_vote(voter);

}
    else if(get_Day_Night()==1) //Night
      Night_vote(voter,ind);
  }


void Room :: check_votee(string votee_,string voter_)
{
    int player_ind=find_player(votee_);
    if(player_ind==-1)
      {
        MyException e ("User not Joined");
        throw e;
      }
    else if(player[player_ind]->get_live() == 0)
     {
       MyException e("User already died");
     throw e;
     }
        int voter_ind=find_player(voter_);
        if(player[voter_ind]->get_silence()==0)
           votee.push_back(votee_);
        if(voters.size() == Num_Mafia() && get_Day_Night()==1) //Night
          {

            count_votes();
            set_state_night(1);
            check_state_night();
            change_Day();
            voters.clear();
            votee.clear();
            set_vote_zero();
          }
  }


void Room :: add_votes_to_player()
{ int index;
  //cout<<"mm"<<votee.size()<<endl;
  for(int i=0;i<votee.size();i++)
  {
    index=find_player(votee[i]);
    player[index]->add_vote();
    //cout<<player[index]->get_name()<<endl;
  }
}

void Room :: count_votes()
{
  add_votes_to_player();
  int max_vote=0;
  vector<int> max_ind;
  for(int i=0; i<player.size();i++)
  {
    if(player[i]->get_vote() > max_vote)
      { max_vote=player[i]->get_vote();
        max_ind.clear();
        max_ind.push_back(i);
    }
    else if(player[i]->get_vote() ==  max_vote)
    {max_ind.push_back(i);}
  }
  int ind=rand() % (max_ind.size());
  int index=max_ind[ind];
  if(get_Day_Night() == 0)
     { end_of_game();
       dead_Day(index);
       for(int i=0;i<player.size();i++)
       {if(player[i]->get_silence()==1)
       player[i]->set_silence();}
     }
  else
    kill_Night(index);
}


void Room :: set_vote_zero()
{
  for(int i=0;i<player.size();i++)
    player[i]->set_vote_to_zero();
}


void Room :: dead_Day(int index)
  {
    if(player[index]->get_role() == "Joker")
    {
      cout<<"Loose"<<endl;
    }
  player[index]->set_live();
  cout<<player[index]->get_name()<<" is dead"<<endl;
  set_Day_Night();
  cout<<"Night"<<get_Day()<<endl; //////////////vote =0
  voters.clear();
  votee.clear();
  set_vote_zero();
}



int Room:: repeated_detective(string detective_)
{
  for(int i=0;i<detect.size();i++)
     {if(detect[i]== detective_)
      {MyException e("Detective has already asked");
      throw e;}
      }
    return -1;
}
int Room :: repeated_doctor(string doctor_)
{
  for(int i=0;i<doctor.size();i++)
     {if(doctor[i]== doctor_)
      {MyException e("Doctor has already healed");
      throw e;}
      }
    return -1;
}



bool  Room :: check_detective(string detective_)
{

    int i=find_player(detective_);
    if(player[i]->get_role() == "Detective" && player[i]->get_live() == 1 && i!=-1)
    {
     if(repeated_detective(detective_)==-1)
        detect.push_back(detective_);
        return 1;
    }
     else
      {
        MyException e("User can not ask");
        throw e;
      }
      return 0;
}


void Room :: check_suspect(string suspect)
{
   int i=find_player(suspect);
 if(i !=-1)
    {
      if(player[i]->get_live() >0)
        {
          if(player[i]->is_Mafia() == 0)
            cout<<"No"<<endl;
          else if(player[i]->is_Mafia() == 1 && player[i]->get_role() == "GodFather")
            cout<<"No"<<endl;
          else
            cout<<"Yes"<<endl;}
      else if(player[i]->get_live()==0)
          {
            MyException e("Person is dead");
            throw e;
          }
        }
 else if(i ==-1)
    {
      MyException e("User not joined");
      throw e;
    }
}




bool Room :: check_doctor(string doctor_)
{
    int i=find_player(doctor_);
    if(i!=-1)
    {if(player[i]->get_role() == "Doctor" && player[i]->get_live() > 0)
   { //cout<<player[i]->get_live()<<endl;
    if(repeated_doctor(doctor_)==-1)
      doctor.push_back(doctor_);
      return 1;
  }
    else
      {MyException e("User can not heal");
      throw e;}
}
else if(i==-1)
  {MyException e("User can not heal");
  throw e;}
}


void Room :: save_player(string player_)
{
    int i=find_player(player_);
    if(i!=-1)
    {if(player[i]->get_live() >0)
    {
        player[i]->set_nodeath();
      }
    else
  {
      MyException e("Person is dead");
      throw e;
  }}
  else
  {
    MyException e("User not joined");
    throw e;
  }

}

int Room :: repeated_silencer(string silencer_name)
{
  for(int i=0; i<silencer.size();i++)
  {
    if(silencer_name == silencer[i])
      {MyException e("Silencer has already silenced");
    throw e;}
  }
return -1;
}


bool Room :: is_silencer(string silencer_name)
{
  int i=find_player(silencer_name);
  if(player[i]->get_role() == "Silencer" && player[i]->get_live() >0 && i !=-1)
    {
      if(repeated_silencer(silencer_name)==-1);
        {silencer.push_back(silencer_name);
        return 1;}
    }
  else
  {
    MyException e("User can not silence");
    throw e;
  }

}



void Room :: make_silent(string player_)
{
  int i=find_player(player_);
  if(player[i]->get_live() > 0)
  {
      player[i]->set_silence();
  }
  else
    {MyException e("Person is dead");
    throw e;
    }
}


void Room :: kill_player()
{
  for(int i=0;i<player.size();i++)
  {
    if(player[i]->get_kill()==1 && player[i]->get_live() ==1)
    {
      if(player[i]->get_nodeath()== 0 && player[i]->get_extra_live()==0)
      {  cout<<"killed "<<player[i]->get_name()<<endl;
      player[i]->set_live();

    }
      else if(player[i]->get_nodeath()== 1)
        player[i]->set_nodeath();
      else if(player[i]->get_extra_live()==1)
          player[i]->zero_extra_live();

    player[i]->zero_kill();
     }

  }
  detect.clear();
  doctor.clear();
  silencer.clear();

}


void Room :: show_silenced()
{
  vector<string> silenced_names;
  for(int i=0; i<player.size();i++)
  {
    if(player[i]->get_silence() ==1 && player[i]->get_live()>0)
      silenced_names.push_back(player[i]->get_name());
  }
  std :: sort(silenced_names.begin(),silenced_names.end());
  for(int i=0;i<silenced_names.size();i++)
  {
    cout<<"Silenced "<<silenced_names[i]<<endl;
  }
}


void Room :: Night()
{
  inc_Day();
  //cout<<player[2]->get_live()<<endl;
  cout<<"Day"<<get_Day()<<endl;

  kill_player();
  show_silenced();
  set_Day_Night();
}

int Room:: num_detective()
{ int sum=0;
  for(int i=0;i<player.size();i++)
  {
    if(player[i]->get_role()== "Detective" && player[i]->get_live()>0)
      sum++;
  }
  return sum;
}


int Room:: num_doctor()
{ int sum=0;
  for(int i=0;i<player.size();i++)
  {
    if(player[i]->get_role()== "Doctor" && player[i]->get_live()>0)
      sum++;
  }
  return sum;
}


int Room:: num_silencer()
{ int sum=0;
  for(int i=0;i<player.size();i++)
  {
    if(player[i]->get_role()== "Silencer" && player[i]->get_live()>0)
      sum++;
  }
  return sum;
}



void Room :: check_state_night()
{
  if(get_state_night() == 1)
  {
    if(num_detective()==0)
      state_night=2;
  }
  if(get_state_night() == 2)
  {
    if(num_doctor()==0)
      state_night=3;
  }
  if(get_state_night() == 3)
  {
    if(num_silencer()==0)
      state_night=4;
  }
//cout<<"get state"<<get_state_night()<<endl;
}



void Room :: change_Day()
{
  if(get_state_night()==4 && get_Day_Night()== 1)
  {
    Night();
    set_state_night(0);
    end_of_game();
    //cout<<"NNNN"<<endl;
  }
}


Room :: ~Room()
{
  for(int i=0;i<player.size();i++)
    delete player[i];
}
