//libraries needed
#include<stdio.h>
#include<stdlib.h>  //for malloc and system function


struct n	
{
int data;
struct n *link;
};


typedef struct n NODE;

NODE *getnode(int j)			//this function is used when there is a connection between the nodes
{
NODE * temp;
temp=(NODE *)malloc(sizeof(NODE));	//allocating memory to the temp dynamically	
temp->data=j;
temp->link=NULL;
return(temp);
}


NODE *findlast(NODE *h)		//This function is called when there is no connection between the nodes
{
NODE *ptr;
for(ptr=h;ptr->link!=NULL;ptr=ptr->link);
return(ptr);
}


void display(NODE *h[10],int n)		//this function is displaying the list
{
NODE *ptr;

for(int i=0;i<n;i++)
	{
	printf("\n V%d",i+1);		
	ptr=h[i];
	if(ptr==NULL)
		printf(" NULL");
	while(ptr!=NULL)
	{
	printf(" ->V%d",ptr->data);
	ptr=ptr->link;
	}
	printf("\n");
	}
}






void main()
{
NODE *ptr,*temp,*h[10];
int n,a[10][10],i,j;

printf("\n Enter total number of vertices : ");
scanf("%d",&n);

printf("\n Enter entries of an adjacency matrix :\n");
for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{
	printf("\n Enter a[%d][%d] : ",i+1,j+1);  
	scanf("%d",&a[i][j]);
	}

system("clear");			//after entering the adjancency matrix we are clearing the screen using the function system


//printing the adjancency matrix 
printf("\n\nAdjacency matrix is  \n");		
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf(" %d ",a[i][j]);
}
printf("\n");
}

for(i=0;i<n;i++)
h[i]=NULL;			//making the values of pointer array as NULL


for(i=0;i<n;i++)			//from here we are converting the Adjacency matrix into Adjacency list
	for(j=0;j<n;j++)
	{
		if(a[i][j]==1)
		{
		temp=getnode(j+1);
		if(h[i]==NULL)
		h[i]=temp;
		else
		{
		ptr=findlast(h[i]);
		ptr->link=temp;
		}
		}
	}

printf("\n The Adjacency list \n");	//size of the list will be equal to the no. of vertices
display(h,n);
}


