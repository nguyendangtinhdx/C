#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
#include<iostream>
using namespace std;
	class hocphan
	{
		private:
			char *mahp,*tenhp;
			int sotc;
		public:
			hocphan *next;
		hocphan(char *ma, char *ten, int so)
		{
			mahp=new char[strlen(ma)+ 1];
			tenhp=new char [strlen(ten) +1];
			strcpy(mahp,ma);
			strcpy(tenhp,ten);
			sotc=so;
		}
		char *getmahp()
		{
			return mahp;
		}
		char *gettenhp()
		{
			return tenhp;
		}
		int getsotc()
		{
			return sotc;
		}
		void get(char *ma, char *ten, int so )
		{
			mahp=new char[strlen(ma)+ 1];
			tenhp=new char [strlen(ten) +1];
			strcpy(mahp,ma);
			strcpy(tenhp,ten);
			sotc=so;
		}
	};
	class list
	{
		private:
			hocphan *first;
		public:
			list()
			{
				first=NULL;
			}
			void nhap();
			void in();
			void sapxep();
			hocphan *tim(char *m);
			void xoa(char *m);
	};
void list::nhap()
{
	char ma[50],ten[50];
	int so;
	do
	{
		cout<<"\n Ma hoc phan: ";
		fflush(stdin);
		gets(ma);
		if(strcmp(ma,"")!=0)
		{
			cout<<"\n Ten hoc phan: ";
			fflush(stdin);
			gets(ten);
			cout<<"\n So tin chi: ";
			cin>>so;
			hocphan *x = new hocphan(ma,ten,so);
			x->next=first;
			first=x;
		}
	}while(strcmp(ma,"")!=0);
}
void list::in()
{
	hocphan *p=first;
	cout<<"\n\t TenHP\t MaHP\t SoTC "<<endl;
	while(p!=NULL)
	{
		cout<<"\n\t "<<p->getmahp()<<"\t "<<p->gettenhp()<<"\t "<<p->getsotc();
		p=p->next;
	}
}
void list::sapxep()
{
	hocphan *q,*p;
	char xm[50],xt[50];
	int xs;
	if(first!=NULL)
		for(p=first;p->next!=NULL;p=p->next)
		for(q=p->next;q!=NULL;q=q->next)
			if(strcmp(p->getmahp(),q->getmahp())>0)
			{
				strcpy(xm,p->getmahp());
				strcpy(xt,p->gettenhp());
				xs=p->getsotc();
				p->get(q->getmahp(),q->gettenhp(),q->getsotc());
				q->get(xm,xt,xs);
			}
}
hocphan *list::tim(char *m)
{
	hocphan *p=first;
	while(p!=NULL&&strcmp(p->getmahp(),m)!=0)
		p=p->next;
		return p;
}
void list::xoa(char *m)
{
	while(first!=NULL&&strcmp(first->getmahp(),m)==0)
	{
		hocphan *x = first;
		first=first->next;
		delete x;
	}
	if(first!=NULL)
	{
		hocphan *p=first;
		while(p->next!=NULL)
			if(strcmp(p->next->getmahp(),m)==0)
			{
				hocphan *x = p->next;
				p->next=p->next->next;
				delete x;
			}
			else
				p=p->next;
	}
}
int main()
{
	list s;
	s.nhap();
	s.in();
	s.sapxep();
	cout<<"\n Danh sach sau khi sap xep: ";
	s.in();
	char m[50],xm[50];
	cout<<"\n Nhap Ma hoc phan muon tim: ";
	gets(m);
	hocphan *p=s.tim(m);
	if(p!=NULL)
	{
		cout<<"\n Da tim thay hoc phan: ";
		cout<<"\n\t TenHP\t MaHP\t SoTC "<<endl;
		cout<<"\n\t "<<p->getmahp()<<"\t "<<p->gettenhp()<<"\t "<<p->getsotc();
	}
	else
		cout<<"\n Khong tim thay hoc phan ";
	cout<<"\n Nhap Ma hoc phan muon xoa: ";
	gets(xm);
	s.xoa(xm);
	cout<<"\n Danh sach sau khi xoa: ";
	s.in();
}
