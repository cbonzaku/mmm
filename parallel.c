#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>

int **A,**B,**C,n=2,p=2,nbr=2;






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
   
int is =id*nbr;
int ie = is + nbr;

  
        for ( int i= is; i < ie; i++)
        {
            for (int j = 0; j < n; j++)
            {
                
                 C[i][j]=caculElement(i,j);
            }
            
            

        }
        

    

     pthread_exit(NULL);

}



                //2eme partie du home work


void *paral2(void *tid){

    
        int id=*(int *)(tid); 

        
        int d1=n/2;//}
                   //} block size
        int d2=n/(p/2);//}

        int is=(id%(n))*d1;
        int js =d2*id;

      
        int ie=is+d1-1,je=js+d2-1;
        int s=0;

   

  
        for (int i=is; i < ie; i++)
        {
            for (int j = js; j < je; i++)
            { 
                s=0;
                for (int k = js; k < je; k++)
                {
      
                    s=s+ A[i][k]*B[k][j];
                }
                C[i][j]=s;
                
            }
            
           
            
            

        }
        

    

     pthread_exit(NULL);

}

