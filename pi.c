#include <mpi.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void calc_pi(int rank, int num_procs){
	int i;
	int num_intervals;
	double  h;
	double  mypi;
	double  pi;
	double  sum;
	double  x;
	
	MPI_Init (NULL ,NULL);
	
	/* set number of intervals to calculate */
	if (rank == 0) {
		num_intervals = 1000;
	}
	//16 Architectures parallèles, M. Eleuldj, Département Génie Informatique, EMI, octobre 2014
	//Programme du calcul de P(2/5) 17
	/* tell other tasks how many intervals */

	MPI_Bcast(&num_intervals, 1, MPI_INT, 0, MPI_COMM_WORLD);
	/* now everyone does their calculation */
	h = 1.0 / (double) num_intervals;
	sum = 0.0;
	for (i = rank + 1; i <= num_intervals; i += num_procs) {
		x = h * ((double)i - 0.5);
		sum += (4.0 * sqrt(1.0 - x*x));
	}
	mypi = h * sum;
	/* combine everyone's calculations */
	MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0,MPI_COMM_WORLD);
	if (rank == 0) {
		printf("PI is approximately %.16f\n", pi);
	}
	MPI_Finalize();
}

int main (int argc, char **argv)
{
	calc_pi(2,2);
}
