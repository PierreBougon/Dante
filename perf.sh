#!/bin/bash

make -s -C largeur/
make -s -C profondeur/
make -s -C tournoi/
make -s -C astar/
make -s -C generateur/

echo "generating a maze..."
time ./generateur/generateur 1000 1000 > mazes/perf.txt
echo "testing the maze with all algorithm..."
time ./largeur/solver mazes/perf.txt > /dev/null
echo "largeur done"
time ./profondeur/solver mazes/perf.txt > /dev/null
echo "profondeur done"
time ./astar/solver mazes/perf.txt > /dev/null
echo "astar done"
time ./tournoi/solver mazes/perf.txt > /dev/null
echo "tournoi done"
