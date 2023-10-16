projectmaking:
	g++ -c main.cpp
	g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system
	./sfml-app
clear:
	rm main.o
	rm sfml-app
