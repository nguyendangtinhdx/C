#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
	class nguoi
	{
		int maso;
		char hoten[50];
		public:
			void nhap()
			{
				cout<<"\n Ma can bo: ";
				cin>>maso;
				cout<<"\n Ho ten: ";
				fflush(stdin);
				gets(hoten);
			}
			void in()
			{
				cout<<"\n MaCB: "<<maso;
				cout<<"\n HoTen: "<<hoten;
			}
	};
	class bienche: public nguoi
	{
		float pccv,hsl;
		public:
			void nhap1()
			{
				cout<<"\n He so luong: ";
				cin>>hsl;
				cout<<"\n Phu cap chuc vu: ";
				cin>>pccv;
			}
			void in1()
			{
				cout<<"\n HSL: "<<hsl;
				cout<<"\n PCCV: "<<pccv;
			}
			float tinhluong1()
			{
				return hsl*750+pccv;
			}
	};
	class hopdong: public nguoi
	{
		int snlv;
		public:
			void nhap2()
			{
				cout<<"\n So ngay lam viec: ";
				cin>>snlv;
			}
			void in2()
			{
				cout<<"\n SNLV: "<<snlv;
			}
			float tinhluong2()
			{
				return snlv*150;
			}
	};
int main()
{
	bienche bc[100];
	hopdong hd[100];
	int n,i,m,j;
	cout<<"\n Nhap so can bo: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		bc[i].nhap();
		bc[i].nhap1();
	}
	cout<<"\n Dang sach can bo BIEN CHE: ";
	for(i=0;i<n;i++)
	{
		bc[i].in();
		bc[i].in1();
		cout<<"\n He so luong: "<<bc[i].tinhluong1();
	}
	cout<<"\n Nhap so can bo: ";
	cin>>m;
	for(j=0;j<m;j++)
	{
		hd[j].nhap();
		hd[j].nhap2();
	}
	cout<<"\n Dang sach can bo HOP DONG: ";
	for(j=0;j<m;j++)
	{
		hd[j].in();
		hd[j].in2();
		cout<<"\n He so luong: "<<hd[j].tinhluong2();
	}
	getch();
}
