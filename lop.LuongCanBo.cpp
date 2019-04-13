#include<conio.h>
#include<iostream>
#include<stdio.h>
using namespace std;
	class bienche
	{
		protected:
			char ma[50],ten[50];
			int hsl,phucap;
		public:
			void nhap()
			{
				cout<<"\n BIEN CHE ";
				cout<<"\n Ma can bo: ";
				fflush(stdin);
				gets(ma);
				cout<<"\n Ten can bo: ";
				gets(ten);
				cout<<"\n He so luong: ";
				cin>>hsl;
				cout<<"\n Phu cap: ";
				cin>>phucap;
			}
			void in()
			{
				cout<<"\n 			CAN BO BIEN CHE ";
				cout<<"\n\t MaCanBo\t TeNCanBo\t HeSoLuong\t PhuCap ";
				cout<<"\n\t "<<ma<<"\t\t "<<ten<<"\t\t "<<hsl<<"\t\t "<<phucap;
			}
	};
	class hopdong: public bienche
	{
		protected:
			char ma1[50],ten1[50];
			int ngaylam;
		public:
			void nhap1()
			{
				cout<<"\n HOP DONG ";
				cout<<"\n Ma can bo: ";
				fflush(stdin);
				gets(ma1);
				cout<<"\n Ten can bo: ";
				gets(ten1);
				cout<<"\n So ngay lam: ";
				cin>>ngaylam;
			}
			void in1()
			{
				cout<<"\n 			CAN BO HOP DONG ";
				cout<<"\n\t MaCanBo\t TeNCanBo\t NgayLam ";
				cout<<"\n\t "<<ma1<<"\t\t "<<ten1<<"\t\t "<<ngaylam;
			}
	};
	class luong: public hopdong
	{
		int luong1,luong2;
		public:
			void tinh()
			{
				luong1=hsl*750+phucap;
				luong2=ngaylam*150;
				cout<<"\n Luong cua can bo BIEN CHE: "<<luong1;
				cout<<"\n Luong cua can bo HOP DONG: "<<luong2;
			}
	};
int main()
{
	luong s[50];
	int n,i;
	cout<<"\n Nhap so can bo: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		s[i].nhap();
		s[i].nhap1();
	}
	for(i=0;i<n;i++)
	{
		s[i].in();
		s[i].in1();
		s[i].tinh();
	}
	getch();
}
