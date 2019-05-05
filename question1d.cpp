
#include <bits/stdc++.h>

using namespace std;


//Compressed Sparse Row (CSR) Format

int main()
{


	int N=6;
	int nz=12;

	int val1[nz+1] ={0,1,2,3,4,5,6,7,8,9,10,11,12} ;
	int col1_indices[nz+1] ={0,1,4,1,2,4,1,3,4,5,3,4,5};
	int row1_pointers[N+1] = {0,1,3,6,10,12,13};

	int val2[nz+1] ={0,1,2,3,4,5,6,7,8,9,10,11,12} ;
	int col2_indices[nz+1] ={0,1,4,1,2,4,1,3,4,5,3,4,5};
	int row2_pointers[N+1] = {0,1,3,6,10,12,13};
	int i,j,k,l;

	// int N;
	// scanf("%d",&N);
	// int nz;
	// scanf("%d",&nz);

	// N=N+1;
	// nz=nz+1;

	// int val1[nz+1];
	// int col1_indices[nz+1];
	// int row1_pointers[N+1];

	// int val2[nz+1];
	// int col2_indices[nz+1];
	// int row2_pointers[N+1];
	// int i,j,k,l;
	// int temp;

	// val1[0]=val2[0]=col1_indices[0]=col2_indices[0]=row1_pointers[0]=row2_pointers[0]=0;
  
 //  	for(i=1;i<nz+1;i++)
 //  	{
 //  		scanf("%d",&val1[i]);
 //  		val2[i]=val1[i];
 //  	}

 //  	for(i=1;i<nz+1;i++)
 //  	{
 //  		scanf("%d",&col1_indices[i]);
 //  		col2_indices[i]=col1_indices[i];
 //  	}

 //  	for(i=1;i<N+1;i++)
 //  	{
 //  		scanf("%d",&row1_pointers[i]);
 //  		row2_pointers[i]=row1_pointers[i];
 //  	}
	


	// for(i=1;i<nz+1;i++)
 //  	{
 //  		printf("%d\n",val1[i]);
 //  	}

  	// for(i=1;i<nz+1;i++)
  	// {
  	// 	printf("%d\n",col1_indices[i]);
  	// }

	int result[N][N];

	memset(result,0,sizeof(result[0][0])*N*N);

	for(i=1;i<N+1;i++)
	{

		for(j=row1_pointers[i];j<row1_pointers[i+1];j++)
		{

				for(k=row2_pointers[col1_indices[j]];k<row2_pointers[col1_indices[j]+1];k++)
				{
					result[i][col2_indices[k]]+=val1[j]*val2[k];
				
				}

		}

		// printf("\n");
	}




	for(i=1;i<N;i++)
	{
		for(j=1;j<N;j++)
		{
			cout<<result[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}

// 6
// 12 
// 0 1 2 3 4 5 6 7 8 9 10 11 12
// 0 1 4 1 2 4 1 3 4 5 3 4 5
// 0 1 3 6 10 12 13