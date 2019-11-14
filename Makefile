all: kempe

kempe:
	g++ -std=c++11 -o kempe main.cpp kempe.cpp readfile.cpp
