#!/bin/bash
echo Building!
gcc src/*.c -lSDL2 -lm -o bin/run
echo Done!
