#include<stdio.h>
#include<cstdlib>
using namespace std;
void loading()
{
int i;
char ch;
system("reset");
printf("Hello, Enter any key to continue: ");
scanf("%c",&ch);
for(i=0;i<50000;i++)
{
printf("Loading Content: %d\n",i+1);
}
system("reset");
}
int main()
{
loading();
}
