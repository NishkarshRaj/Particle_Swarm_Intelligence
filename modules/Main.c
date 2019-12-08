#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<time.h>
#define NODES 50

//Adjancy List
//N nodes -> 0 is V1, 1 is V2,,, k is Vk+1,,,, n-1 is Vn
//Adjancy List ignoring loop, if connected with rest, then added in ordered fashion
struct node
{
	int node_number;
	struct node *next; //for linked list of structures
	struct node *list[20]; //for Adjancy list
};

//User creates graph as .csv file
void create_csv(char f1[100])
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

//Time calculator
void time()
{
//clock_t is capable of calculating processor time and clock funcion is capable of returning the clock time since the program is started
clock_t start = clock(); 
/*
write the program for which you need to calculate the time used by cpu
*/
clock_t end = clock();
clock_t time = ((double) (end - start)) / CLOCKS_PER_SEC;    //number of processor clock ticks per second is CLOCKS_PER_SEC
printf("%d\n",time);
}

//Module 4
void readcsv(char f1[100])
{

  // Declare the file pointer 
  FILE * filePointer;

  // Declare the variable for the data to be read from file 
  char dataToBeRead[50];

  // Open the existing file GfgTest.c using fopen() 
  // in read mode using "r" attribute 
  filePointer = fopen(f1, "r");

  // Check if this filePointer is null 
  // which maybe if the file does not exist 
  if (filePointer == NULL) {
    printf("test.csv file failed to open.");
  } else {

    printf("The file is now opened.\n");
    int count = 0;
    int k = 10;
int n,i,j;
    char arr[NODES][NODES];
    while (fgets(dataToBeRead, 50, filePointer) != NULL) {
      if (count == 0) {
        // First line of csv contains total number of nodes
        k = atoi(dataToBeRead);
      } else {
        int j = 0;
        int length = (int) strlen(dataToBeRead);
        for (int i = 0; i < length - 1; i++) {

          if (dataToBeRead[i] != ',') {

            arr[count - 1][j] = dataToBeRead[i];

            // make sure to print using %c 
            printf("%c \n", arr[count - 1][j]);
            j++;
          }
        }
        printf("\n");

      }
      count++;
    }

    // Closing the file using fclose() 
    fclose(filePointer);

    printf("Data successfully read from specified file\n");
    printf("The file is now closed.\n");
    int array[k][k];
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < k; j++) {
        array[i][j] = arr[i][j] - '0';
        printf("%d ", array[i][j]);
      }
      printf("\n");
    }
    ////Adjancy Matrix to adjancy List
node *ptr,*head,*p;
	n=k;
k=0;
int matrix[n][n];
	node *list1[n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			matrix[i][j] = array[i][j];
		}
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
  }
}

int main()
{
int ch1,n,count;
char f1[100];
printf("An efficient approach to optimize Network routing using Particle Swarm Intelligence\n\n");
printf("Press 1) Create new graph\n");
printf("Press 2) Use existing graph\n");
printf("Enter your choice: ");
scanf("%d",&ch1);
switch(ch1)
{
case 1: printf("Enter Unique Name of the graph: ");
scanf("%s",&f1);
	create_csv(f1);
break;
case 2:
printf("Following are the existing .csv files in the current directory\n");
///////////// to get the .csv files in current directory
struct dirent **namelist;
count=1;
       n = scandir(".", &namelist, parse_ext, alphasort);
       if (n < 0) {
           perror("scandir");
           return 1;
       }
       else {
           while (n--) {
               printf("%d: %s\n",count, namelist[n]->d_name);
count++;
               free(namelist[n]);
           }
           free(namelist);
       }
///////////////////
printf("Enter name of the file you want to use: ");
scanf("%s",&f1);
break;
default: printf("Wrong Choice! Exiting Code\n");
}
//Running Module 4 Read CSV
readcsv(f1);
return 0;
}