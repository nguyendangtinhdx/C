#include<conio.h>
#include<iostream>
#include<math.h>
using namespace std;
	class hinhhoc
	{
		public:
			virtual float dientich()
			{
				return 0;
			}
			virtual float chuvi()
			{
				return 0;
			}
	};
	class hinhtron: public hinhhoc
	{
		float r;
		public:
			void nhap()
			{
				cout<<"\n Hinh tron: ";
				cout<<"\n Ban kinh = ";
				cin>>r;
			}
			void in()
			{
				cout<<"\n => R = "<<r;
			}
			float dientich()
			{
				return 3.14*r*r;
			}
			float chuvi()
			{
				return 2*3.24*r;
			}
	};
	class hinhtamgiac: public hinhhoc
	{
		int a,b,c;
		float s,p;
		public:
			void nhap()
			{
				cout<<"\n Hinh tam giac: ";
				cout<<"\n Canh a = "; cin>>a;
				cout<<"\n Canh b = "; cin>>b;
				cout<<"\n Canh c = "; cin>>c;
			}
			void in()
			{
				cout<<"\n => (a,b,c) = "<<"("<<a<<","<<b<<","<<c<<")";
			}
			float dientich()
			{
				p=(a+b+c)/2;
				return sqrt(p*(p-a)*(p-b)*(p-c));
			}
			float chuvi()
			{
				return a+b+c;
			}
	};
	class hinhvuong: public hinhhoc
	{
		float a;
		public:
			void nhap()
			{
				cout<<"\n Hinh vuong: ";
				cout<<"\n Canh a = "; cin>>a;
			}
			void in()
			{
				cout<<"\n => a = "<<a;
			}
			float dientich()
			{
				return a*a;
			}
			float chuvi()
			{
				return 4*a;
			}
	};
int main()
{
	hinhhoc *h[100];
	int n,i,tl;
	cout<<"\n Nhap so luong hinh hoc: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\n 1-HinhTron; 2-HinhTamGiac; 3-HinhVuong: ";
		cin>>tl;
		if(tl==1)
		{
			hinhtron *p = new hinhtron;
			p->nhap();
			h[i]=p;
		}
		else if(tl==2)
		{
			hinhtamgiac *p = new hinhtamgiac;
			p->nhap();
			h[i]=p;
		}
		else
		{
			hinhvuong *p = new hinhvuong;
			p->nhap();
			h[i]=p;
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<"\n Dien tich = "<<h[i]->dientich()<<" cm^2";
		cout<<"\n Chu vi = "<<h[i]->chuvi()<<" cm";
	}
	getch();
}
