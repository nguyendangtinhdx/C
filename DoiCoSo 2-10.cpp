#include<iostream>
using namespace std;
int convert(int i)
{
	if(i>0)
	{
		convert(i/2);
		cout<<i%2;
	}
}
int  main()
{
	int i;
	cout<<"\n Input: ";
	cin>>i;
	convert(i);
}
