#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#include<pthread.h>
#include "parallel.h"
#include "seq.h"



int **A,**B,**C;
double time1,time2;
int mode;


int main(int argc, char const *argv[])
{

    clock_t begin,end,begin1,end1;
     int n=3;
     int p=3;
     int para=0 ;
    
printf("\nentre la dimention de la matrice\t");
scanf("%d",&n);

   
      e: printf("\nentre le nombre de thread :\t");
       scanf("%d",&p);
       if((n%p!=0)){
           printf("\nerreur: la demention doit etre un multiple du nbr de thread \t");
           goto e;}
 
 
   // allocation memoire pour A,B et C
    A = (int **)malloc(n * sizeof(int *));
	    for (int i = 0; i < n; i++){
		A[i] = (int *)malloc(n * sizeof(int));}

    B = (int **)malloc(n * sizeof(int *));
	    for (int i = 0; i < n; i++){
		B[i] = (int *)malloc(n * sizeof(int));}

   C = (int **)malloc(n * sizeof(int *));
	    for (int i = 0; i < n; i++){
		C[i] = (int *)malloc(n * sizeof(int));}

    pthread_t threads[p];
   
    int rc,t=0,*id;
    
   
    
    // initialization de A et B
    srand(time(0));
   for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            A[i][j]=rand() %11;
            B[i][j]=rand() %11;

        }
        

    }
    
    
    //afichage de A
printf("\n \n \t \t A =\n");

    for (int i = 0; i < n; i++)
    {
          for (int j = 0; j < n; j++)
        {
            if(j==n-1){printf("\t%d\t\n",A[i][j]);}
            else
            {
            printf("\t%d\t",A[i][j]);
            }
            
            

        }
    }


//afichage de B
    printf("\n \n \t \t B =\n");

    for (int i = 0; i < n; i++)
    {
          for (int j = 0; j < n; j++)
        {
            if(j==n-1){printf("\t%d\t\n",B[i][j]);}
            else
            {
            printf("\t%d\t",B[i][j]);
        
            }
            
            

        }
    }


     
    
    
    id = (int *) malloc( sizeof(int) );
    begin=clock();
    
    // creating threads
     for(t=0; t<p; t++){
         
         *id=t;
       
       pthread_create(&threads[t], NULL, paral, (void *)id);
      
       

       
    }
     for (int i = 0; i < p; i++){
       pthread_join(threads[i], NULL);}
       end=clock();
       
    

    begin1=clock();
       sequenciel(n);
       end1=clock();
   
   printf("\n \n \t \t C =\n");
   

    


    printf("\nparallel time is :%f\n",((double) (end - begin)) / CLOCKS_PER_SEC);
    printf("\nseqenciel time is :%f\n",((double) (end1 - begin1)) / CLOCKS_PER_SEC);
    
    return 0;
}