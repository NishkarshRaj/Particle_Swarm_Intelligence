#include<stdio.h>
int main()
{
	printf("Creation of .csv file by user\n");
	//Adjance Matrix is a square matrix n*n with n being the number of nodes in the network
	int n,i,j,count=0;
	printf("Enter the number of nodes in network: ");
	scanf("%d",&n);
	int ds[100];
	char temp[100];
	// Create a file pointer
	FILE *fp;
	// Create a .csv file
	fp = fopen("First.csv","a+");  
	// to update: Ask user for name of csv file to be made and also create a text file to store details of all csv file made till now or 
	//create a code to search for all csv files in current path.

	// Storing number of nodes as first line in adjacency matrix
	sprintf(temp,"%d",n);	
        fputs(temp,fp);
	fputs("\n",fp);
        printf("Enter the Adjancy Matrix values row wise\n");
	for(i=0;i<n;i++)
	{
			for(j=0;j<n;j++)
			{
				scanf("%d",&ds[count]);
				//temp=ds[count]; //string because fputs only takes string as input
				sprintf(temp,"%d",ds[count]);
				fputs(temp,fp);
				fputs(",",fp);
				count++;
			}
			fputs("\n",fp);
	}
	fclose(fp);
}
