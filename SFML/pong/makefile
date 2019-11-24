objects = Main.o

pong: Main.o
	g++ $(objects) -o pong -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

Main.o: source/Main.cpp
	g++ -c source/Main.cpp

clean:
	rm -f pong $(objects)
