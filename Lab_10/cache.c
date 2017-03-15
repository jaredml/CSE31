#include <sys/times.h>
#include <stdio.h>

#define CACHE_MIN (1024) /* smallest cache (in words) */
#define CACHE_MAX (1024*1024*16) /* largest cache */
#define STRIDE_MIN 1 /* smallest stride (in words) */
#define STRIDE_MAX 128 /* largest stride */
#define SAMPLE 10 /* to get a larger time sample */
#define CLK_TCK 60 /* number clock cycles per second */
int x[CACHE_MAX]; /* array going to stride through */

double get_seconds () { /* routine to read time */
  
  struct tms rusage;
  times (&rusage); /* UNIX utility: time in clock ticks */
  return (double) (rusage.tms_utime) / CLK_TCK;
}

int main () {
  
  int register i, index, stride, limit, temp;
  int steps, tsteps, csize;
  double sec0, sec; /* timing variables */
  for (csize = CACHE_MIN; csize <= CACHE_MAX; csize = csize * 2)
    
    for (stride = STRIDE_MIN; stride <= STRIDE_MAX; stride = stride * 2) {
      sec = 0; /* initialize timer */
      limit = csize - stride + 1; /* cache size this loop */
      steps = 0;
      do { /* repeat until collect 1 second */
	
	sec0 = get_seconds (); /* start timer */
	for (i = SAMPLE * stride; i != 0; i = i - 1) /* larger sample */
	  for (index = 0; index < limit; index = index + stride)
	    x[index] = x[index] + 1; /* cache access */
	steps = steps + 1; /* count while loop iterations */
	sec = sec + (get_seconds () - sec0); /* end timer */
	
      }
      while (sec < 1.0); /* until collect 1 second */
      
      /* Repeat empty loop to loop subtract overhead */
      tsteps = 0; /* used to match number of while iterations */
      do { /* repeat until same number of iterations as above */
	
	sec0 = get_seconds (); /* start timer */
	for (i = SAMPLE * stride; i != 0; i = i - 1) /* larger sample */
	  for (index = 0; index < limit; index = index + stride)
	    temp = temp + index; /* dummy code */
	tsteps = tsteps + 1; /* count while iterations */
	sec = sec - (get_seconds () - sec0); /* - overhead */
	
      }
      while (tsteps < steps); /* until equal to number of iterations */
      
      if( stride==STRIDE_MIN ) printf("\n"); /* extra line to separate array sizes */
      printf("Size(bytes): %7d Stride(bytes): %4d read+write: %4.2f ns\n",
	     csize * sizeof (int), stride * sizeof (int),
	     (double) sec*1e9 / (steps*SAMPLE*stride*((limit-1)/stride + 1)));
      
    } /* end of both outer for loops */
}
