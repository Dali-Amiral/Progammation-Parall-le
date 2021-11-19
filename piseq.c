#include <stdio.h>
#include <math.h>
#include <stdlib.h>


double Leibniz(int n) {
	double pi=1.0;
	for (int i=1; i<=n; ++i) pi += ((i&1) ? -1.0 : 1.0) / (2*i + 1);
	return 4*pi;
} // pi = 4*{1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 + ...}

double Viete(int n) {
 	double q=0.0, pi=2.0;
	for (int i=0; i<n; ++i) {
	    q = sqrt(2.0+q);
	    pi *= 2.0/q;
  	}
  	return pi;
} 
// Pi = 2 * 2/sqrt(2) * 2/sqrt(2+sqrt(2)) * 2/sqrt(2+sqrt(2+sqrt(2)) * ...

void main() {
	printf("\n\nLeibniz: pi = 4*{1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 + ...}n\n\n");
		for (int n=10; n<=1000000; n*=10) printf("\n  n=%7i: pi=%.14fn",n,Leibniz(n));
  		printf("\n\tprecis: pi=3.14159265358979n\n");

  		printf("\nnViete: pi = ");
  		printf("2 * 2/sqrt(2) * 2/sqrt(2+sqrt(2)) * 2/sqrt(2+sqrt(2+sqrt(2)) *...n\n\n");
  		
  		for (int n=4; n<=24; n+=4) printf("\n  n=%2i: pi=%.14fn\n",n,Viete(n));
  		printf("precis: pi=3.14159265358979n");

  	getchar();
}
