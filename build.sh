#!/bin/bash
echo Building!
gcc src/*.c -lSDL2 -lm -o bin/run
echo Done!

while true; do
    read -p "Run Program? (y/n) " yn
    case $yn in
        [Yy]* ) ./bin/run; break;;
        [Nn]* ) exit;;
        * ) echo "Please answer yes or no.";;
    esac
done
