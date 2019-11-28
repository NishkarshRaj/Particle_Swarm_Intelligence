// C program to generate random numbers 
#include<math.h>
#include<stdio.h>  //Io Header File
#include<stdlib.h> //For Rand and Srand inbuilt functions 
#include<time.h> //To generate Random numbers each and every time rather than getting same random number 
//Time function is needed to generate dynamic numbers at runtime because rand() is compiled time executed and generates same number on multiple execution
  
float random_generator()
{
	register int x = rand(); //Using register storage class for faster access
	//printf("%d",x); Yes every time new random integer is generated
	//How to convert any integer number into a float between 0 and 1
	//Divide the number by 10^(number of digits)
	int count=0,temp;
	temp=x; //temp holds x value because its going to change to 0 to count frequency of digits
	while(temp>0)
	{
	    count++;
	    temp=temp/10;
	}
	//printf("%d\n%d\n",x,count);
	temp = pow(10,count); //using same variable again to save memory
	float answer = (float)x/temp;
	//printf("%f\n",answer);
	return abs(answer);
}  
  
// Driver program 
int main(void) 
{ 
	//Initialization used to call only once
	srand(time(0)); 
	printf("%f\n%f\n%f\n",random_generator(),random_generator(),random_generator());
    return 0; 
} 

