all: serial mpi

serial:
	g++ -std=c++11 -o serial serial.cpp kempe.cpp readfile.cpp
	
mpi:
	mpicc -std=c++11 -o mpi mpi.cpp kempe.cpp readfile.cpp
