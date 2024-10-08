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
      Game : -vector ~Room*~ rooms
      Game : -Room* curr
      Room : -string room_name
      Room : -int Day_Night=0
      Room : -int Day_Num=0
      Room : -int state_night
      Room : -vector ~string~ role_name
      Room : -vector ~int~ role_number
      Room : -vector ~string~ user_name
      Room : -vector ~int~ player_ind
      Room : -vector ~Player*~ player
      Room : -vector ~string~ voters
      Room : -vector ~string~ votee
      Room : -vector ~string~ detect
      Room : -vector ~string~ silencer
      Room : -vector ~string~ doctor
      Room : -int delete_room=0
      Player: ~string name
      Player: ~int live=1
      Player: ~int extra_live=0
      Player: ~int nodeath=0
      Player: ~int silence=0 
      Player: ~int vote=0 
      Player: ~int kill
      Villager <|-- Detective
      Villager <|-- Doctor
      Villager <|-- RouinTan
      Mafia <|-- GodFather
      Player <|-- Joker
      Player <|-- Mafia
      Villager <|-- RouinTan
      Mafia <|-- Silencer
      Player <|-- Villager

class Villager{
      +virtual get_role() String
      +Villager(username)
      +is_Mafia() bool
      +is_Villager() bool
}


class Silencer{
      +get_role() String
      +Silencer(username)
}

class RouinTan{
      +get_role() String
      +RouinTan(username)
}

class Mafia{
      +virtual get_role() String
      +Mafia(username)
      +is_Mafia() bool
      +is_Villager() bool
}

class Detective{
      +get_role() String
      +Detective(username)
}
class GodFather{
      +get_role() String
      +GodFather(username)
}
class Doctor{
      +get_role() String
      +Doctor (username)
}

class Joker{
      +virtual get_role() String
      +Joker (username)
      +is_Mafia() bool
      +is_Villager() bool
}      
class Game{
      +add_role(role_name_, role_num)
      +create_room(vector ~string~ commands)
      +switch_room(vector ~string~ commands)
      +join(vector ~string~ commands)
      +show_Day()
      +vote(vector ~string~ commands)
      +detect(vector ~string~ commands)
      +heal(vector ~string~ commands)
      +silent(vector ~string~ commands)
      +change_to_number(role_num) int
      +get_room_state(vector ~string~ commands)
}
class room{
        +set_role_number(index, num)
        +add_user_name(username_) int
        +all_roles() int
        +alloc_role(ind, username)
        +rand_role(username_) int
        +get_Day() int
        +check_voter(voter)
        +check_votee(votee,voter)
        +count_votes()
        +save_player(player_)
        +check_suspect(suspect)
        +kill_player()
        +end_of_game()
        +set_state_night(state)
        +get_state_night() int
        +check_state_night()

}





class Player{
  +virtual get_role()=0 String
  +add_vote()
  +get_vote() int
  +get_name() String
  +set_live()
  +get_live() int
  +set_extra_live()
  +get_extra_live() int
  +zero_extra_live()
  +virtual is_Mafia()=0 bool
  +virtual is_Villager()=0 bool
  +set_kill()
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


