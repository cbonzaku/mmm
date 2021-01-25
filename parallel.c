#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

int **A,**B,**C,n=2;






int caculElement(int i,int j){
      int s=0;
    for (int k = 0; k < n; k++)
    {
      
        s=s+ A[i][k]*B[k][j];
    }
    return   s;
} 



// work for a thread
void *paral(void *tid){
    
int id=*(int *)(tid); 
   

  
        for ( int i=0; i < n; i++)
        {
            
           
            C[id][i]=caculElement(id,i);
            

        }
        

    

     pthread_exit(NULL);

}

