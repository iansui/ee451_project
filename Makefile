all: serial mpi-static mpi-dynamic

serial:
	g++ -std=c++11 -o serial serial.cpp kempe.cpp readfile.cpp
	
mpi-static:
	mpic++ -std=c++11 -o mpi-static mpi-static.cpp kempe.cpp readfile.cpp

mpi-dynamic:
	mpic++ -std=c++11 -o mpi-dynamic mpi-dynamic.cpp kempe.cpp readfile.cpp

clean:
	rm -f serial
	rm -f mpi-static
	rm -f mpi-dynamic
