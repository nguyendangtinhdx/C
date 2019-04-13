#include<conio.h>
#include<iostream>
#include<stdio.h>
using namespace std;
	class num
	{
		public:
			int i;
			num(int x)
			{
				i=x;
			}
			virtual void show()
			{
				cout<<"\n He 10: ";
				cout<<dec<<i<<endl;
			}
	};
	class outhex: public num
	{
		public:
			outhex(int n): num(n){}
			void show()
			{
				cout<<"\n He 10: "<<dec<<i;
				cout<<"=> He 16: "<<hex<<i<<endl;				
			}
	};
	class outoct: public num
	{
		public:
			outoct(int n): num(n){}
			void show()
			{
				cout<<"\n He 10: "<<dec<<i;
				cout<<"=> He 8: "<<oct<<i<<endl;	
			}
	};

int main()
{
	int hh;
	cout<<"\n Nhap he 10 = "; cin>>hh;
	num *p;
	num n(hh);
	outoct o(hh);
	outhex h(hh);
	p=&n;
	p->show();
	p=&o;
	p->show();
	p=&h;
	p->show();
	getch();
}
