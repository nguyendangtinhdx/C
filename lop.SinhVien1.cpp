#include<conio.h>
#include<iostream>
#include<stdio.h>
using namespace std;
	class sinhvien
	{
		char *ma,*hoten;
		public:
			sinhvien(char *t=NULL, char *l=NULL)
			{
				ma=new char[strlen(t)+1];
				hoten=new char[strlen(l)+1];
				strcpy(ma,t);
				strcpy(hoten,l);
			}
		virtual	void in()
			{
				cout<<"\n MaSV: "<<ma;
				cout<<"\n HoTenSV: "<<hoten;
			}
	};
	class supham: public sinhvien
	{
		protected: 
			int dtb,hocbong;
		public:
			supham(char *t=NULL, char *l=NULL, int hb=0,int diemtb=0):sinhvien(t,l)
			{
				dtb=diemtb;
				hocbong=hb;
			}
			void in()
			{
				sinhvien::in();
				cout<<"\n DiemTB: "<<dtb;
				cout<<"\n HocBong: "<<hocbong;
			}
	};
	class cunhan: public supham
	{
		int hocphi;
		public:
			cunhan(char *t=NULL, char *l=NULL, int hb=0,int diemtb=0,int hp=0):supham(t,l)
			{
				hocphi=hp;
			}
			void in()
			{
				supham::in();
				cout<<"\n Hoc phi: "<<hocphi;
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
	sinhvien *s[100];
	cunhan t;
	sinhvien v;
	supham sp;
	char ma[50],ht[50];
	int n,i,dtb,hb,hp;
	cout<<"\n Nhap so sinh vien: ";
	cin>>n;
	for(i=0;i<n;i++)
	{	
		cout<<"\n Ma sinh vien: ";
		fflush(stdin);
		gets(ma);
		cout<<"\n Ho ten sinh vien: ";
		gets(ht);
		cout<<"\n Diem trung binh: ";
		cin>>dtb;
		cout<<"\n Hoc bong: ";
		cin>>hb;
		cout<<"\n Hoc phi: ";
		cin>>hp;
		cunhan *p=new cunhan(ma,ht,hb,dtb,hp);
		s[i]=p;
	}
	for(i=0;i<n;i++)
	s[i]=&v;
	s[i]->in();
	s[i]=&sp;
	s[i]->in();
	s[i]=&t;
	s[i]->in();
	getch();
}
