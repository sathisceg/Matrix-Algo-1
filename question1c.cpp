#include <bits/stdc++.h>


using namespace std;

//Coordinate Storage Format (COO)
int main()
{


   //Static input
   // int N=12;

   // int row1_id[12]={5,3,3,2,1,1,4,2,3,2,3,4};
   // int col1_id[12]={5,5,3,4,1,4,4,1,1,2,4,3};
   // int val1[12]={12,9,7,5,1,2,11,3,6,4,8,10};
   // int row2_id[12]={5,3,3,2,1,1,4,2,3,2,3,4};
   // int col2_id[12]={5,5,3,4,1,4,4,1,1,2,4,3};
   // int val2[12]={12,9,7,5,1,2,11,3,6,4,8,10};

   srand(time(0));
   int N =rand();
   N=N%10;
   // cout<<N;
   // printf("\n");

   if(N<5)
   {
      N=N+10;
   }

   int row1_id[N];
   int col1_id[N];
   int val1[N];

   int row2_id[N];
   int col2_id[N];
   int val2[N];

   int i,j;

   int temp=0;
   int maxR=0,maxC=0;
   for(i=0;i<N;i++)
   {
         temp=(rand()%10);
         row1_id[i]=temp;
         
         if(maxR<temp)
         {
            maxR=temp;
         }

         temp=(rand()%10);
         row2_id[i]=temp;
         if(maxR<temp)
         {
            maxR=temp;
         }

         temp=(rand()%10);
         col1_id[i]=temp;
         col2_id[i]=temp;

         if(maxC<temp)
         {
            maxC=temp;
         }
         temp=(rand()%10);

         val1[i]=temp;
         val2[i]=temp;

   }


   // printf("%d %d\n",maxR,maxC);

   // for (i = 0; i < N; ++i)
   // {
   //    printf("%d %d %d|",row1_id[i],col1_id[i],val1[i] );
   //    printf("%d %d %d",row2_id[i],col2_id[i],val2[i] );

   //    printf("\n");
   // }



   int result[maxR][maxC];
   memset(result, 0, sizeof(result[0][0]) * maxR * maxC);

   for(i=0;i<N;i++)
   {
      
         int tc=col1_id[i];
         for(j=0;j<N;j++)
         {
            if(tc==row2_id[j])
            {
               result[row1_id[i]][col2_id[j]]+=val1[i]*val2[j];
            }
         }
         
   }

   for (i = 0; i < maxR; ++i)
   {
         for(j=0;j<maxC;j++)
         {
            cout<<result[i][j]<<" ";
         }

         cout<<endl;
   }

	return 0;
}













