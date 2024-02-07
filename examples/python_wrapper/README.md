## wrapper for python

## compile
g++ -shared -c -fPIC -lpugixml -lfestlib generic.cpp -o generic.o
g++ -shared -Wl,-soname,library.so -lfestlib -lpugixml -o library.so generic.o

## run
python wrapper.py
