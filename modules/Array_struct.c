#include<stdio.h>
#include<stdlib.h>
//Adjancy List
//N nodes -> 0 is V1, 1 is V2,,, k is Vk+1,,,, n-1 is Vn
//Adjancy List ignoring loop, if connected with rest, then added in ordered fashion
struct node
{
	int node_number;
	struct node *next; //for linked list of structures
	struct node *list; //for Adjancy list
};
// Create a linked list
int main()
{
	node *ptr,*head,*p;
	int n,i,j;
	scanf("%d",&n); //Number of vertex in the network
	int matrix[n][n];
	node *list[n];
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
	////////////////////////////////////////////////
	//Create Linked list for all the Nodes in Network
	for(i=0;i<n;i++)
	{
		ptr = (node*)malloc(sizeof(node));
		printf("Enter the Unique number for Node: ");
		scanf("%d",&(ptr->node_number));
		ptr->list=NULL;
		ptr->next=NULL;
		list[i]=(node*)malloc(sizeof(node));
		if(i==0)
		{
			head=(node*)malloc(sizeof(node));
			head=ptr;	
		}
		else
		{
			p=head;
			while(p->next!=NULL)
			{
				p=p->next;
			}
			p->next=ptr;
		}
		list[i]=ptr;
	}
	////////////////////////////////////////////////
	//Display the Linked List
	p=head;
	printf("%d\n",head->node_number);
	while(p->next!=NULL)
	{
		printf("%d\n",ptr->node_number);
		p=p->next;
	}
	//printf("%d",list[0]->node_number);
	return 0;
}
