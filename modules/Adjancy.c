#include<stdio.h>
#include<stdlib.h>
//Adjancy List
//N nodes -> 0 is V1, 1 is V2,,, k is Vk+1,,,, n-1 is Vn
//Adjancy List ignoring loop, if connected with rest, then added in ordered fashion
typedef struct node
{
	int node_number;
	struct node *next; //for linked list of structures
	struct node *list; //for Adjancy list
};
// Create a linked list
int main()
{
	node v1 = (node*)malloc(sizeof(node));
	v1->node_number=1;
	v1->next=NULL;
	vi->list=NULL;
	printf("%d",v1->node_number);
	int n,i,j;
	scanf("%d",&n); //Number of vertex in the network
	int matrix[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&matrix[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}
