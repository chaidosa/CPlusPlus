#include<bits/stdc++.h>
#include "omp.h"

using namespace std;

static long num_steps = 100000000;
double step;
int main(){
	double start = omp_get_wtime();
	double pi;
	omp_set_num_threads(4);
	for(int j = 0; j < 10; j++)
	{
		
		double x,t, sum = 0.0;
		int i;
		step = 1.0/(double) num_steps;
		
		#pragma omp parallel for reduction(+ : sum) private(x)
		for(i = 0; i < num_steps; i++){		
			x = (i+0.5)*step;			
			sum += 4.0/(1.0 + x*x);			
		}
			
		pi = step*sum;
	}
	
	double end = omp_get_wtime();	
	cout<<pi;
	cout<<"\naverage time "<<(end-start)/10;
return 0;
}
