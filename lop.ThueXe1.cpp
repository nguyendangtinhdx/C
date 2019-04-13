#include<conio.h>
#include<stdio.h>
#include<iostream>
using namespace std;
	class xedap
	{
		char ten[50],cmnd[50];
		int gio;
		public:
			virtual void nhap()
			{
				cout<<"\n Ten: ";
				fflush(stdin);
				gets(ten);
				cout<<"\n CMND: ";
				gets(cmnd);
				cout<<"\n Gio thue: ";
				cin>>gio;
			}
			virtual	void in()
			{
				cout<<"\n Ten: "<<ten;
				cout<<"\n CMND: "<<cmnd;
				cout<<"\n Gio thue: "<<gio;
			}
			virtual int tinhtien()
			{
					return gio*50;
			}
	};
	class xemay: public xedap
	{
		char ten[50],cmnd[50];
		int gio,loai;
		public:
			void nhap()
			{
				cout<<"\n Ten: ";
				fflush(stdin);
				gets(ten);
				cout<<"\n CMND: ";
				gets(cmnd);
				cout<<"\n Gio thue: ";
				cin>>gio;
				cout<<"\n Loai: ";
				cin>>loai;
			}
			void in()
			{
				cout<<"\n Ten: "<<ten;
				cout<<"\n CMND: "<<cmnd;
				cout<<"\n Gio thue: "<<gio;
				cout<<"\n Loai: "<<loai<<" Phan khoi";
			}
			int tinhtien()
			{
				if(loai==100)
				{
					if(gio>1)
						return 150*gio;
						return 100;
				}
				else
				{
					if(gio>1)
						return 200*gio;
						return 100;
				}
			}
	};
int main()
{
	xemay m;
	xedap *p;
	xedap d;
	cout<<"\n XE DAP ";
	do
	{
	 	d.nhap();
	 	d.in();
	 	cout<<"\n So tien: "<<d.tinhtien();
	}while(getch()!=27);
	p=&m;
	cout<<"\n XE MAY ";
	do
	{
	 	p->nhap();
	 	p->in();
	 	cout<<"\n So tien: "<<p->tinhtien();
	}while(getch()!=27);

	getch();
}
