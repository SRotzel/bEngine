#!/bin/bash

echo Building...
if gcc src/*.cpp -lSDL2 -lm -lstdc++ -o bin/run; then
    echo Done!
    while true; do
        read -p "Run Program? (y/n)" yn
        case $yn in
            [Yy]* ) ./bin/run; break;;
            [Nn]* ) exit;;
            * ) exit;;
        esac
    done
else
    echo Failed to compile...
fi