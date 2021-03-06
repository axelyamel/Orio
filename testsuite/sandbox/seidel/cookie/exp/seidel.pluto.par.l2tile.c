#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

double A[N][N+13];

void init_arrays()
{
  int i, j;
  for (i=0; i<N; i++) 
    for (j=0; j<N; j++) 
      A[i][j] = i*i+j*j;
}

double rtclock()
{
  struct timezone tzp;
  struct timeval tp;
  int stat;
  gettimeofday (&tp, &tzp);
  return (tp.tv_sec + tp.tv_usec*1.0e-6);
}

int main()
{
  init_arrays();

  double annot_t_start=0, annot_t_end=0, annot_t_total=0;
  int annot_i;

  for (annot_i=0; annot_i<REPS; annot_i++)
  {
    annot_t_start = rtclock();
    

#include <math.h>
#include <assert.h>
#include <omp.h>
#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))



 int c1, c2, c3, c4, c5, c6, c7, c8, c9;
 register int lb, ub, lb1, ub1, lb2, ub2;
 register int lbv, ubv;

if (N >= 3) {
  for (c1=-1;c1<=floord(2*T+N-4,256);c1++) {
 lb1=max(max(ceild(256*c1-T+1,256),ceild(128*c1-127,256)),0);
 ub1=min(min(floord(256*c1+255,256),floord(256*c1+N+253,512)),floord(T+N-3,256));
#pragma omp parallel for shared(c1,lb1,ub1) private(c2,c3,c4,c5,c6,c7,c8,c9)
 for (c2=lb1; c2<=ub1; c2++) {
      for (c3=max(max(max(max(0,ceild(512*c2-N-252,256)),ceild(512*c1-512*c2-253,256)),ceild(128*c2-127,128)),ceild(128*c1-127,128));c3<=min(min(min(min(floord(T+N-3,128),floord(256*c1-256*c2+N+253,128)),floord(256*c1+N+508,256)),floord(256*c2+T+N+252,256)),floord(512*c2+N+507,256));c3++) {
        for (c4=max(max(max(max(0,ceild(128*c3-N-29,32)),8*c1-8*c2),ceild(256*c2-N-29,32)),ceild(-256*c2+256*c3-N-284,32));c4<=min(min(min(min(8*c1-8*c2+7,floord(T-1,32)),floord(128*c2+127,16)),floord(-128*c2+128*c3+127,16)),floord(256*c3+253,64));c4++) {
          for (c5=max(max(max(max(max(0,8*c2),ceild(256*c3-N-59,64)),ceild(256*c3-32*c4-N-60,32)),ceild(256*c3-T-N-28,32)),ceild(16*c4-15,16));c5<=min(min(min(min(min(8*c2+7,floord(256*c3+N+252,64)),floord(128*c3+127,16)),floord(128*c3-16*c4+127,16)),floord(T+N-3,32)),floord(32*c4+N+29,32));c5++) {
            for (c6=max(max(max(max(max(8*c3,ceild(16*c4+16*c5-15,16)),ceild(64*c5-N-28,32)),ceild(16*c5-15,16)),ceild(64*c4-29,32)),0);c6<=min(min(min(min(min(floord(T+N-3,16),floord(32*c5+T+N+28,32)),floord(64*c5+N+59,32)),floord(32*c4+N+29,16)),8*c3+7),floord(32*c4+32*c5+N+60,32));c6++) {
              for (c7=max(max(max(max(0,32*c4),32*c5-N+2),16*c6-N+2),-32*c5+32*c6-N-29);c7<=min(min(min(min(T-1,-32*c5+32*c6+30),floord(32*c6+29,2)),32*c4+31),32*c5+30);c7++) {

		/*@ begin Loop(
		  transform Unroll(ufactor=4)
                for (c8=max(max(c7+1,32*c5),32*c6-c7-N+2);c8<=min(min(c7+N-2,32*c6-c7+30),32*c5+31);c8++) {
		  transform UnrollJam(ufactor=4)
                  for (c9=max(c7+c8+1,32*c6);c9<=min(c7+c8+N-2,32*c6+31);c9++) {
                    A[-c7+c8][-c7-c8+c9]=(A[1+-c7+c8][1+-c7-c8+c9]+A[1+-c7+c8][-c7-c8+c9]+A[1+-c7+c8][-c7-c8+c9-1]+A[-c7+c8][1+-c7-c8+c9]+A[-c7+c8][-c7-c8+c9]+A[-c7+c8][-c7-c8+c9-1]+A[-c7+c8-1][1+-c7-c8+c9]+A[-c7+c8-1][-c7-c8+c9]+A[-c7+c8-1][-c7-c8+c9-1])/9;
                  }
                }
		) @*/  {
    for (c8=max(max(c7+1,32*c5),32*c6-c7-N+2); c8<=min(min(c7+N-2,32*c6-c7+30),32*c5+31)-3; c8=c8+4) {
      {
        for (c9=max(c7+c8+1,32*c6); c9<=min(c7+c8+N-2,32*c6+31)-3; c9=c9+4) {
          A[-c7+c8][-c7+c9-c8]=0.111111111111*(A[-c7+c8+1][-c7+c9-c8+1]+A[-c7+c8+1][-c7+c9-c8]+A[-c7+c8+1][-c7+c9-c8-1]+A[-c7+c8][-c7+c9-c8+1]+A[-c7+c8][-c7+c9-c8]+A[-c7+c8][-c7+c9-c8-1]+A[-c7+c8-1][-c7+c9-c8+1]+A[-c7+c8-1][-c7+c9-c8]+A[-c7+c8-1][-c7+c9-c8-1]);
          A[-c7+c8][-c7+c9-c8+1]=0.111111111111*(A[-c7+c8+1][-c7+c9-c8+2]+A[-c7+c8+1][-c7+c9-c8+1]+A[-c7+c8+1][-c7+c9-c8]+A[-c7+c8][-c7+c9-c8+2]+A[-c7+c8][-c7+c9-c8+1]+A[-c7+c8][-c7+c9-c8]+A[-c7+c8-1][-c7+c9-c8+2]+A[-c7+c8-1][-c7+c9-c8+1]+A[-c7+c8-1][-c7+c9-c8]);
          A[-c7+c8][-c7+c9-c8+2]=0.111111111111*(A[-c7+c8+1][-c7+c9-c8+3]+A[-c7+c8+1][-c7+c9-c8+2]+A[-c7+c8+1][-c7+c9-c8+1]+A[-c7+c8][-c7+c9-c8+3]+A[-c7+c8][-c7+c9-c8+2]+A[-c7+c8][-c7+c9-c8+1]+A[-c7+c8-1][-c7+c9-c8+3]+A[-c7+c8-1][-c7+c9-c8+2]+A[-c7+c8-1][-c7+c9-c8+1]);
          A[-c7+c8][-c7+c9-c8+3]=0.111111111111*(A[-c7+c8+1][-c7+c9-c8+4]+A[-c7+c8+1][-c7+c9-c8+3]+A[-c7+c8+1][-c7+c9-c8+2]+A[-c7+c8][-c7+c9-c8+4]+A[-c7+c8][-c7+c9-c8+3]+A[-c7+c8][-c7+c9-c8+2]+A[-c7+c8-1][-c7+c9-c8+4]+A[-c7+c8-1][-c7+c9-c8+3]+A[-c7+c8-1][-c7+c9-c8+2]);
        }
        for (; c9<=min(c7+c8+N-2,32*c6+31); c9=c9+1) {
          A[-c7+c8][-c7+c9-c8]=0.111111111111*(A[-c7+c8+1][-c7+c9-c8+1]+A[-c7+c8+1][-c7+c9-c8]+A[-c7+c8+1][-c7+c9-c8-1]+A[-c7+c8][-c7+c9-c8+1]+A[-c7+c8][-c7+c9-c8]+A[-c7+c8][-c7+c9-c8-1]+A[-c7+c8-1][-c7+c9-c8+1]+A[-c7+c8-1][-c7+c9-c8]+A[-c7+c8-1][-c7+c9-c8-1]);
        }
      }
      {
        for (c9=max(c7+c8+2,32*c6); c9<=min(c7+c8+N-1,32*c6+31)-3; c9=c9+4) {
          A[-c7+c8+1][-c7+c9-c8-1]=0.111111111111*(A[-c7+c8+2][-c7+c9-c8]+A[-c7+c8+2][-c7+c9-c8-1]+A[-c7+c8+2][-c7+c9-c8-2]+A[-c7+c8+1][-c7+c9-c8]+A[-c7+c8+1][-c7+c9-c8-1]+A[-c7+c8+1][-c7+c9-c8-2]+A[-c7+c8][-c7+c9-c8]+A[-c7+c8][-c7+c9-c8-1]+A[-c7+c8][-c7+c9-c8-2]);
          A[-c7+c8+1][-c7+c9-c8]=0.111111111111*(A[-c7+c8+2][-c7+c9-c8+1]+A[-c7+c8+2][-c7+c9-c8]+A[-c7+c8+2][-c7+c9-c8-1]+A[-c7+c8+1][-c7+c9-c8+1]+A[-c7+c8+1][-c7+c9-c8]+A[-c7+c8+1][-c7+c9-c8-1]+A[-c7+c8][-c7+c9-c8+1]+A[-c7+c8][-c7+c9-c8]+A[-c7+c8][-c7+c9-c8-1]);
          A[-c7+c8+1][-c7+c9-c8+1]=0.111111111111*(A[-c7+c8+2][-c7+c9-c8+2]+A[-c7+c8+2][-c7+c9-c8+1]+A[-c7+c8+2][-c7+c9-c8]+A[-c7+c8+1][-c7+c9-c8+2]+A[-c7+c8+1][-c7+c9-c8+1]+A[-c7+c8+1][-c7+c9-c8]+A[-c7+c8][-c7+c9-c8+2]+A[-c7+c8][-c7+c9-c8+1]+A[-c7+c8][-c7+c9-c8]);
          A[-c7+c8+1][-c7+c9-c8+2]=0.111111111111*(A[-c7+c8+2][-c7+c9-c8+3]+A[-c7+c8+2][-c7+c9-c8+2]+A[-c7+c8+2][-c7+c9-c8+1]+A[-c7+c8+1][-c7+c9-c8+3]+A[-c7+c8+1][-c7+c9-c8+2]+A[-c7+c8+1][-c7+c9-c8+1]+A[-c7+c8][-c7+c9-c8+3]+A[-c7+c8][-c7+c9-c8+2]+A[-c7+c8][-c7+c9-c8+1]);
        }
        for (; c9<=min(c7+c8+N-1,32*c6+31); c9=c9+1) {
          A[-c7+c8+1][-c7+c9-c8-1]=0.111111111111*(A[-c7+c8+2][-c7+c9-c8]+A[-c7+c8+2][-c7+c9-c8-1]+A[-c7+c8+2][-c7+c9-c8-2]+A[-c7+c8+1][-c7+c9-c8]+A[-c7+c8+1][-c7+c9-c8-1]+A[-c7+c8+1][-c7+c9-c8-2]+A[-c7+c8][-c7+c9-c8]+A[-c7+c8][-c7+c9-c8-1]+A[-c7+c8][-c7+c9-c8-2]);
        }
      }
      {
        for (c9=max(c7+c8+3,32*c6); c9<=min(c7+c8+N,32*c6+31)-3; c9=c9+4) {
          A[-c7+c8+2][-c7+c9-c8-2]=0.111111111111*(A[-c7+c8+3][-c7+c9-c8-1]+A[-c7+c8+3][-c7+c9-c8-2]+A[-c7+c8+3][-c7+c9-c8-3]+A[-c7+c8+2][-c7+c9-c8-1]+A[-c7+c8+2][-c7+c9-c8-2]+A[-c7+c8+2][-c7+c9-c8-3]+A[-c7+c8+1][-c7+c9-c8-1]+A[-c7+c8+1][-c7+c9-c8-2]+A[-c7+c8+1][-c7+c9-c8-3]);
          A[-c7+c8+2][-c7+c9-c8-1]=0.111111111111*(A[-c7+c8+3][-c7+c9-c8]+A[-c7+c8+3][-c7+c9-c8-1]+A[-c7+c8+3][-c7+c9-c8-2]+A[-c7+c8+2][-c7+c9-c8]+A[-c7+c8+2][-c7+c9-c8-1]+A[-c7+c8+2][-c7+c9-c8-2]+A[-c7+c8+1][-c7+c9-c8]+A[-c7+c8+1][-c7+c9-c8-1]+A[-c7+c8+1][-c7+c9-c8-2]);
          A[-c7+c8+2][-c7+c9-c8]=0.111111111111*(A[-c7+c8+3][-c7+c9-c8+1]+A[-c7+c8+3][-c7+c9-c8]+A[-c7+c8+3][-c7+c9-c8-1]+A[-c7+c8+2][-c7+c9-c8+1]+A[-c7+c8+2][-c7+c9-c8]+A[-c7+c8+2][-c7+c9-c8-1]+A[-c7+c8+1][-c7+c9-c8+1]+A[-c7+c8+1][-c7+c9-c8]+A[-c7+c8+1][-c7+c9-c8-1]);
          A[-c7+c8+2][-c7+c9-c8+1]=0.111111111111*(A[-c7+c8+3][-c7+c9-c8+2]+A[-c7+c8+3][-c7+c9-c8+1]+A[-c7+c8+3][-c7+c9-c8]+A[-c7+c8+2][-c7+c9-c8+2]+A[-c7+c8+2][-c7+c9-c8+1]+A[-c7+c8+2][-c7+c9-c8]+A[-c7+c8+1][-c7+c9-c8+2]+A[-c7+c8+1][-c7+c9-c8+1]+A[-c7+c8+1][-c7+c9-c8]);
        }
        for (; c9<=min(c7+c8+N,32*c6+31); c9=c9+1) {
          A[-c7+c8+2][-c7+c9-c8-2]=0.111111111111*(A[-c7+c8+3][-c7+c9-c8-1]+A[-c7+c8+3][-c7+c9-c8-2]+A[-c7+c8+3][-c7+c9-c8-3]+A[-c7+c8+2][-c7+c9-c8-1]+A[-c7+c8+2][-c7+c9-c8-2]+A[-c7+c8+2][-c7+c9-c8-3]+A[-c7+c8+1][-c7+c9-c8-1]+A[-c7+c8+1][-c7+c9-c8-2]+A[-c7+c8+1][-c7+c9-c8-3]);
        }
      }
      {
        for (c9=max(c7+c8+4,32*c6); c9<=min(c7+c8+N+1,32*c6+31)-3; c9=c9+4) {
          A[-c7+c8+3][-c7+c9-c8-3]=0.111111111111*(A[-c7+c8+4][-c7+c9-c8-2]+A[-c7+c8+4][-c7+c9-c8-3]+A[-c7+c8+4][-c7+c9-c8-4]+A[-c7+c8+3][-c7+c9-c8-2]+A[-c7+c8+3][-c7+c9-c8-3]+A[-c7+c8+3][-c7+c9-c8-4]+A[-c7+c8+2][-c7+c9-c8-2]+A[-c7+c8+2][-c7+c9-c8-3]+A[-c7+c8+2][-c7+c9-c8-4]);
          A[-c7+c8+3][-c7+c9-c8-2]=0.111111111111*(A[-c7+c8+4][-c7+c9-c8-1]+A[-c7+c8+4][-c7+c9-c8-2]+A[-c7+c8+4][-c7+c9-c8-3]+A[-c7+c8+3][-c7+c9-c8-1]+A[-c7+c8+3][-c7+c9-c8-2]+A[-c7+c8+3][-c7+c9-c8-3]+A[-c7+c8+2][-c7+c9-c8-1]+A[-c7+c8+2][-c7+c9-c8-2]+A[-c7+c8+2][-c7+c9-c8-3]);
          A[-c7+c8+3][-c7+c9-c8-1]=0.111111111111*(A[-c7+c8+4][-c7+c9-c8]+A[-c7+c8+4][-c7+c9-c8-1]+A[-c7+c8+4][-c7+c9-c8-2]+A[-c7+c8+3][-c7+c9-c8]+A[-c7+c8+3][-c7+c9-c8-1]+A[-c7+c8+3][-c7+c9-c8-2]+A[-c7+c8+2][-c7+c9-c8]+A[-c7+c8+2][-c7+c9-c8-1]+A[-c7+c8+2][-c7+c9-c8-2]);
          A[-c7+c8+3][-c7+c9-c8]=0.111111111111*(A[-c7+c8+4][-c7+c9-c8+1]+A[-c7+c8+4][-c7+c9-c8]+A[-c7+c8+4][-c7+c9-c8-1]+A[-c7+c8+3][-c7+c9-c8+1]+A[-c7+c8+3][-c7+c9-c8]+A[-c7+c8+3][-c7+c9-c8-1]+A[-c7+c8+2][-c7+c9-c8+1]+A[-c7+c8+2][-c7+c9-c8]+A[-c7+c8+2][-c7+c9-c8-1]);
        }
        for (; c9<=min(c7+c8+N+1,32*c6+31); c9=c9+1) {
          A[-c7+c8+3][-c7+c9-c8-3]=0.111111111111*(A[-c7+c8+4][-c7+c9-c8-2]+A[-c7+c8+4][-c7+c9-c8-3]+A[-c7+c8+4][-c7+c9-c8-4]+A[-c7+c8+3][-c7+c9-c8-2]+A[-c7+c8+3][-c7+c9-c8-3]+A[-c7+c8+3][-c7+c9-c8-4]+A[-c7+c8+2][-c7+c9-c8-2]+A[-c7+c8+2][-c7+c9-c8-3]+A[-c7+c8+2][-c7+c9-c8-4]);
        }
      }
    }
    for (; c8<=min(min(c7+N-2,32*c6-c7+30),32*c5+31); c8=c8+1) {
      {
        for (c9=max(c7+c8+1,32*c6); c9<=min(c7+c8+N-2,32*c6+31)-3; c9=c9+4) {
          A[-c7+c8][-c7+c9-c8]=0.111111111111*(A[-c7+c8+1][-c7+c9-c8+1]+A[-c7+c8+1][-c7+c9-c8]+A[-c7+c8+1][-c7+c9-c8-1]+A[-c7+c8][-c7+c9-c8+1]+A[-c7+c8][-c7+c9-c8]+A[-c7+c8][-c7+c9-c8-1]+A[-c7+c8-1][-c7+c9-c8+1]+A[-c7+c8-1][-c7+c9-c8]+A[-c7+c8-1][-c7+c9-c8-1]);
          A[-c7+c8][-c7+c9-c8+1]=0.111111111111*(A[-c7+c8+1][-c7+c9-c8+2]+A[-c7+c8+1][-c7+c9-c8+1]+A[-c7+c8+1][-c7+c9-c8]+A[-c7+c8][-c7+c9-c8+2]+A[-c7+c8][-c7+c9-c8+1]+A[-c7+c8][-c7+c9-c8]+A[-c7+c8-1][-c7+c9-c8+2]+A[-c7+c8-1][-c7+c9-c8+1]+A[-c7+c8-1][-c7+c9-c8]);
          A[-c7+c8][-c7+c9-c8+2]=0.111111111111*(A[-c7+c8+1][-c7+c9-c8+3]+A[-c7+c8+1][-c7+c9-c8+2]+A[-c7+c8+1][-c7+c9-c8+1]+A[-c7+c8][-c7+c9-c8+3]+A[-c7+c8][-c7+c9-c8+2]+A[-c7+c8][-c7+c9-c8+1]+A[-c7+c8-1][-c7+c9-c8+3]+A[-c7+c8-1][-c7+c9-c8+2]+A[-c7+c8-1][-c7+c9-c8+1]);
          A[-c7+c8][-c7+c9-c8+3]=0.111111111111*(A[-c7+c8+1][-c7+c9-c8+4]+A[-c7+c8+1][-c7+c9-c8+3]+A[-c7+c8+1][-c7+c9-c8+2]+A[-c7+c8][-c7+c9-c8+4]+A[-c7+c8][-c7+c9-c8+3]+A[-c7+c8][-c7+c9-c8+2]+A[-c7+c8-1][-c7+c9-c8+4]+A[-c7+c8-1][-c7+c9-c8+3]+A[-c7+c8-1][-c7+c9-c8+2]);
        }
        for (; c9<=min(c7+c8+N-2,32*c6+31); c9=c9+1) {
          A[-c7+c8][-c7-c8+c9]=(A[1+-c7+c8][1+-c7-c8+c9]+A[1+-c7+c8][-c7-c8+c9]+A[1+-c7+c8][-c7-c8+c9-1]+A[-c7+c8][1+-c7-c8+c9]+A[-c7+c8][-c7-c8+c9]+A[-c7+c8][-c7-c8+c9-1]+A[-c7+c8-1][1+-c7-c8+c9]+A[-c7+c8-1][-c7-c8+c9]+A[-c7+c8-1][-c7-c8+c9-1])/9;
        }
      }
    }
  }
/*@ end @*/

              }
            }
          }
        }
      }
    }
  }
}


    annot_t_end = rtclock();
    annot_t_total += annot_t_end - annot_t_start;
  }
  
  annot_t_total = annot_t_total / REPS;

#ifndef TEST
  printf("%f\n", annot_t_total);
#else
  {
    int i, j;
    for (i=0; i<N; i++) {
      for (j=0; j<N; j++) {
	if (j%100==0)
	  printf("\n");
	printf("%f ",A[i][j]);
      }
      printf("\n");
    }
  }
#endif
  
  return ((int) A[0][0]); 

}
                                    
