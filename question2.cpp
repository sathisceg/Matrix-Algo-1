#include <bits/stdc++.h>


using namespace std;



void display_matrix(double **A,int N)
{

	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{	
			printf("%lf ",A[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}



int main()
{


	int N;

	scanf("%d",&N);

	int i,k,j;

	double **A;

	A = (double**)malloc(sizeof(double*)*N);

	for(i=0;i<N;i++)
	{
		A[i]=(double *)malloc(sizeof(double)*N);
	}



	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%lf",&A[i][j]);
		}
	}



	double *B;

	B=(double*)malloc(sizeof(double)*N);

	for(i=0;i<N;i++)
	{
			scanf("%lf",&B[i]);
	}
	
	

	for(k=0;k<N-1;k++)
	{
		
		for(i=k+1;i<N;i++)
		{

			
			A[i][k]/= A[k][k];	
		}



		for(i=k+1;i<N;i++)
		{
			for(j=k+1;j<N;j++)
			{
				A[i][j]-= A[i][k]*A[k][j];	
			}
		}

	}


	


	display_matrix(A,N);




	double *Y;
	Y=(double*)malloc(sizeof(double)*N);

	double *X;
	X=(double*)malloc(sizeof(double)*N);


	memset(Y,0,N*sizeof(double));

	memset(X,0,N*sizeof(double));

	double L[N][N] ={0};





	for(i=0;i<N;i++)
	{
		for (j=0; j <= i; j++)
		{
			if(i==j)
			{
				//printf("1");
				L[i][j]=1;
			}
			else
			{
				//printf("%lf ",A[i][j]);
				L[i][j]=A[i][j];
			}	
		}		//printf("\n");
	}



  	for(i=0;i<N;i++)
  	{
  		Y[i]=B[i];

  		//printf("%lf\n",Y[i]);
  		for(j=0;j<i;j++)
  		{
  			Y[i]-=L[i][j]*Y[j];
  		}
  		Y[i]/=L[i][i];

  		//printf("%lf\n",Y[i]);
	}

	//printf("\n\n");

  	// for(i=0;i<N;i++)
  	// {
  	// 	printf("%lf\n",Y[i]);
  	// }


  	//printf("\n\n");
  	for(i=N-1;i>=0;i--)
  	{
  		X[i]=Y[i];

  		//printf("%lf\n",Y[i]);
  		for(j=N-1;j>i;j--)
  		{
  			X[i]-=A[i][j]*X[j];
  		}
  		X[i]/=A[i][i];

  		//printf("%lf\n",X[i]);
	}

	for(i=0;i<N;i++)
  	{
  		printf("%lf\n",X[i]);
  	}
  

	return 0;
}


//input	
//3 1 1 -1 1 -2 3 2 3 1 4 -6 7

