/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define x 99999; //indicates that a message cannot be sent directly from city i to city j


void Empire()
{
	int n = 0;//number of cities
	printf("Enter number of  cities\n");
	(void)scanf("%d", &n);// gets number of cities
	int A[n][n];//adjency matrix

	if(n<=100)
	{
    /*initialize the adjacency matrix*/
    int u, v;
    for (u = 0; u < n; u++) {
        for (v = 0; v < n; v++) {
            A[u][v] = x;
        }
    }
	
	// fill adjacency matrix
	int i,j;
	    for (i = 0; i < n; i++) 
		{
			
        	for (j = 0; j <= i; j++) {
            	if(i == j) 
				{
                	A[i][j] = 0;
            	} 
				else 
				{
                	(void)scanf("%*c%d", &A[i][j]);//the * here means read the data but don't assign it to a variable in the argument list
                	A[j][i] = A[i][j];
            	}
        	}
    	} 
    	
    	
    //Calcile minimum time from the capital
    int k,l;
    for (k = 0; k < n; k++)
	{
		for (l = 0; l < n; l++)
		{
			/*here we will compare the time spent to go from the capital to a city for example l with the time spent to
			go from the city l to the city k plus the 
			time spent to go from the capital to the city k, if it is smaller we change it*/
			if(A[l][0] > A[l][k] + A[k][0])
			{
				A[l][0]=A[l][k] + A[k][0];
			}
		}
		
		
	}
	
	//get the minimum time, the result 
	int min=0;//the time it is received in the last city to get the message
	int m;
	for (m = 0; m < n; m++)
	{
		if(A[m][0] > min)//we compare the values on the first column of the matrix where we saved all the minimum time taken from the capitol to others cities
		{
			min = A[m][0];
		}
	}
	
	printf("the time it is received in the last city to get the message = %d ", min);
	}
	else{
		
	printf("number of cities must be under 100 \n");
	}
	
		
}


int main(int argc, char *argv[]) {
	Empire();
	return 0;
}
