#include <bits/stdc++.h>


using namespace std;


int main()
{



	 int N=4;
	 
	 int A[N-1][N] = { { 0, 1, 1,1 },
                       { 1,1,1,1 },
                       { 1,1,1,0},
                    };

   int B[N-1][N] = { { 0, 1, 1,1 },
                       { 1,1,1,1 },
                       { 1,1,1,0},
                    };




   int C[N][N] = {0};

   int i,j,k;
   int ti,tj;
   int p=1,q=1;

   for(i=0;i<N;i++)
   {
   		for(j=0;j<N;j++)
   		{
   			 for(k=0;k<N;k++)
   			 {
   	

   					 int tk2 = k-j+q+1;
   					 int tk1 = i-k+q+1;
   					 // ti--;
   					 tj=j;

   					 if(tk2-1<0||tk1-1<0)
   					 {
   					 	 // printf("0 ");		
   					 	 continue;			
   					 }

   					  if(tk2-1>N||tk1-1>N)
   					 {
   					 		// printf("0 ");
   					 		continue;
   					 }

   					 // 	if(i==0&&(j==2||j==3))
   					 // 	{
   					 //   printf("%d  %d/",tk1-1,k);
   					 //   printf("%d  %d",tk2-1,j);
   					 //   printf("|");
   					 // 	printf("hi ");
   					 // }
   					 // if(A[tk1-1][k]!=1||B[tk2-1][j]!=1)
   					 // {
   					 // 		printf("1) %d %d %d /",tk1-1,k,A[tk1-1][k]);
   					 // 		printf("2) %d %d %d ",tk2-1,j,B[tk2-1][j]);
   					 // 		printf("\n");
   					 // }

   					 // printf("%d %d\n",tk1-1,tk2-1 );
   					 if((tk1-1>=0&&tk1-1<N)&&(tk2-1>=0&&tk2-1<N))
   					 {
   					 		 C[i][j]+=(A[tk1-1][k]*B[tk2-1][j]);
   					 }
   				  

   			 }
   			
   		}

   		printf("\n");
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
