#include<conio.h>
#include<iostream>
#include<math.h>o
using namespace std;
	class phanso
	{
		int t,m;
		public:
			void nhap()
			{
				cout<<"\n Tu So = ";
				cin>>t;
				do
				{
					cout<<"\n Mau so = ";
					cin>>m;
				}while(m==0);
			}	
			void in()
			{
				cout<<"\n Tu So = "<<t<<"; Mau So = "<<m;
			}
		/*	int ucln(int a,int b)
			{
				if(b==0) return a;
				return ucln(b,a%b);
			}*/
			int ucln(int a, int b)
			{
				while(a!=b)
				{
					if(a>b)
						a-=b;
					else
						b-=a;
				}
			}
			phanso tong(phanso p1,phanso p2)
			{
				int i;
				phanso p,t;
				p.t=p1.t*p2.m+p2.t*p1.m;
				p.m=p1.m*p2.m;
				i=ucln(p.t,p.m);
				cout<<"\n UCLN = "<<ucln(p.t,p.m);
				p.t/=i;
				p.m/=i;
				return p;
			}

	};
int main()
{
	phanso p,p1,p2;
	cout<<"\n Phan so thu 1: ";
	p1.nhap();
	cout<<"\n Phan so thu 2: ";
	p2.nhap();
	p1.in();
	p2.in();
	p=p.tong(p1,p2);
	cout<<"\n Tong 2 phan so : ";
	p.in();
	getch();
}
