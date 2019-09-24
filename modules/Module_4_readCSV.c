# include <stdio.h> 
# include <string.h> 
#include <stdlib.h>     /* atoi */
#define NODES 50
int main( ) 
{ 

// Declare the file pointer 
FILE *filePointer ; 

// Declare the variable for the data to be read from file 
char dataToBeRead[50]; 

// Open the existing file GfgTest.c using fopen() 
// in read mode using "r" attribute 
filePointer = fopen("First.csv", "r") ; 

// Check if this filePointer is null 
// which maybe if the file does not exist 
if ( filePointer == NULL ) 
{ 
	printf( "test.csv file failed to open." ) ; 
} 
else
{ 

printf("The file is now opened.\n") ; 
int count = 0;
int k=10;
char arr[NODES][NODES];
while( fgets ( dataToBeRead, 50, filePointer ) != NULL ) 
{ 
if(count==0) 
{
// First line of csv contains total number of nodes
k = atoi( dataToBeRead );
}

else
{
int j=0;
int length = (int)strlen(dataToBeRead); 
for (int i = 0; i < length-1; i++) 
{

if(dataToBeRead[i]!=',')
{

arr[count-1][j]=dataToBeRead[i];

// make sure to print using %c 
printf("%c \n",arr[count-1][j]);
j++;
}
}
printf("\n");

}
count++;
} 

// Closing the file using fclose() 
fclose(filePointer) ; 

printf("Data successfully read from file GfgTest.c\n"); 
printf("The file is now closed.\n") ; 
int array[k][k];
for (int i = 0; i < k; i++) 
{
for (int j = 0; j < k; j++) 
{
array[i][j]=arr[i][j]-'0';
printf("%d ",array[i][j]);
} 
printf("\n");
}
}

return 0;         
} 
