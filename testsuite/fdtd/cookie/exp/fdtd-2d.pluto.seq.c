
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

#define tmax T
#define nx N
#define ny N
double ex[nx][ny +1];
double ey[nx +1][ny];
double hz[nx][ny];

void init_arrays()
{
    int i, j;
    for (i=0; i<nx+1; i++)  {
        for (j=0; j<ny; j++)  {
            ey[i][j] = 0;
        }
    }
    for (i=0; i<nx; i++)  {
        for (j=0; j<ny+1; j++)  {
            ex[i][j] = 0;
        }
    }
    for (j=0; j<ny; j++)  {
        ey[0][j] = ((double)j)/ny;
    }
    for (i=0; i<nx; i++)    {
        for (j=0; j<ny; j++)  {
            hz[i][j] = 0;
        }
    }
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

#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))

	#define S1(zT0,zT1,t,j)	{ey[0][j]=t;}
	#define S2(zT0,zT1,zT2,t,i,j)	{ey[i][j]=ey[i][j]-((double)(1))/2*(hz[i][j]-hz[i-1][j]);}
	#define S3(zT0,zT1,zT2,t,i,j)	{ex[i][j]=ex[i][j]-((double)(1))/2*(hz[i][j]-hz[i][j-1]);}
	#define S4(zT0,zT1,zT2,t,i,j)	{hz[i][j]=hz[i][j]-((double)(7))/10*(ey[1+i][j]+ex[i][1+j]-ex[i][j]-ey[i][j]);}

	int c1, c2, c3, c4, c5, c6;

	register int lbv, ubv;

/* Generated from PLuTo-produced CLooG file by CLooG v0.14.1 64 bits in 0.25s. */
for (c1=0;c1<=floord(tmax-1,32);c1++) {
  for (c2=max(ceild(32*c1-31,32),0);c2<=min(floord(tmax+ny-1,32),floord(32*c1+ny+31,32));c2++) {
    for (c3=max(max(max(max(ceild(32*c2-ny-30,32),0),ceild(64*c1-32*c2-61,32)),ceild(32*c1-31,32)),ceild(32*c1-992*c2-1891,992));c3<=min(min(floord(32*c2+nx+30,32),floord(tmax+nx-1,32)),floord(32*c1+nx+31,32));c3++) {
      if ((c1 <= floord(32*c3-nx,32)) && (c2 <= floord(32*c3-nx+ny,32)) && (c3 >= ceild(nx,32))) {
        for (c5=max(32*c3-nx+1,32*c2);c5<=min(32*c2+31,32*c3-nx+ny);c5++) {
          S4(c1,-c1+c3,-c1+c2,32*c3-nx,nx-1,-32*c3+c5+nx-1) ;
        }
      }
      if ((c1 <= floord(32*c2-ny,32)) && (c2 >= max(ceild(32*c3-nx+ny+1,32),ceild(ny,32)))) {
        for (c6=max(32*c3,32*c2-ny+1);c6<=min(32*c2+nx-ny,32*c3+31);c6++) {
          S4(c1,-c1+c3,-c1+c2,32*c2-ny,-32*c2+c6+ny-1,ny-1) ;
        }
      }
      if (c1 == c3) {
        for (c4=max(max(32*c2-ny+1,0),32*c3);c4<=min(min(32*c3+30,tmax-1),32*c2-ny+31);c4++) {
          for (c5=32*c2;c5<=c4+ny-1;c5++) {
            S1(c1,-c1+c2,c4,-c4+c5) ;
            S3(c1,0,-c1+c2,c4,0,-c4+c5) ;
            for (c6=c4+1;c6<=32*c3+31;c6++) {
              S2(c1,0,-c1+c2,c4,-c4+c6,-c4+c5) ;
              S3(c1,0,-c1+c2,c4,-c4+c6,-c4+c5) ;
              S4(c1,0,-c1+c2,c4,-c4+c6-1,-c4+c5-1) ;
            }
          }
          for (c6=c4+1;c6<=32*c3+31;c6++) {
            S4(c1,0,-c1+c2,c4,-c4+c6-1,ny-1) ;
          }
        }
      }
      if (c1 == c3) {
        for (c4=max(max(0,32*c3),32*c2-ny+32);c4<=min(min(32*c3+30,tmax-1),32*c2-1);c4++) {
          for (c5=32*c2;c5<=32*c2+31;c5++) {
            S1(c1,-c1+c2,c4,-c4+c5) ;
            S3(c1,0,-c1+c2,c4,0,-c4+c5) ;
            for (c6=c4+1;c6<=32*c3+31;c6++) {
              S2(c1,0,-c1+c2,c4,-c4+c6,-c4+c5) ;
              S3(c1,0,-c1+c2,c4,-c4+c6,-c4+c5) ;
              S4(c1,0,-c1+c2,c4,-c4+c6-1,-c4+c5-1) ;
            }
          }
        }
      }
      if (c1 == c3) {
        for (c4=max(max(32*c2,0),32*c3);c4<=min(min(32*c3+30,32*c2+30),tmax-1);c4++) {
          S1(c1,-c1+c2,c4,0) ;
          for (c6=c4+1;c6<=32*c3+31;c6++) {
            S2(c1,0,-c1+c2,c4,-c4+c6,0) ;
          }
          for (c5=c4+1;c5<=32*c2+31;c5++) {
            S1(c1,-c1+c2,c4,-c4+c5) ;
            S3(c1,0,-c1+c2,c4,0,-c4+c5) ;
            for (c6=c4+1;c6<=32*c3+31;c6++) {
              S2(c1,0,-c1+c2,c4,-c4+c6,-c4+c5) ;
              S3(c1,0,-c1+c2,c4,-c4+c6,-c4+c5) ;
              S4(c1,0,-c1+c2,c4,-c4+c6-1,-c4+c5-1) ;
            }
          }
        }
      }
      for (c4=max(max(max(32*c1,32*c3-nx+1),0),32*c2-ny+1);c4<=min(min(min(32*c3-nx+31,32*c2-ny+31),32*c1+31),tmax-1);c4++) {
        for (c5=32*c2;c5<=c4+ny-1;c5++) {
          for (c6=32*c3;c6<=c4+nx-1;c6++) {
            S2(c1,-c1+c3,-c1+c2,c4,-c4+c6,-c4+c5) ;
            S3(c1,-c1+c3,-c1+c2,c4,-c4+c6,-c4+c5) ;
            S4(c1,-c1+c3,-c1+c2,c4,-c4+c6-1,-c4+c5-1) ;
          }
          S4(c1,-c1+c3,-c1+c2,c4,nx-1,-c4+c5-1) ;
        }
        for (c6=32*c3;c6<=c4+nx;c6++) {
          S4(c1,-c1+c3,-c1+c2,c4,-c4+c6-1,ny-1) ;
        }
      }
      for (c4=max(max(max(0,32*c1),32*c3-nx+1),32*c2-ny+32);c4<=min(min(min(32*c1+31,tmax-1),32*c2-1),32*c3-nx+31);c4++) {
        for (c5=32*c2;c5<=32*c2+31;c5++) {
          for (c6=32*c3;c6<=c4+nx-1;c6++) {
            S2(c1,-c1+c3,-c1+c2,c4,-c4+c6,-c4+c5) ;
            S3(c1,-c1+c3,-c1+c2,c4,-c4+c6,-c4+c5) ;
            S4(c1,-c1+c3,-c1+c2,c4,-c4+c6-1,-c4+c5-1) ;
          }
          S4(c1,-c1+c3,-c1+c2,c4,nx-1,-c4+c5-1) ;
        }
      }
      for (c4=max(max(max(32*c3-nx+32,32*c1),0),32*c2-ny+1);c4<=min(min(min(32*c2-ny+31,32*c3-1),32*c1+31),tmax-1);c4++) {
        for (c5=32*c2;c5<=c4+ny-1;c5++) {
          for (c6=32*c3;c6<=32*c3+31;c6++) {
            S2(c1,-c1+c3,-c1+c2,c4,-c4+c6,-c4+c5) ;
            S3(c1,-c1+c3,-c1+c2,c4,-c4+c6,-c4+c5) ;
            S4(c1,-c1+c3,-c1+c2,c4,-c4+c6-1,-c4+c5-1) ;
          }
        }
        for (c6=32*c3;c6<=32*c3+31;c6++) {
          S4(c1,-c1+c3,-c1+c2,c4,-c4+c6-1,ny-1) ;
        }
      }
      for (c4=max(max(max(32*c2,0),32*c1),32*c3-nx+1);c4<=min(min(min(32*c1+31,32*c2+30),tmax-1),32*c3-nx+31);c4++) {
        for (c6=32*c3;c6<=c4+nx-1;c6++) {
          S2(c1,-c1+c3,-c1+c2,c4,-c4+c6,0) ;
        }
        for (c5=c4+1;c5<=32*c2+31;c5++) {
          for (c6=32*c3;c6<=c4+nx-1;c6++) {
            S2(c1,-c1+c3,-c1+c2,c4,-c4+c6,-c4+c5) ;
            S3(c1,-c1+c3,-c1+c2,c4,-c4+c6,-c4+c5) ;
            S4(c1,-c1+c3,-c1+c2,c4,-c4+c6-1,-c4+c5-1) ;
          }
          S4(c1,-c1+c3,-c1+c2,c4,nx-1,-c4+c5-1) ;
        }
      }
      for (c4=max(max(max(32*c1,0),32*c3-nx+32),32*c2-ny+32);c4<=min(min(min(32*c3-1,tmax-1),32*c1+31),32*c2-1);c4++) {
/*@ begin Loop(
transform UnrollJam(ufactor=8)
        for (c5=32*c2;c5<=32*c2+31;c5++) 
transform Unroll(ufactor=8)
          for (c6=32*c3;c6<=32*c3+31;c6++) 
{
            S2(c1,-c1+c3,-c1+c2,c4,-c4+c6,-c4+c5) ;
            S3(c1,-c1+c3,-c1+c2,c4,-c4+c6,-c4+c5) ;
            S4(c1,-c1+c3,-c1+c2,c4,-c4+c6-1,-c4+c5-1) ;
}
) @*/{ 

  for (c5 = 32 * c2; c5 <= 32 * c2 + 31 - 7; c5 = c5 + 8)     { 

      for (c6 = 32 * c3; c6 <= 32 * c3 + 31 - 7; c6 = c6 + 8)         { 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + c5); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + c5); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6 - 1, -c4 + c5 - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 1), -c4 + c5); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 1), -c4 + c5); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 1) - 1, -c4 + c5 - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 2), -c4 + c5); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 2), -c4 + c5); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 2) - 1, -c4 + c5 - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 3), -c4 + c5); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 3), -c4 + c5); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 3) - 1, -c4 + c5 - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 4), -c4 + c5); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 4), -c4 + c5); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 4) - 1, -c4 + c5 - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 5), -c4 + c5); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 5), -c4 + c5); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 5) - 1, -c4 + c5 - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 6), -c4 + c5); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 6), -c4 + c5); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 6) - 1, -c4 + c5 - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 7), -c4 + c5); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 7), -c4 + c5); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 7) - 1, -c4 + c5 - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + (c5 + 1)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + (c5 + 1)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6 - 1, -c4 + (c5 + 1) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 1), -c4 + (c5 + 1)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 1), -c4 + (c5 + 1)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 1) - 1, -c4 + (c5 + 1) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 2), -c4 + (c5 + 1)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 2), -c4 + (c5 + 1)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 2) - 1, -c4 + (c5 + 1) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 3), -c4 + (c5 + 1)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 3), -c4 + (c5 + 1)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 3) - 1, -c4 + (c5 + 1) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 4), -c4 + (c5 + 1)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 4), -c4 + (c5 + 1)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 4) - 1, -c4 + (c5 + 1) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 5), -c4 + (c5 + 1)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 5), -c4 + (c5 + 1)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 5) - 1, -c4 + (c5 + 1) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 6), -c4 + (c5 + 1)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 6), -c4 + (c5 + 1)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 6) - 1, -c4 + (c5 + 1) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 7), -c4 + (c5 + 1)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 7), -c4 + (c5 + 1)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 7) - 1, -c4 + (c5 + 1) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + (c5 + 2)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + (c5 + 2)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6 - 1, -c4 + (c5 + 2) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 1), -c4 + (c5 + 2)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 1), -c4 + (c5 + 2)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 1) - 1, -c4 + (c5 + 2) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 2), -c4 + (c5 + 2)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 2), -c4 + (c5 + 2)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 2) - 1, -c4 + (c5 + 2) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 3), -c4 + (c5 + 2)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 3), -c4 + (c5 + 2)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 3) - 1, -c4 + (c5 + 2) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 4), -c4 + (c5 + 2)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 4), -c4 + (c5 + 2)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 4) - 1, -c4 + (c5 + 2) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 5), -c4 + (c5 + 2)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 5), -c4 + (c5 + 2)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 5) - 1, -c4 + (c5 + 2) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 6), -c4 + (c5 + 2)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 6), -c4 + (c5 + 2)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 6) - 1, -c4 + (c5 + 2) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 7), -c4 + (c5 + 2)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 7), -c4 + (c5 + 2)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 7) - 1, -c4 + (c5 + 2) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + (c5 + 3)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + (c5 + 3)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6 - 1, -c4 + (c5 + 3) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 1), -c4 + (c5 + 3)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 1), -c4 + (c5 + 3)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 1) - 1, -c4 + (c5 + 3) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 2), -c4 + (c5 + 3)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 2), -c4 + (c5 + 3)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 2) - 1, -c4 + (c5 + 3) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 3), -c4 + (c5 + 3)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 3), -c4 + (c5 + 3)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 3) - 1, -c4 + (c5 + 3) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 4), -c4 + (c5 + 3)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 4), -c4 + (c5 + 3)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 4) - 1, -c4 + (c5 + 3) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 5), -c4 + (c5 + 3)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 5), -c4 + (c5 + 3)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 5) - 1, -c4 + (c5 + 3) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 6), -c4 + (c5 + 3)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 6), -c4 + (c5 + 3)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 6) - 1, -c4 + (c5 + 3) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 7), -c4 + (c5 + 3)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 7), -c4 + (c5 + 3)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 7) - 1, -c4 + (c5 + 3) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + (c5 + 4)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + (c5 + 4)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6 - 1, -c4 + (c5 + 4) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 1), -c4 + (c5 + 4)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 1), -c4 + (c5 + 4)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 1) - 1, -c4 + (c5 + 4) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 2), -c4 + (c5 + 4)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 2), -c4 + (c5 + 4)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 2) - 1, -c4 + (c5 + 4) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 3), -c4 + (c5 + 4)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 3), -c4 + (c5 + 4)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 3) - 1, -c4 + (c5 + 4) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 4), -c4 + (c5 + 4)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 4), -c4 + (c5 + 4)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 4) - 1, -c4 + (c5 + 4) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 5), -c4 + (c5 + 4)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 5), -c4 + (c5 + 4)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 5) - 1, -c4 + (c5 + 4) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 6), -c4 + (c5 + 4)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 6), -c4 + (c5 + 4)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 6) - 1, -c4 + (c5 + 4) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 7), -c4 + (c5 + 4)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 7), -c4 + (c5 + 4)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 7) - 1, -c4 + (c5 + 4) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + (c5 + 5)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + (c5 + 5)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6 - 1, -c4 + (c5 + 5) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 1), -c4 + (c5 + 5)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 1), -c4 + (c5 + 5)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 1) - 1, -c4 + (c5 + 5) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 2), -c4 + (c5 + 5)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 2), -c4 + (c5 + 5)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 2) - 1, -c4 + (c5 + 5) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 3), -c4 + (c5 + 5)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 3), -c4 + (c5 + 5)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 3) - 1, -c4 + (c5 + 5) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 4), -c4 + (c5 + 5)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 4), -c4 + (c5 + 5)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 4) - 1, -c4 + (c5 + 5) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 5), -c4 + (c5 + 5)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 5), -c4 + (c5 + 5)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 5) - 1, -c4 + (c5 + 5) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 6), -c4 + (c5 + 5)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 6), -c4 + (c5 + 5)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 6) - 1, -c4 + (c5 + 5) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 7), -c4 + (c5 + 5)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 7), -c4 + (c5 + 5)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 7) - 1, -c4 + (c5 + 5) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + (c5 + 6)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + (c5 + 6)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6 - 1, -c4 + (c5 + 6) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 1), -c4 + (c5 + 6)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 1), -c4 + (c5 + 6)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 1) - 1, -c4 + (c5 + 6) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 2), -c4 + (c5 + 6)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 2), -c4 + (c5 + 6)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 2) - 1, -c4 + (c5 + 6) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 3), -c4 + (c5 + 6)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 3), -c4 + (c5 + 6)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 3) - 1, -c4 + (c5 + 6) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 4), -c4 + (c5 + 6)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 4), -c4 + (c5 + 6)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 4) - 1, -c4 + (c5 + 6) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 5), -c4 + (c5 + 6)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 5), -c4 + (c5 + 6)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 5) - 1, -c4 + (c5 + 6) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 6), -c4 + (c5 + 6)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 6), -c4 + (c5 + 6)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 6) - 1, -c4 + (c5 + 6) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 7), -c4 + (c5 + 6)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 7), -c4 + (c5 + 6)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 7) - 1, -c4 + (c5 + 6) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + (c5 + 7)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + (c5 + 7)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6 - 1, -c4 + (c5 + 7) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 1), -c4 + (c5 + 7)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 1), -c4 + (c5 + 7)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 1) - 1, -c4 + (c5 + 7) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 2), -c4 + (c5 + 7)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 2), -c4 + (c5 + 7)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 2) - 1, -c4 + (c5 + 7) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 3), -c4 + (c5 + 7)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 3), -c4 + (c5 + 7)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 3) - 1, -c4 + (c5 + 7) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 4), -c4 + (c5 + 7)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 4), -c4 + (c5 + 7)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 4) - 1, -c4 + (c5 + 7) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 5), -c4 + (c5 + 7)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 5), -c4 + (c5 + 7)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 5) - 1, -c4 + (c5 + 7) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 6), -c4 + (c5 + 7)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 6), -c4 + (c5 + 7)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 6) - 1, -c4 + (c5 + 7) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 7), -c4 + (c5 + 7)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 7), -c4 + (c5 + 7)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 7) - 1, -c4 + (c5 + 7) - 1); 
        } 

      for (; c6 <= 32 * c3 + 31; c6 = c6 + 1)         { 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + c5); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + c5); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6 - 1, -c4 + c5 - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + (c5 + 1)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + (c5 + 1)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6 - 1, -c4 + (c5 + 1) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + (c5 + 2)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + (c5 + 2)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6 - 1, -c4 + (c5 + 2) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + (c5 + 3)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + (c5 + 3)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6 - 1, -c4 + (c5 + 3) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + (c5 + 4)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + (c5 + 4)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6 - 1, -c4 + (c5 + 4) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + (c5 + 5)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + (c5 + 5)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6 - 1, -c4 + (c5 + 5) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + (c5 + 6)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + (c5 + 6)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6 - 1, -c4 + (c5 + 6) - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + (c5 + 7)); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + (c5 + 7)); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6 - 1, -c4 + (c5 + 7) - 1); 
        } 
    } 

  for (; c5 <= 32 * c2 + 31; c5 = c5 + 1)     { 

      for (c6 = 32 * c3; c6 <= 32 * c3 + 31 - 7; c6 = c6 + 8)         { 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + c5); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + c5); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6 - 1, -c4 + c5 - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 1), -c4 + c5); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 1), -c4 + c5); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 1) - 1, -c4 + c5 - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 2), -c4 + c5); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 2), -c4 + c5); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 2) - 1, -c4 + c5 - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 3), -c4 + c5); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 3), -c4 + c5); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 3) - 1, -c4 + c5 - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 4), -c4 + c5); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 4), -c4 + c5); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 4) - 1, -c4 + c5 - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 5), -c4 + c5); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 5), -c4 + c5); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 5) - 1, -c4 + c5 - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 6), -c4 + c5); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 6), -c4 + c5); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 6) - 1, -c4 + c5 - 1); 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 7), -c4 + c5); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 7), -c4 + c5); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + (c6 + 7) - 1, -c4 + c5 - 1); 
        } 

      for (; c6 <= 32 * c3 + 31; c6 = c6 + 1)         { 
          S2(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + c5); 
          S3(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6, -c4 + c5); 
          S4(c1, -c1 + c3, -c1 + c2, c4, -c4 + c6 - 1, -c4 + c5 - 1); 
        } 
    } 
} 
/*@ end @*/
      }
      for (c4=max(max(max(32*c2,32*c3-nx+32),32*c1),0);c4<=min(min(min(32*c3-1,tmax-1),32*c1+31),32*c2+30);c4++) {
        for (c6=32*c3;c6<=32*c3+31;c6++) {
          S2(c1,-c1+c3,-c1+c2,c4,-c4+c6,0) ;
        }
        for (c5=c4+1;c5<=32*c2+31;c5++) {
          for (c6=32*c3;c6<=32*c3+31;c6++) {
            S2(c1,-c1+c3,-c1+c2,c4,-c4+c6,-c4+c5) ;
            S3(c1,-c1+c3,-c1+c2,c4,-c4+c6,-c4+c5) ;
            S4(c1,-c1+c3,-c1+c2,c4,-c4+c6-1,-c4+c5-1) ;
          }
        }
      }
      if ((c1 == c3) && (c2 <= min(floord(32*c3-1,32),floord(tmax-32,32)))) {
        S1(c1,-c1+c2,32*c2+31,0) ;
        for (c6=32*c2+32;c6<=32*c3+31;c6++) {
          S2(c1,0,-c1+c2,32*c2+31,-32*c2+c6-31,0) ;
        }
      }
      if ((-c1 == -c3) && (c1 >= ceild(32*c2-31,32)) && (c1 <= min(floord(tmax-32,32),floord(32*c2-1,32)))) {
        S1(c1,-c1+c2,32*c1+31,0) ;
        for (c5=32*c1+32;c5<=32*c2+31;c5++) {
          S1(c1,-c1+c2,32*c1+31,-32*c1+c5-31) ;
          S3(c1,0,-c1+c2,32*c1+31,0,-32*c1+c5-31) ;
        }
      }
      if ((-c1 == -c3) && (c1 <= min(floord(tmax-32,32),c2-1))) {
        for (c5=32*c2;c5<=min(32*c2+31,32*c1+ny+30);c5++) {
          S1(c1,-c1+c2,32*c1+31,-32*c1+c5-31) ;
          S3(c1,0,-c1+c2,32*c1+31,0,-32*c1+c5-31) ;
        }
      }
      if ((-c1 == -c2) && (-c1 == -c3) && (c1 <= floord(tmax-32,32))) {
        S1(c1,0,32*c1+31,0) ;
      }
      if ((c1 >= c2) && (c2 <= min(c3-1,floord(tmax-32,32)))) {
        for (c6=32*c3;c6<=min(32*c2+nx+30,32*c3+31);c6++) {
          S2(c1,-c1+c3,-c1+c2,32*c2+31,-32*c2+c6-31,0) ;
        }
      }
    }
  }
}
/* End of CLooG code */




    annot_t_end = rtclock();
    annot_t_total += annot_t_end - annot_t_start;
  }
  
  annot_t_total = annot_t_total / REPS;

#ifndef TEST
  printf("%f\n", annot_t_total);
#else
  {
    int i,j;
    for (i=0; i<nx; i++) {
      for (j=0; j<ny; j++)  {
	if (j%100==0)
          printf("\n");
        printf("%f ",hz[i][j]);
      }
      printf("\n");
    }
  }
#endif


  return ((int) hz[0][0]); 

}
                                    
