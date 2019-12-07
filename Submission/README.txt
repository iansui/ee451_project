EE451 Fall 2019 Final Project
Parallelization of Kempe’s Influence Maximization Algorithm
Yi Sui, Liheng Lin, Pengcheng Li

The source files are intended to be run on USC HPC:

1. Log onto user@hpc-login3.usc.edu
2. run "source /usr/usc/openmpi/default/setup.sh"
3. run "make" to compile and generate the executables

Serial Implementation:
    -Run "sbatch serial.sl" to submit the job to be run on HPC using slurm
    
    -The default seed size and sample times to run are both 10
    
    -The output would be stored in serial-output.txt
    
    -serial.sl can be modified to run the test with different parameters, or with diffrent resources allocation time
    
    For example:
    srun --ntasks=${SLURM_NTASKS} ./serial 1 2  
    // this would run it with seed size = 1 and sample times = 2
    
    
MPI Static Mapping Implementation:
    -Run "sbatch mpi-static.sl" to submit the job to be run on HPC using slurm
    
    -The default seed size and sample times to run are both 10
    
    -The output would be stored in mpi-static-output.txt
    
    - mpi-static.sl can be modified to run the test with different parameters, or with diffrent resources allocation time, or with different number of computing nodes(workers)
    
    For example:
    srun --ntasks=${SLURM_NTASKS} ./mpi-static 1 2 > mpi-static-output.txt  
    // this would run it with seed size = 1 and sample times = 2
    
    
MPI Dynamic Mapping Implementation:
    -Run "sbatch mpi-dynamic.sl" to submit the job to be run on HPC using slurm
    
    -The default seed size and sample times to run are both 10
    
    -The default block size is 10
    
    -The output would be stored in mpi-dynamic-output.txt
    
    -mpi-dynamic.sl can be modified to run the test with different parameters, or with diffrent resources allocation time, or with different number of computing nodes(workers)
    
    For example:
    srun --ntasks=${SLURM_NTASKS} ./mpi-dynamic 1 2 50 > mpi-dynamic-output.txt  
    // this would run it with seed size = 1, sample times = 2, and block size = 50
    
    
MPI Graph Partition Implementation:
    -Run "sbatch graph-partition.sl" to submit the job to be run on HPC using slurm
    
    -The default seed size and sample times to run are both 10
    
    -The output would be stored in mpi-dynamic-output.txt
    
    -mpi-dynamic.sl can be modified to run the test with different parameters, or with diffrent resources allocation time, or with different number of computing nodes(workers)
    
    For example:
    srun --ntasks=${SLURM_NTASKS} ./mpi-dynamic 1 2 50 > mpi-dynamic-output.txt  
    // this would run it with seed size = 1, sample times = 2, and block size = 50
    
