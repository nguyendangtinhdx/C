#include<conio.h>
#include<iostream>
using namespace std;
void quaylui(int i,int n)
{
    int j,k,d=0;
    static int a[20];
    for(j=0;j<=1;j++)
    {
        a[i]=j;
        if(i==n-1)
        {
        	for(k=0;k<n;k++)
                cout<<a[k];
           		cout<<"\n";
        }
        else quaylui(i+1,n);
    }
}
int main()
{       
	int n;
    cout<<"\n Nhap n = ";
    cin>>n;
    quaylui(0,n);
	getch();
}
