#include<conio.h>
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
	class date
	{
		int  d,m,y;
		public:
		//	date *next;
			void nhap()
			{
				cout<<"\n Ngay: "; cin>>d;
				cout<<"\n Thang: "; cin>>m;
				cout<<"\n Nam: "; cin>>y;
			}
			void in()
			{
				cout<<"\t "<<d<<"-"<<m<<"-"<<y;
			}
			int gety()
			{
				return y;
			}
	};
	class nhanvien: public date
	{
		char ma[50], ten[50], diachi[50], quequan[50];
		nhanvien *first;
		public:
			nhanvien *next;
			nhanvien()
			{
				first=NULL;
			}
			nhanvien(char *m, char *t, char *d, char *q)
			{
				strcpy(ma,m);
				strcpy(ten,t);
				strcpy(diachi,d);
				strcpy(quequan,q);
			}
			char *getma()
			{
				return ma;
			}
			char *getten()
			{
				return ten;
			}
			char *getdc()
			{
				return diachi;
			}
			char *getqq()
			{
				return quequan;
			}
			void bosung(nhanvien *p)
			{
				p->next=first;
				first=p;
			}
			void nhap()
			{
				do
				{
					cout<<"\n Ma nhan vien: ";
					fflush(stdin);
					gets(ma);
					if(strcmp(ma,"")!=0)
					{
						cout<<"\n Ten nhan vien: ";
						gets(ten);
						date::nhap();
						cout<<"\n Dia chi: ";
						fflush(stdin);
						gets(diachi);
						cout<<"\n Que quan: ";
						gets(quequan);
						nhanvien *p=new nhanvien(ma,ten,diachi,quequan);
							p->next=first;
							first=p;
					}
				}while(strcmp(ma,"")!=0);
			}
			void inds()
			{
				nhanvien *p=first;
				cout<<"\n\t MaNV\t TenNV\t DiaChi  QueQuan D-M-Y";
				cout<<"\n\t "<<p->getma()<<"\t "<<p->getten()<<"\t "<<p->getdc()<<"\t "<<p->getqq();
				date::in();
			}
	};
int main()
{
	nhanvien n;
	n.nhap();
	n.inds();
	getch();
}
