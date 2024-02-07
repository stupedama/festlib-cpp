import ctypes
print(ctypes.CDLL('./library.so').print_generic())

