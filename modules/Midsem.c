#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
//User creates graph as .csv file
void create_csv()
{
	printf("Creation of .csv file by user\n");
	//Adjance Matrix is a square matrix n*n with n being the number of nodes in the network
	int n,i,j,count=0;
	char f1[100];
	printf("Enter the number of nodes in network: ");
	scanf("%d",&n);
	int ds[100];
	char temp[100];
printf("Enter Unique Name of the graph: ");
scanf("%s",&f1);
	// Create a file pointer
	FILE *fp;
	// Create a .csv file
	fp = fopen(f1,"a+");  
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

//method to find the .csv file in current folder
static int parse_ext(const struct dirent *dir)
   {
     if(!dir)
       return 0;

     if(dir->d_type == DT_REG) 
	 { /* only deal with regular file */
         const char *ext = strrchr(dir->d_name,'.');
         if((!ext) || (ext == dir->d_name))
           return 0;
         else {
           if(strcmp(ext, ".csv") == 0)
             return 1;
         }
     }
     return 0;
}
int main()
{
int ch1,n;
printf("An efficient approach to optimize Network routing using Particle Swarm Intelligence\n\n");
printf("Press 1) Create new graph\n");
printf("Press 2) Use existing graph\n");
printf("Enter your choice: ");
scanf("%d",&ch1);
switch(ch1)
{
case 1:
	create_csv();
break;
case 2:
///////////// to get the .csv files in current directory
struct dirent **namelist;
       n = scandir(".", &namelist, parse_ext, alphasort);
       if (n < 0) {
           perror("scandir");
           return 1;
       }
       else {
           while (n--) {
               printf("%s\n", namelist[n]->d_name);
               free(namelist[n]);
           }
           free(namelist);
       }
///////////////////
break;
default: printf("Wrong Choice! Exiting Code\n");
}
return 0;
}
