# !/bin/bash

g++ -c main.cpp -I~/Загрузки/SFML-2.5.1/include
g++ main.o -o main -L~/Загрузки/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
