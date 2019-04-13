#include<conio.h>
#include<string.h>
#include<iostream>
#include<stdio.h>
using namespace std;
	class String
	{
		char *s;
		int l;
		public:
			void nhap()
			{
				s = new char[100];
				cout<<"\n Nhap chuoi: ";
				gets(s);
				l = strlen(s);
			}
			void in()
			{
				cout<<"\n => "<<s<<endl<<" Co do dai = "<<l;
			}
			char *get()
			{
				return s;
			}
			String operator +(String s2)
			{
				strcat(s,s2.s);
				return *this;
			}
			String operator =(String s2)
			{
				strcpy(s,s2.s);
				return *this;
			}	
			int operator ==(String s2)
			{
				return strcmp(s,s2.s)==0;
			}
			char operator [](int i)
			{
				if(i>=0||i<strlen(s))
				return s[i];
			}
			int operator <(String s2)
			{
				if(strlen(s)<strlen(s2.s))
					return 1;
					return 0;
			}	

	};
		
int main()
{
	String s,ss,sss,s1,s2,s3;
	s1.nhap();
	s1.in();
	s2.nhap();
	s2.in();
/*	s=s1+s2;
	cout<<"\n Chuoi noi thanh: "<<s.get();
	s1=s2;
	cout<<"\n Chuoi gan s1 = s2 thanh: "<<s1.get();
	if(s1==s2)
	{
		cout<<"\n 2 chuoi = nhau ";
	}
	else
	{
		cout<<"\n 2 chuoi != nhau ";
	}
	int n;
	cout<<"\n Truy cap ki tu thu: ";
	cin>>n;
	cout<<"\n Ki tu do la: "<<s1[n];*/
	if(s1<s2)
	{
		cout<<"\n Chuoi truoc < hon chuoi sau ";
	}
	else
	{
		cout<<"\n Chuoi truoc > hon chuoi sau ";
	}
	getch();
}
