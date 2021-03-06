#include <stdio.h> 
#include <string.h>  
int P; 
int R; 
 
int total = 0; 

int safe[10];
int sz = 0;
int is_available(int process_number, int allocated[][R], 
                  int max[][R], int need[][R], int available[]) 
{ int i;
  
    int flag = 1; 
    for (int i = 0; i < R; i++) { 
  
        if (need[process_number][i] > available[i]) 
            flag = 0; 
    } 
  
    return flag; 
} 
 
void safe_sequence(int marked[], int allocated[][R], int max[][R], 
                   int need[][R], int available[]) 
{ 
  int i;
    for (i = 0; i < P; i++) { 
  
        if (!marked[i] && is_available(i, allocated, max, need, available)) { 
  
            marked[i] = 1; 
  
            
            for (int j = 0; j < R; j++) 
                available[j] += allocated[i][j]; 
  
	safe[sz] = i;
	sz++;
          
          safe_sequence(marked, allocated, max, need, available); 
     
	sz--;
	safe[sz] = 0; 
  
            marked[i] = 0; 
  
   
            for (int j = 0; j < R; j++) 
                available[j] -= allocated[i][j]; 
        } 
    } 

    if (sz == P) { 
  
        total++; 
        for (int i = 0; i < P; i++) { 
  
            printf(" P%d", safe[i]);
	   if(i !=(P-1))
		  printf("-->"); 
        } 
  
        printf("\n");
    } 
} 
  
int main()

{ 

	printf("\nEnter number of processes---: "); 
	scanf("%d", &P);
	printf("\nEnter number of resource----: ");
	scanf("%d",&R);
	int available[R];
	int allocated[P][R];
	int max[P][R];
	int i,j;
	printf("\nEnter available matrix-------\n");
	for (i=0;i<R;i++)
	{
		scanf("%d", &available[i]);
	}
	printf("\nEnter allocated matrix-------\n");
	for (i=0;i<P;i++)
		for (j=0;j<R;j++)
			scanf("%d", &allocated[i][j]);
	printf("\nEnter max matrix-------------\n");
	for (i=0;i<P;i++)
		for (j=0;j<R;j++)
			scanf("%d", &max[i][j]);
   
  
  
    int marked[P]; 
	for(i= 0 ; i < P; i++)
	marked[i] = 0;
  
    int need[P][R]; 
    for (int i = 0; i < P; i++) 
        for (int j = 0; j < R; j++) 
            need[i][j] = max[i][j] - allocated[i][j]; 
  printf("safe sequence if exit:\n\n");
    safe_sequence(marked, allocated, max, need, available); 
  if (total == 0)
	printf("\nSystem is unsafe and lead to DEADLOCK:\n");
else{
       
        printf("\nThere are total %d  safe-sequences\n", total ); 
	}

    return 0;
}
