# !/bin/bash

g++ -c *.cpp -I~/Загрузки/SFML-2.5.1/include
g++ *.o -o main -L~/Загрузки/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
