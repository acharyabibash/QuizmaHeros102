Quizma: Menu.o main.o
	g++ *.o -o Quizma -lsfml-system -lsfml-window\
	    -lsfml-graphics -lsfml-audio


Menu.o: Menu.cpp Menu.h
	g++ -Wall -g -c Menu.cpp

main.o: main.cpp
	g++ -Wall -g -c main.cpp

clean:
	rm -vf *.o

delete:
	rm -vf Quizma
