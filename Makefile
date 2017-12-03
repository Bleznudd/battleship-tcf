#MAKEFILE OF BATTLESHIP-TCF

#DEFINIZIONE DEL COMPILATORE
CXX	= g++
#IDENTIFICA SE COMPILARE PER DEBUG O PER RELEASE
DR = UNIX
#OPZIONI DEL COMPILATORE
CFLAGS = -pipe -std=c++14 -O0 -pedantic -Wall -D$(DR)
#IDENTIFICA IL NUMERO DI JOBS PER MAKE
#(NON UTILIZZARE PIÙ DEL NUMERO DI CORES DISPONIBILI)
CPUCORES = 4

all:
	$(MAKE) -j $(CPUCORES) battleship-tcf

 #ISTRUZIONI PER L'ESEGUIBILE
battleship-tcf:	main.o Ship.o Player.o Point.o Battleship.o Carrier.o Cruiser.o Destroyer.o ShipFactory.o Graphic.o
	 $(CXX) $(CFLAGS) main.o Ship.o Player.o Point.o Battleship.o Carrier.o Cruiser.o Destroyer.o ShipFactory.o Graphic.o -o battleship-tcf

 #ISTRUZIONI PER COMPILARE LE VARIE CLASSI
main.o:  main.cpp
	 $(CXX) $(CFLAGS) -c ./main.cpp
Ship.o:  ./source/Ship.cpp
	 $(CXX) $(CFLAGS) -c ./source/Ship.cpp
Player.o:  ./source/Player.cpp
	 $(CXX) $(CFLAGS) -c ./source/Player.cpp
Point.o:  ./source/Point.cpp
	 $(CXX) $(CFLAGS) -c ./source/Point.cpp
Battleship.o:  ./source/Battleship.cpp
	 $(CXX) $(CFLAGS) -c ./source/Battleship.cpp
Carrier.o:  ./source/Carrier.cpp
	 $(CXX) $(CFLAGS) -c ./source/Carrier.cpp
Cruiser.o:  ./source/Cruiser.cpp
	 $(CXX) $(CFLAGS) -c ./source/Cruiser.cpp
Destroyer.o:  ./source/Destroyer.cpp
	 $(CXX) $(CFLAGS) -c ./source/Destroyer.cpp
ShipFactory.o: ./source/ShipFactory.cpp
	 $(CXX) $(CFLAGS) -c ./source/ShipFactory.cpp
Graphic.o: ./source/Graphic.cpp
	 $(CXX) $(CFLAGS) -c ./source/Graphic.cpp
	 