## wrapper for python
Example for making binding for python

### Compiling
```bash
g++ -shared -c -fPIC -lpugixml -lfestlib generic.cpp -o generic.o

g++ -shared -Wl,-soname,library.so -lfestlib -lpugixml -o library.so generic.o
```

### Run
```bash
python wrapper.py
```
