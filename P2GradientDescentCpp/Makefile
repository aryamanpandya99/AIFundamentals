CC = gcc
CFLAGS  = -g -Wall

linear_regression.o :  gradient_descent.cpp
	g++ -o gd gradient_descent.cpp -DWITHOUT_NUMPY -I/usr/include/python3.9 -lpython3.9
	#change above if paths different for you locally