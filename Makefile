all: serial

serial:
	g++ -std=c++11 -o serial serial.cpp kempe.cpp readfile.cpp
