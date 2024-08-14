# Mafia Game Implementation in C++

### Overview: <br>
This project is a C++ object-oriented system designed to assist the "god" in moderating the Mafia game. The system provides a comprehensive solution for managing multiple games across different rooms simultaneously, allowing the god to assign roles, track game events, and perform necessary calculations to determine game outcomes.

The Mafia game involves various roles, including Joker, Villager, Detective, Doctor, RouinTan, Mafia, GodFather, and Silencer, which are randomly assigned to players. The system is designed with a flexible class structure: a Game class that manages Room instances, where each room hosts players with different roles.

A base class User underpins the system, with derived classes representing the different player roles, such as Villager, Mafia, and Joker. Further specializations include roles like Detective, Doctor, and RouinTan derived from the Villager class, and GodFather and Silencer derived from the Mafia class. This design ensures that the god can effectively manage the game, providing a seamless and organized experience for all participant


### Roles: <br> 
* Joker: Has unique objectives and can influence the game unpredictably.
* Villager: A regular townsperson with no special abilities.
* Detective: Can investigate players to determine their roles.
* Doctor: Can heal one player per round, saving them from potential elimination.
* RouinTan: Has special abilities.
* Mafia: Works with the other Mafia members to eliminate the Villagers.
* GodFather: The leader of the Mafia, often undetectable by the Detective.
* Silencer: Can silence one player per round, preventing them from speaking or voting.

### System Design: 
```mermaid
classDiagram
      Animal <|-- Duck
      Animal <|-- Fish
      Animal <|-- Zebra
      Animal : +int age
      Animal : +String gender
      Animal: +isMammal()
      Animal: +mate()
      class Duck{
          +String beakColor
          +swim()
          +quack()
      }
      class Fish{
          -int sizeInFeet
          -canEat()
      }
      class Zebra{
          +bool is_wild
          +run()
      }
```

```mermaid
classDiagram
      Game *-- Room
      Room
      Game : -vector <Room*> rooms
      Game : -Room* curr
      Room : -string room_name
      Room : -int Day_Night=0
      Room : -int Day_Num=0
      Room : -int state_night
      Room : -vector <string> role_name
      Room : -vector <int> role_number
      Room : -vector <string> user_name
      Room : -vector <int> player_ind
      Room : -vector<Player*> player
      Room : -vector <string> voters
      Room : -vector<string> votee
      Room : -vector<string> detect
      Room : -vector<string>silencer
      Room : -vector<string>doctor
      Room : -int delete_room=0
      Player: ~string name
      Player: ~int live=1
      Player: ~int extra_live=0
      Player: ~int nodeath=0
      Player: ~int silence=0 
      Player: ~int vote=0 
      Player: ~int kill
      Detective :+string get_role()
      Detective: +Detective(string username)
      Villager <|-- Detective
class Game{
      +void  add_role(string role_name_,string role_num)
      +void create_room(vector <string> commands)
      +bool check_num_villager()
      +bool check_num_mafia()
      +void switch_room(vector <string> commands)
      +void join(vector <string> commands)
      +void show_Day()
      +void vote(vector <string> commands)
      +void  end_vote()
      +void detect()
      +void silent()
      +void detect(vector <string> commands)
      +void heal(vector <string> commands)
      +void  silent(vector <string> commands)
      +int check_room(string room_name)
      +int change_to_number(string role_num)
      +void check_create_room(vector <string> commands)
      +void get_room_state(vector <string> commands)
      +void check_delete();
}
class room{
        +string get_room_name()
        +Room(string room_name_)
        +void set_role_number(int index,int num)
        +int get_role_number(int index)
        +string get_role_name(int index)
        +int add_user_name(string username_)
        +int all_roles()
        +void alloc_role(int ind,string username)
        +void set_role()
        +void role_to_person()
        +int rand_role(string username_)
        +int get_Day()
        +void  inc_Day()
        +int get_Day_Night()
        +void set_Day_Night()
        +void check_voter(string voter)
        +void check_votee(string votee,string voter)
        +void count_votes()
        +void make_silent(string player_)
        +bool is_silencer(string silencer_name)
        +void save_player(string player_)
        +void check_suspect(string suspect)
        +bool check_detective(string detective_)
        +void dead_Day(int index)
        +void Night_vote(string voter,int index)
        +void kill_Night(int index)
        +bool check_doctor(string doctor_)
        +int Num_Mafia()
        +void print_role()
        +void add_votes_to_player()
        +int find_voter(string voter)
        +int find_player(string name)
        +void set_vote_zero()
        +void change_voter_vote(string voter)
        +int repeated_detective(string detective_)
        +int repeated_doctor(string doctor_)
        +int repeated_silencer(string silencer_name)
        +void show_silenced()
        +void Night()
        +void kill_player()
        +int Num_Villager()
        +void end_of_game()
        +void set_state_night(int state)
        +int get_state_night()
        +void check_state_night()
        +int num_silencer()
        +int num_doctor()
        +int num_detective()
        +void change_Day()
        + ~Room()
        +int get_delete()
}
class Player{
  +virtual string get_role()=0
  +Player(string username)
  +int get_silence()
  +void set_silence()
  +void add_vote()
  +int get_vote()
  +string get_name()
  +void set_live()
  +int get_live()
  +void set_extra_live()
  +int get_extra_live()
  +void zero_extra_live()
  +virtual bool is_Mafia()=0
  +virtual bool is_Villager()=0 
  +void set_nodeath()
  +int get_nodeath()
  +void set_vote_to_zero()
  +void set_kill()
  +int get_kill()
  +void zero_kill()
}

```



### Commands: 
The following commands are available for players to interact with the game:

* Create_room room_name (role_name number): Creates a new game room with the specified roles and number of players.
* Switch_room room_number: Switches the player to the specified game room.
* Join user_name: Joins the game with the specified user name.
* Vote voter_name votee_name: Casts a vote from the voter to the votee.
* End_vote: Ends the voting phase.
* Detect detective_name suspect_name: Allows the Detective to investigate a suspect.
* Heal doctor_name person_name: Allows the Doctor to heal a person.
* Silent silencer_name person: Allows the Silencer to silence a player.
* Day day_num: Advances the game to the specified day number.
* Killed user_name: Marks the specified user as killed.
* Silenced user_name: Marks the specified user as silenced.
* Get_room_state: Outputs the current state of the room, including the number of Mafia members and Villagers.

### Usage:
Follow the prompts in the game to create rooms, join rooms, assign roles, and play the game using the available commands.


