
/*@ begin PerfTuning (        
  def build
  {
    #arg command = 'icc';
    arg build_command = 'icc -fast -openmp -I/usr/local/icc/include -lm';
  }
   
  def performance_counter         
  {
    arg method = 'basic timer';
    arg repetitions = 2;
  }
  
  def performance_params
  {
    param T1_I[] = [1,16,32,64,128,256,512,1024,2048];
    param T1_J[] = [1,16,32,64,128,256,512,1024,2048];
    param T2_I[] = [1,16,32,64,128,256,512,1024,2048];
    param T2_J[] = [1,16,32,64,128,256,512,1024,2048];

    param ACOPY_A[] = [True,False];

    param U_I[] = range(1,31);
    param U_J[] = range(1,31);

    param SCREP[] = [True,False];
    param VEC[] = [True,False];
    param OMP[] = [True,False];

    param PERMUTS[] = [

		       (['iii'],['jjj'],['ii'],['jj'],'i','j'),
		       (['jjj'],['iii'],['jj'],['ii'],'i','j'),

		       (['iii'],['jjj'],['ii'],['jj'],'j','i'),
		       (['jjj'],['iii'],['jj'],['ii'],'j','i'),

		       ];

    constraint tileI = ((T2_I == 1) or (T2_I % T1_I == 0));
    constraint tileJ = ((T2_J == 1) or (T2_J % T1_J == 0));

    constraint reg_capacity = (2*U_I*U_J + 2*U_I + 2*U_J <= 130);

    constraint copy_limitA = ((not ACOPY_A) or (ACOPY_A and 
                              (T1_I if T1_I>1 else T2_I)*(T1_J if T1_J>1 else T2_J) <= 512*512));
  }

  def search
  {
    arg algorithm = 'Randomsearch';
#    arg algorithm = 'Exhaustive';
#    arg time_limit = 5;
    arg total_runs = 5000;
  }
  
  let SIZE = 10000;
  
  def input_params
  {
    param MSIZE = SIZE;
    param NSIZE = SIZE;
  
  }

  def input_vars
  {
    decl int M = MSIZE;
    decl int N = NSIZE;
    decl static double a[M][N] = random;
    decl static double y_1[N] = random;
    decl static double y_2[M] = random;
    decl static double x1[M] = 0;
    decl static double x2[N] = 0;
  }

            
) @*/

int i, j;
int ii, jj;
int iii, jjj;

/*@ begin Loop(
  transform Composite(
    tile = [('i',T1_I,'ii'),('j',T1_J,'jj'),(('ii','i'),T2_I,'iii'),(('jj','j'),T2_J,'jjj')],
    permut = [PERMUTS],
    arrcopy = [(ACOPY_A,'a[i][j]',[(T1_I if T1_I>1 else T2_I),(T1_J if T1_J>1 else T2_J)],'_copy')],
    unrolljam = [('j',U_J),('i',U_I)],
    scalarreplace = (SCREP, 'double', 'scv_'),
    vector = (VEC, ['ivdep','vector always']),
    openmp = (OMP, 'omp parallel for private(iii,jjj,ii,jj,i,j,a_copy)')
  )

for (i=0;i<=N-1;i++)
  for (j=0;j<=N-1;j++) 
  { 
    x1[i]=x1[i]+a[i][j]*y_1[j]; 
    x2[j]=x2[j]+a[i][j]*y_2[i]; 
  } 

) @*/

for (i=0;i<=N-1;i++)
  for (j=0;j<=N-1;j++) { 
    x1[i]=x1[i]+a[i][j]*y_1[j]; 
    x2[j]=x2[j]+a[i][j]*y_2[i]; 
  } 

/*@ end @*/
/*@ end @*/


