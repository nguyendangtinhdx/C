#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
	class xedap
	{
		char ten[50],cmnd[50];
		int gio,tien;
		public:
			virtual void nhap()
			{
				cout<<"\n Ten nguoi thue: ";
				fflush(stdin);
				gets(ten);
				cout<<"\n So CMND: ";
				gets(cmnd);
				cout<<"\n So gio thue: ";
				cin>>gio;
				tien=50*gio;
			}
			virtual void in()
			{
				cout<<"\n 		XE DAP  ";
				cout<<"\n\t Ten\t CMND\t GioThue\t TongTien ";
				cout<<"\n\t "<<ten<<"\t "<<cmnd<<"\t "<<gio<<"\t\t "<<tien;
			}
	};
	class xemay: public xedap
	{
		char ten1[50],cmnd1[50];
		int gio1,tien1,bienso1,loai1;
		public:
			void nhap()
			{
				cout<<"\n Ten nguoi thue: ";
				fflush(stdin);
				gets(ten1);
				cout<<"\n So CMND: ";
				gets(cmnd1);
				cout<<"\n Bien so: ";
				cin>>bienso1;
				cout<<"\n So gio thue: ";
				cin>>gio1;
				cout<<"\n Loai xe: ";
				cin>>loai1;
				cout<<" Phan khoi";
				if(loai1==100&&gio1==1)
				{
					tien1=150;
				}
				else if(loai1==250&&gio1==1)
				{
					tien1=200;
				}
				else
				{
					tien1=100*gio1;
				}		
			}
			void in()
			{	
				cout<<"\n 				XE MAY  ";
				cout<<"\n\t Ten\t CMND\t BienSo\t GioThue LoaiXe\t TongTien ";
				cout<<"\n\t "<<ten1<<"\t "<<cmnd1<<"\t "<<bienso1<<"\t "<<gio1<<"\t "<<loai1<<"\t "<<tien1;
			}
	};
int main()
{
	int n,i,j;
	xedap *m;
	xemay h;
	xedap d;
	cout<<"\n XE DAP: ";
	do
	{
		d.nhap();
		d.in();
	}while(getch()!=27);
	
	cout<<"\n XE MAY: ";
	m=&h;
	do
	{
		m->nhap();m->in();
	}while(getch()!=27);
	
	
}
