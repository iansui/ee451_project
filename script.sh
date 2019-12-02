#! /bin/bash
#salloc --nodes=4 --ntasks-per-node=1 --time=01:00:00
source /usr/usc/openmpi/default/setup.sh
#make clean
make mpi-static
echo "mpi-static 1st run"
mpirun -np 4 ./mpi-static > static1.txt
echo "mpi-static 2nd run"
mpirun -np 4 ./mpi-static > static2.txt
echo "mpi-static 3rd run"
mpirun -np 4 ./mpi-static > static3.txt
echo "done...."
exit
