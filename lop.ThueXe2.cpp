#include<conio.h>
#include<stdio.h>
#include<iostream>
using namespace std;
	class xe
	{
		char ten[30],cmnd[30];
		int gio;
		public:
			void nhap();
			virtual void in();
			virtual float tinhtien();
			int getgio();
	};
void xe::nhap()
{
	cout<<"\n Ho ten: "; 
	fflush(stdin);
	gets(ten);
	cout<<"\n CMND: ";
	gets(cmnd);
	cout<<"\n Gio thue: ";
	cin>>gio;
}
void xe::in()
{
	cout<<"\n Ten: "<<ten;
	cout<<"\n CMND: "<<cmnd;
	cout<<"\n Gio thue: "<<gio;
}
float tinhtien()
{
	return 0;
}
int xe::getgio()
{
	return gio;
}

	class xedap: public xe
	{
		public:
			void nhap();
			void in();
			float tinhtien();
	};
float xedap::tinhtien()
{
		return 50*getgio();
}

	class xemay: public xe
	{
		int loai;
		char bienso[10];
		public:
			void nhap();
			void in();
			float tinhtien();
	};
void xemay::nhap()
{
	xe::nhap();
	cout<<"\n Loai: ";
	cin>>loai;
	cout<<"\n Bien so: ";
	gets(bienso);
}
void xemay::in()
{
	xe::in();
	cout<<"\n Loai: "<<loai<<" Phan khoi";
	cout<<"\n Bien so: "<<bienso;
}
float xemay::tinhtien()
{
	if(loai==100)
		if(getgio()<=1)
			return 150;
		else
			return 150+(getgio()-1)*100;
	else
		if(getgio()<=1)
			return 200;
		else
			return 200+(getgio()-1)*100;
}
int main()
{
	xe *ds[100];
	xedap *p;
	xemay *q;
	int i=0,tl,k;
	do
	{
		i++;
		cout<<"\n Nhap thong tin xe dap hay xa may, 1 - Xe Dap, 2 - Xe May ";
		cin>>tl;
		switch(tl)
		{
			case 1: p=new xedap;
					p->nhap();
					ds[i]=p;
					break;
			case 2: q=new xemay;
					q->nhap();
					ds[i]=q;
					break;
		}
	}
	while(getch()!=27);
	for(k=1;k<=i;k++)
	{
		ds[k]->in();
		cout<<ds[k]->tinhtien();
	}
	getch();
}
