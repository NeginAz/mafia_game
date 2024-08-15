all:	myprogram



myprogram: main.o Game.o Room.o Player.o Mafia.o Villager.o Silencer.o GodFather.o Doctor.o Detective.o  RouinTan.o Joker.o MyException.o
	g++  main.cpp Game.cpp Room.cpp Player.cpp Mafia.cpp Villager.cpp Silencer.cpp GodFather.cpp Doctor.cpp Detective.cpp RouinTan.cpp Joker.cpp MyException.cpp -o myprogram

main.o : main.cpp MyException.cpp
	g++ -c main.cpp

Game.o : Game.cpp Room.cpp Game.h MyException.cpp
	g++ -c Game.cpp Room.cpp

Room.o : Room.cpp Player.cpp Mafia.cpp Villager.cpp Silencer.cpp GodFather.cpp Doctor.cpp Detective.cpp RouinTan.cpp Joker.cpp Room.h
	g++ -c Room.cpp Player.cpp Mafia.cpp Villager.cpp Silencer.cpp GodFather.cpp Doctor.cpp Detective.cpp RouinTan.cpp Joker.cpp

Player.o :Player.cpp Player.h
	g++ -c Player.cpp

Villager.o : Villager.cpp Villager.h Player.cpp
	g++ -c Villager.cpp Player.cpp

Mafia.o : Mafia.cpp Mafia.h Player.cpp
	g++ -c Mafia.cpp Player.cpp

Joker.o : Joker.cpp Joker.h Player.cpp
	g++ -c Joker.cpp Player.cpp

Detective.o : Detective.cpp Detective.h Villager.cpp Player.cpp
	g++ -c Detective.cpp Villager.cpp Player.cpp

Doctor.o : Doctor.cpp Doctor.h Villager.cpp Player.cpp
	g++ -c Doctor.cpp Villager.cpp Player.cpp

RouinTan.o : RouinTan.cpp RouinTan.h Villager.cpp Player.cpp
	g++ -c RouinTan.cpp Villager.cpp Player.cpp

Silencer : Silencer.cpp Silencer.h Mafia.cpp Player.cpp
	g++ -c Silener.cpp Mafia.cpp Player.cpp

GodFather.o : GodFather.cpp GodFather.h Mafia.cpp Player.cpp
	g++ -c GodFather.cpp Mafia.cpp Player.cpp

MyException.o : MyException.cpp MyException.h
	g++ -c MyException.cpp

clean:
	rm -r *.o
