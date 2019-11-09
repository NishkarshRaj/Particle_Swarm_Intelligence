#include<stdio.h>
#include<stdlib.h>
//Adjancy List
//N nodes -> 0 is V1, 1 is V2,,, k is Vk+1,,,, n-1 is Vn
//Adjancy List ignoring loop, if connected with rest, then added in ordered fashion
struct node
{
	int node_number;
	struct node *next; //for linked list of structures
	struct node *list[20]; //for Adjancy list
};
// Create a linked list-> Adjancy List from Adjancy Matrix
int main()
{
	node *ptr,*head,*p;
	int n,i,j,k;
	scanf("%d",&n); //Number of vertex in the network
	int matrix[n][n];
	node *list1[n];
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
k=1;
	//Create Linked list for all the Nodes in Network
	for(i=0;i<n;i++)
	{
		ptr = (node*)malloc(sizeof(node));
		//printf("Enter the Unique number for Node: ");
		//scanf("%d",&(ptr->node_number));
ptr->node_number=k;
k++;
		//ptr->list=NULL;
		ptr->next=NULL;
		list1[i]=(node*)malloc(sizeof(node));
		for(j=0;j<20;j++)
		{
			list1[i]->list[j]=NULL;
		}
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
		list1[i]=ptr;
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
	//printf("%d",list1[0]->node_number);
	/////////////////////////////////////////////////
	//Create List
	p=head;
	while(p->next!=NULL)
	{
//printf("Check 1\t");
		j=0;
k=p->node_number;
k--;
		for(i=0;i<n;i++)
		{
//	printf("Check 2\t");
			if((matrix[k][i]!=0)&&(i!=k))
			{
//printf("Check 3\n");
				p->list[j++]=list1[i];	
			}
		}
p=p->next;
	}
//printf("Check4");
		j=0;
k=p->node_number;
k--;
		for(i=0;i<n;i++)
		{
//	printf("Check 2\t");
			if((matrix[k][i]!=0)&&(i!=k))
			{
//printf("Check 3\n");
				p->list[j++]=list1[i];	
			}
		}
	/////////////////////////////////////////////////
	//Display Adjancy List
	p=head;
	while(p->next!=NULL)
	{
printf("%d: ",p->node_number);
		for(i=0;p->list[i]!=NULL;i++)
		{
			printf("%d\t",p->list[i]->node_number);
		}
printf("\n");
p=p->next;
	}
printf("%d: ",p->node_number);
		for(i=0;p->list[i]!=NULL;i++)
		{
			printf("%d\t",p->list[i]->node_number);
		}
printf("\n");
	return 0;
}
