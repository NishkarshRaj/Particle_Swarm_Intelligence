#include <stdio.h> 
#define INT_MAX 100000
int n;

//Prims Helper Function
int isValidEdge(int u, int v, int* inMST) 
{ 
   if (u == v) 
       return 0; 
   if (inMST[u] == 0 && inMST[v] == 0) 
        return 0; 
   else if (inMST[u] == 1 && inMST[v] == 1) 
        return 0; 
   return 1; 
} 
  
void primMST(int cost[][50],int x) 
{   
    int inMST[n]; 
  
    // Include first vertex in MST 
    inMST[0] = 1; 
  
    // Keep adding edges while number of included 
    // edges does not become V-1. 
    int edge_count = 0, mincost = 0; 
    while (edge_count < x - 1) { 
  
        // Find minimum weight valid edge.   
        int min = INT_MAX, a = -1, b = -1; 
        for (int i = 0; i < x; i++) { 
            for (int j = 0; j < x; j++) {                
                if (cost[i][j] < min) { 
                    if (isValidEdge(i, j, inMST)) { 
                        min = cost[i][j]; 
                        a = i; 
                        b = j; 
                    } 
                } 
            } 
        } 
        if (a != -1 && b != -1 ) { 
            printf("Edge %d:(%d, %d) cost: %d \n",  
                         edge_count++, a, b, min); 
            mincost = mincost + min; 
            inMST[b] = inMST[a] = 1; 
        } 
    } 
    printf("\nMinimum cost= %d \n", mincost); 
} 

int main() 
{ 
int i,j;
printf("Enter number of vertex: ");
scanf("%d",&n);
int cost[50][50];
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&cost[i][j]);
}
}
    // Print the solution 
    primMST(cost,n); 
  
    return 0; 
} 
