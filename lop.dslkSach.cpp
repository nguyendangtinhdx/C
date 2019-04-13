#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
#include<iostream>
using namespace std;
	class sach 
	{
		private:
			char *ma,*ten,*tacgia;
			int nam;
		public:
			sach *next;
		sach(char *m, char *t, char *tg, int n)
		{
			ma=new char[strlen(m) +1];
			ten=new char[strlen(t) +1];
			tacgia=new char[strlen(tg) +1];
			strcpy(ma,m);
			strcpy(ten,t);
			strcpy(tacgia,tg);
			nam=n;
		}
		char *getma()
		{
			return ma;
		}
		char *getten()
		{
			return ten;
		}
		char *gettacgia()
		{
			return tacgia;
		}
		int getnam()
		{
			return nam;
		}
	};
	class list
	{
		private:
			sach *first;
		public:
			list()
			{
				first=NULL;
			}
			void nhap();
			void in();
			sach *bosung(char *xm, char *xt, char *xtg, int xn);
			void hienthi();
			sach *tim(char *xm);
			void xoa(char *xm);
	};
void list::nhap()
{
	char m[50],t[50],tg[50];
	int n;
	do
	{
		cout<<"\n Ma sach: ";
		fflush(stdin);
		gets(m);
		if(strcmp(m,"")!=0)
		{
			cout<<"\n Ten sach: ";
			gets(t);
			cout<<"\n Ten tac gia: ";
			gets(tg);
			cout<<"\n Nam xuat ban: ";
			cin>>n;
			sach *x = new sach(m,t,tg,n);
			x->next=first;
			first=x;
		}
	}while(strcmp(m,"")!=0);
}
void list::in()
{
	sach *p=first;
	cout<<"\n\t MaSach\t TenSach TenTG\t NamXB "<<endl;
	while(p!=NULL)
	{
		cout<<"\n\t "<<p->getma()<<"\t "<<p->getten()<<"\t "<<p->gettacgia()<<"\t "<<p->getnam();
		p=p->next;
	}
}	
void list::hienthi()
{
	sach *p=first;
	cout<<"\n\t MaSach\t TenSach TenTG\t NamXB "<<endl;
	while(p!=NULL)
	{
		if(p->getnam()>2008)
			cout<<"\n\t "<<p->getma()<<"\t "<<p->getten()<<"\t "<<p->gettacgia()<<"\t "<<p->getnam();
			p=p->next;
	}
}
sach *list::tim(char *m)
{
	sach *p=first;
	while(p!=NULL&&strcmp(p->getma(),m)!=0)
		p=p->next;
		return p;
}
void list::xoa(char *m)
{
	while(first!=NULL&&strcmp(first->getma(),m)==0)
	{
		sach *x=first;
		first=first->next;
		delete x;
	}
	if(first!=NULL)
	{
		sach *p=first;
		while(p->next!=NULL)
		{
			if(strcmp(p->next->getma(),m)==0)
			{
				sach *x=p->next;
				p->next=p->next->next;
				delete x;
			}
			else
				p=p->next;
		}
	}
}
int main()
{
	list s;
	s.nhap();
	s.in();
	cout<<"\n Nhung cuon sach co Nam xuat ban sau nam 2008: ";
	s.hienthi();
	char m[50];
	cout<<"\n Nhap Ma sach muon tim: ";
	gets(m);
	sach *p = s.tim(m);
	if(p!=NULL)
	{
		cout<<"\n Da tim thay sach: ";
		cout<<"\n\t MaSach\t TenSach TenTG\t NamXB "<<endl;
		cout<<"\n\t "<<p->getma()<<"\t "<<p->getten()<<"\t "<<p->gettacgia()<<"\t "<<p->getnam();
	}
	else
		cout<<"\n Khong tim thay sach ";
	char xm[50];
	cout<<"\n Nhap Ma sach muon xoa: ";
	gets(xm);
	s.xoa(xm);
	cout<<"\n Danh sach sau khi xoa: ";
	s.in();
	getch();
}
