#MAKEFILE OF BATTLESHIP-TCF

#DEFINIZIONE DEL COMPILATORE
CXX	= g++
#IDENTIFICA SE COMPILARE PER DEBUG O PER RELEASE
DR = RELEASE
#OPZIONI DEL COMPILATORE
CFLAGS = -pipe -std=c++14 -O0 -pedantic -Wall -D$(DR)
#IDENTIFICA IL NUMERO DI JOBS PER MAKE
#(NON UTILIZZARE PIÙ DEL NUMERO DI CORES DISPONIBILI)
CPUCORES = 4

all:
	$(MAKE) -j $(CPUCORES) battlehsip-tcf

 #ISTRUZIONI PER L'ESEGUIBILE
battleship-tcf:	main.o Battlehsip.o Carrier.o Cruiser.o Destroyer.o Ship.o Grid.o Player.o Point.o ShipFactory.o
	 $(CXX) $(CFLAGS) main.o Battlehsip.o Carrier.o Cruiser.o Destroyer.o Ship.o Grid.o Player.o Point.o ShipFactory.o -o battlehsip-tcf

 #ISTRUZIONI PER COMPILARE LE VARIE CLASSI
main.o:  main.cpp
	 $(CXX) $(CFLAGS) -c ./source/main.cpp
Battleship.o:  Battleship.cpp
	 $(CXX) $(CFLAGS) -c ./source/Battleship.cpp
Carrier.o:  Carrier.cpp
	 $(CXX) $(CFLAGS) -c ./source/Carrier.cpp
Cruiser.o:  Cruiser.cpp
	 $(CXX) $(CFLAGS) -c ./source/Cruiser.cpp
Destroyer.o:  Destroyer.cpp
	 $(CXX) $(CFLAGS) -c ./source/Destroyer.cpp
Ship.o:  Ship.cpp
	 $(CXX) $(CFLAGS) -c ./source/Ship.cpp
Grid.o:  Grid.cpp
	 $(CXX) $(CFLAGS) -c ./source/Grid.cpp
Player.o:  Player.cpp
	 $(CXX) $(CFLAGS) -c ./source/Player.cpp
Point.o:  Point.cpp
	 $(CXX) $(CFLAGS) -c ./source/Point.cpp
ShipFactory.o:  ShipFactory.cpp
	 $(CXX) $(CFLAGS) -c ./source/ShipFactory.cpp
