#include<conio.h>
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
char kt(char *s)
{
	int n,m,i,j=0,l,k=0;
	char a[100],b[50],c[50],d[50];
	n=strlen(s);
	for(i=0;i<n;i++)
	
		
		a[j++]=s[i];
		
	//	cout<<"\n "<<a[j];
		a[j]=NULL;
		
	
	
	cout<<"\n "<<a[j];
	return a[j];
/*	for(l=n-1;l>n/2;l--)
	{
		c[k++]=s[l];
		c[k]=NULL;
		cout<<"\n "<<c[k];
	}*/
/*	if(strcmp(a[j],c[k])==0)
		return 1;
		return 0;*/
}
int main()
{
	char s[100];
	cout<<"\n Nhap chuoi: ";
	gets(s);
	cout<<kt(s);
/*	if(kt(s)==1)
	{
		cout<<"\n Chuoi doi xung ";
	}
	else
		cout<<"\n Chuoi khong doi xung ";*/
	getch();
}
