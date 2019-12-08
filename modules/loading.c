#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
int i;
char ch;
system("reset");
cout<<"Hello, Enter any key to continue"<<endl;
cin>>ch;
for(i=0;i<10000;i++)
{
cout<<"Loading Content "<<i+1<<endl;
}
system("reset");
}
