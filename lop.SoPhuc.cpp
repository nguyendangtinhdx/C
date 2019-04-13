#include<conio.h>
#include<iostream>
#include<math.h>
using namespace std;
	class sophuc
	{
		float a,b;
		public:
			void nhap()
			{
				cout<<"\n Phan thuc: ";
				cin>>a;
				cout<<"\n Phan ao: ";
				cin>>b;
			}
			void in()
			{
				cout<<"\n So phuc la: ";
				if(b<0)
				{
					cout<<a<<b<<"i"<<endl;
				}
				else
					cout<<a<<"+"<<b<<"i"<<endl;
			}
			sophuc operator *(sophuc s2)
			{
				sophuc s;
				s.a=a*s2.a - b*s2.b;
				s.b=a*s2.b + b*s2.a;
				return s;
			}
			sophuc operator /(sophuc s2)
			{
				sophuc s;
				s.a=(a*s2.a + b*s2.b)/sqrt(s2.a*s2.a+s2.b*s2.b);
				s.b=(b*s2.a - a*s2.b)/sqrt(s2.a*s2.a+s2.b*s2.b);
				return s;
			}
			// + 1 so nguyen vao so phuc
		friend	sophuc operator + (int n, sophuc s2)
			{
				sophuc s;
				s.a=n+s2.a;
				s.b=s2.b;
				return s;
			}
			// + so phuc voi so nguyen
			sophuc operator + (int n)
			{
				sophuc s;
				s.a=a+n;
				s.b=b;
				return s;
			}
			float operator !()
			{
				return sqrt(a*a+b*b);
			}
			
	};
int main()
{
	sophuc s,s1,s2,s3,s4;
	s1.nhap();
	s1.in();
	s2.nhap();
	s2.in();
	s=s1*s2;
	cout<<"\n Tich 2 so phuc: ";
	s.in();
	s3=s1/s2;
	cout<<"\n Thuong 2 so phuc: ";
	s3.in();
	int n;
	cout<<"\n Nhap so nguyen n = "; cin>>n;
	s4=n+s1;
	cout<<"\n Cong 1 so nguyen vao so phuc: ";
	s4.in();
	int m;
	cout<<"\n Nhap so nguyen m = "; cin>>m;
	s1=s1+m;
	cout<<"\n Cong so phuc voi so nguyen: ";
	s1.in();
	cout<<"\n Do dai la: "<<!s2;
	getch();
}
	
