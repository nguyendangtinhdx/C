#include<conio.h>
#include<iostream>
#include<stdio.h>
using namespace std;
	class sinhvien
	{
		char ma[50],hoten[50];
		public:
			sinhvien(){}
			void nhap()
			{
				cout<<"\n Ma sinh vien: ";
				fflush(stdin);
				gets(ma);
				cout<<"\n Ten sinh vien: ";
				gets(hoten);
			}
			void in()
			{
				cout<<"\n\t "<<ma<<"\t "<<hoten;
			}
	};
	class supham: public sinhvien
	{
		protected: 
			int dtb,hocbong;
		public:
			supham(){}
			void nhap1()
			{
				cout<<"\n Diem trung binh: ";
				cin>>dtb;
				cout<<"\n Hoc bong: ";
				cin>>hocbong;
			}
			int getdtb()
			{
				return dtb;
			}
			void in1()
			{
				sinhvien::in();
				cout<<"\t "<<dtb<<"\t "<<hocbong;
			}
	};
	class cunhan: public supham
	{
		int hocphi;
		public:
			cunhan(){}
			void nhap2()
			{
				cout<<"\n Hoc phi: ";
				cin>>hocphi;
			}
			void in2()
			{
				supham::in1();
				cout<<"\t "<<hocphi;
			}
			int operator >(cunhan &d)
			{
				if(dtb>d.dtb)
					return 1;
					return 0;
			}
	};
int main()
{
	cunhan s[100];
	int n,i,max;
	cout<<"\n Nhap so sinh vien: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		s[i].nhap();
		s[i].nhap1();
		s[i].nhap2();
	}
	cout<<"\n\t MaSV\t HoTen\t DTB\t HocBong HocPhi";
	for(i=0;i<n;i++)
	{
		s[i].in2();
	}
	cout<<"\n Danh sach sinh vien co DTB cao nhat ";
	max=s[0].getdtb();
	for(i=1;i<n;i++)
	{
		if(s[i].getdtb()>max)
			max=s[i].getdtb();
				for(i=0;i<n;i++)
					if(s[i].getdtb()==max)
						s[i].in2();
	}
	

	getch();
}
