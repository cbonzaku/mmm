#include <stdlib.h>
#include <stdio.h>


int **A,**B,**C;




int caculElemen(int i,int j,int n){
      int s=0;
    for (int k = 0; k < n; k++)
    {
      
        s=s+ A[i][k]*B[k][j];
    }
    return   s;
} 



void sequenciel(int n){
    for(int i=0;i<n;i++){
        
        for (int j = 0; j < n; j++)
        {
            
          C[i][j]=caculElemen(i,j,n);
        }
        

    }
}




