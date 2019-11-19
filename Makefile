all: serial mpi-static

serial:
	g++ -std=c++11 -o serial serial.cpp kempe.cpp readfile.cpp
	
mpi-static:
	mpicc -std=c++11 -o mpi-static mpi-static.cpp kempe.cpp readfile.cpp
