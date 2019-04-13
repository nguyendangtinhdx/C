#include<conio.h>
#include<iostream>
using namespace std;
	class A
	{	
		int a,b;
		public:
			void nhap()
			{
				cout<<"\n a = ";
				cin>>a;
				cout<<"\n b = ";
				cin>>b;
			}
			void in()
			{
				cout<<"\n a = "<<a<<"\t b = "<<b;
			}
			int tich()
			{
				return a*b;
			}
	};
	class B: public A
	{
		float x,y;
		public:
			void nhap()
			{
				cout<<"\n x = ";
				cin>>x;
				cout<<"\n y = ";
				cin>>y;
			}
			void in()
			{
				cout<<"\n x = "<<x<<"\t y = "<<y;
			}

	};
int main()
{
	A a;
	B b;
	a.nhap();
	a.in();
	b.nhap();
	b.in();
	cout<<"\n Sau khi ke thua: ";
	b.A::nhap();
	b.A::in();
//	cout<<"\n  a * b = "<<a.tich();
	cout<<"\n  a1 * b1 = "<<b.tich();
	getch();
}
