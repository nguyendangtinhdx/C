#include<conio.h>
#include<iostream>
using namespace std;
	class dathuc
	{
		int *heso,bac;
		public:
			dathuc();
			dathuc(int *a, int n);
			dathuc(int n);
			void nhap();
			void in();
			friend dathuc operator +(dathuc a, dathuc b);
			int &operator [](int i);
	};
dathuc::dathuc()
{
	heso=NULL;
	bac=0;
}
dathuc::dathuc(int *a, int n)
{
	bac=n;
	heso=new int[n+1];
	for(int i=0;i<=n;i++)
		heso[i]=a[i];
}
void dathuc::nhap()
{
	int i;
	cout<<"\n NHAP BAC: "; cin>>bac;
	heso=new int[bac+1];
	for(i=0;i<=bac;i++)
	{
		cout<<"\n He so bac "<<i<<": ";
		cin>>heso[i];
	}
}
void dathuc::in()
{
	int i;
	for(i=bac;i>=0;i--)
		{
			cout<<" "<<heso[i]<<"x^"<<i;
		}
}
dathuc operator +(dathuc a, dathuc b)
{
	int i;
	dathuc c;
	if(a.bac<b.bac)
	{
		c.bac=b.bac;
		c.heso=new int[c.bac+1];
		for(i=0;i<=a.bac;i++)
			c.heso[i]=a.heso[i]+b.heso[i];
		for(i=a.bac+1;i<=b.bac;i++)
			c.heso[i]=b.heso[i];
	}
	else
	{
		c.bac=a.bac;
		c.heso=new int[c.bac+1];
		for(i=0;i<=b.bac;i++)
			c.heso[i]=a.heso[i]+b.heso[i];
		for(i=b.bac+1;i<=a.bac;i++)
			c.heso[i]=a.heso[i];
	}
	return c;
}
int &dathuc::operator [](int i)
{
	return heso[i];
} 
int main()
{
	dathuc d,d1,d2;
	d1.nhap();
	d2.nhap();
	cout<<"\n Da thuc 1: ";
	d1.in();
	cout<<"\n Da thuc 2: ";
	d2.in();
	d=d1+d2;
	cout<<"\n Tong 2 da thuc: ";
	d.in();
	int n;
	cout<<"\n Nhap he so cua bac muon tim: "; cin>>n;
	cout<<"\n He so = "<<d1[n];
	getch();
}
