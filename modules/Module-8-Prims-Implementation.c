#include <stdio.h> 
#define V 5
#define INT_MAX 100000
//@author: Harsh Joshi
// Returns true if edge u-v is a valid edge to be 
// include in MST. An edge is valid if one end is 
// already included in MST and other is not in MST. 
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
  
void primMST(int cost[][V]) 
{   
    int inMST[5]; 
  
    // Include first vertex in MST 
    inMST[0] = 1; 
  
    // Keep adding edges while number of included 
    // edges does not become V-1. 
    int edge_count = 0, mincost = 0; 
    while (edge_count < V - 1) { 
  
        // Find minimum weight valid edge.   
        int min = INT_MAX, a = -1, b = -1; 
        for (int i = 0; i < V; i++) { 
            for (int j = 0; j < V; j++) {                
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
    printf("\n Minimum cost= %d \n", mincost); 
} 

int main() 
{ 
   /* While Merging we need to change this particular code which takes in 2 D array as input */
   int cost[][V] = { 
        { INT_MAX, 2, INT_MAX, 6, INT_MAX }, 
        { 2, INT_MAX, 3, 8, 5 }, 
        { INT_MAX, 3, INT_MAX, INT_MAX, 7 }, 
        { 6, 8, INT_MAX, INT_MAX, 9 }, 
        { INT_MAX, 5, 7, 9, INT_MAX }, 
    }; 
  
    // Print the solution 
    primMST(cost); 
  
    return 0; 
} 