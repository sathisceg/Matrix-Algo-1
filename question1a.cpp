#include <bits/stdc++.h>


using namespace std;


int main()
{



	 int N=5;


	 
	 // int A[N][N] = { { 1, 1, 1,1 ,1},
  //                      { 1,1,1,1,1,1 },
  //                       { 1,1,1,1,1,1 },
  //                        { 1,1,1,1,1,1 },
  //                         { 1,1,1,1,1,1 },
  //                   };




  // int B[N][N] = { { 1, 1, 1,1 ,1},
  //                      { 1,1,1,1,1,1 },
  //                       { 1,1,1,1,1,1 },
  //                        { 1,1,1,1,1,1 },
  //                         { 1,1,1,1,1,1 },
  //                   };


  int A[N][N];
  int B[N][N];

   srand(time(0));
  

   int C[N][N] = {0};

   int i,j,k;
   int ti,tj;
   int p=1,q=1;




   for(i=0;i<N;i++)
   {
   		for (j = 0; j < N; j++)
   		{
   			A[i][j]=(rand()%10);
   			B[i][j]=A[i][j];
   		}
   }

   for(i=0;i<N;i++)
   {
   		for(j=0;j<N;j++)
   		{
             C[i][j]=0;
   			 for(k=0;k<N;k++)
   			 {
   	

   					C[i][j]+=A[i][k]*B[k][j];

   			 }
   			
   		}

   		// printf("\n");
   }


  for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			
			printf("%d ",C[i][j]);
		}

		printf("\n");
	}









   

	return 0;
}













