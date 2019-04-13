#include<conio.h>
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
	class nhanvien
	{
		char *hoten, *diachi;
		int sdt;
		public:
			nhanvien *next;
			nhanvien(){}
			nhanvien(char *ht, char *dc, int s)
			{
				hoten=new char[strlen(ht)+1];
				diachi=new char[strlen(dc)+1];
				strcpy(hoten,ht);
				strcpy(diachi,dc);
				sdt=s;
			}
			char *gethoten()
			{
				return hoten;
			}
			char *getdiachi()
			{
				return diachi;
			}
			int getsdt()
			{
				return sdt;
			}
			void get(char *ht, char *dc, int s)
			{
				hoten=new char[strlen(ht)+1];
				diachi=new char[strlen(dc)+1];
				strcpy(hoten,ht);
				strcpy(diachi,dc);
				sdt=s;
			}
	};
	class danhba
	{
		private: 
			nhanvien *first;
		public:
			danhba()
			{
				first=NULL;
			}
			void nhap()
			{
				char ht[50],dc[50];
				int s;
				do
				{
					cout<<"\n Ho ten: ";
					fflush(stdin);
					gets(ht);
					if(strcmp(ht,"")!=0)
					{
						cout<<"\n Dia chi: ";
						gets(dc);
						cout<<"\n So dien thoai: ";
						cin>>s;
						nhanvien *p=new nhanvien(ht,dc,s);
							p->next=first;
							first=p;
					}
				}while(strcmp(ht,"")!=0);
			}
			void in()
			{
				nhanvien *p=first;
				cout<<"\n\t HoTen\t DiaChi\t SDT ";
				while(p!=NULL)
				{
					cout<<"\n\t "<<p->gethoten()<<"\t "<<p->getdiachi()<<"\t "<<p->getsdt();
					p=p->next;
				}
			}
			void sapxep()
			{
				nhanvien *p,*r;
				char ht[50],dc[50];
				int s;
				if(first!=NULL)
					for(p=first;p->next!=NULL;p=p->next)
					for(r=p->next;r!=NULL;r=r->next)
						if(strcmp(p->gethoten(),r->gethoten())>0)
						{
							strcpy(ht,p->gethoten());
							strcpy(dc,p->getdiachi());
							s=p->getsdt();
							p->get(r->gethoten(),r->getdiachi(),r->getsdt());
							r->get(ht,dc,s);
						}
			}
			void xoa(char *r)
			{
				while(first!=NULL&&strcmp(first->gethoten(),r)==0)
				{
					nhanvien *x = first;
						first=first->next;
						delete(x);
				}
				if(first!=NULL)
				{
					nhanvien *p=first;
					while(p->next!=NULL)
					{
						if(strcmp(p->next->gethoten(),r)==0)
						{
							nhanvien *x=p->next;
									p->next=p->next->next;
									delete(x);
						}
						else
							p=p->next;
					}
				}
			}
			void bosung(nhanvien *r)
			{
				r->next=first;
				first=r;
			}

	};
int main()
{
	danhba d;
	d.nhap();
	d.in();
	cout<<"\n Danh sach sau khi sap xep ";
	d.sapxep();
	d.in();
	char ht[50];
	cout<<"\n Ho ten muon xoa: ";
	gets(ht);
	d.xoa(ht);
	d.in();
	char ht1[50],dc[50];
	int s;
	cout<<"\n Bo sung 1 nhan vien ";
	cout<<"\n Ho ten: ";
	fflush(stdin);
	gets(ht1);
	cout<<"\n Dia chi: ";
	gets(dc);
	cout<<"\n So dien thoai: ";
	cin>>s;
	nhanvien *p=new nhanvien(ht1,dc,s);
	d.bosung(p);
	cout<<"\n Sau khi bo sung ";
	d.in();
	getch();
}
