#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<string.h>
using namespace std;
	class thuvien
	{
		char ma[50], ten[50];
		long sdt;
		public:
			thuvien *next;
			thuvien(){}
			thuvien(char *m, char *t, long s)
			{
				strcpy(ma,m);
				strcpy(ten,t);
				sdt=s;
			}
			void nhap()
			{
				cout<<"\n Ma: ";
				fflush(stdin);
				gets(ma);
				cout<<"\n Ten: ";
				gets(ten);
				cout<<"\n SDT: ";
				cin>>sdt;
			}
			void in()
			{
				cout<<"\n\t "<<ma<<"\t "<<ten<<"\t "<<sdt;
			}
			char *getma()
			{
				return ma;
			}
			char *getten()
			{
				return ten;
			}
			long getsdt()
			{
				return sdt;
			}
			void get(char *m, char *t, long s)
			{
				strcpy(ma,m);
				strcpy(ten,t);
				sdt=s;
			}
	};
	class qldg
	{
		thuvien *first;
		public:
			qldg()
			{
				first=NULL;
			}
			void bosung(thuvien *p)
			{
				p->next=first;
				first=p;
			}
			void inds()
			{
				thuvien *p=first;
				cout<<"\n\t Ma\t Ten\t SDT ";
				while(p!=NULL)
				{
					p->in();
					p=p->next;
				}
			}
			thuvien *tim(char *ma)
			{
				thuvien *p=first;
				while(p!=NULL&&strcmp(p->getma(),ma)!=0)
					p=p->next;
					return p;
			}
			void xoa(char *ma)
			{
				thuvien *p=tim(ma);
				if(p!=NULL)
				{
					if(p==first)
					{
						first=first->next;
						delete(p);
					}
					else
					{
						thuvien *q=first,*t;
						while(q!=NULL&&q!=tim(ma))
						{
							t=q;
							q=q->next;
						}
						t->next=p->next;
						delete(p);
					}
				}
			}
			void sapxep()
			{
				char m[50], t[50];
				long s;
				thuvien *p,*q;
				if(first!=NULL)
					for(p=first;p->next!=NULL;p=p->next)
					for(q=p->next;q!=NULL;q=q->next)
						if(strcmp(p->getma(),q->getma())>0)
						{
							strcpy(m,p->getma());
							strcpy(t,p->getten());
							s=p->getsdt();
							p->get(q->getma(),q->getten(),q->getsdt());
							q->get(m,t,s);
						}
			}
	};
int main()
{
	qldg q;
	char ma[50], ten[50];
	long sdt;
	do
	{
		cout<<"\n Ma: ";
		fflush(stdin);
		gets(ma);
		if(strcmp(ma,"")!=0)
		{
			if(q.tim(ma)==NULL)
			{
				cout<<"\n Ten: ";
				gets(ten);
				cout<<"\n SDT: ";
				cin>>sdt;
				thuvien *p=new thuvien(ma,ten,sdt);
				q.bosung(p);
			}
		}
	}while(strcmp(ma,"")!=0);
	q.inds();
	cout<<"\n Nhap ma muon xoa: ";
	gets(ma);
	q.xoa(ma);
	q.inds();
	cout<<"\n Nhap ma muon tim: ";
	gets(ma);
	thuvien *r=q.tim(ma);
	if(r!=NULL)
		cout<<"\n Tim thay ";
	else
		cout<<"\n Khong tim thay ";
	char m[50], t[50];
	long s;
	cout<<"\n Bo sung 1 thu vien: ";
	cout<<"\n Ma: ";
	gets(m);
	cout<<"\n Ten: ";
	gets(t);
	cout<<"\n SDT: ";
	cin>>s;
	thuvien *y=new thuvien(m,t,s);
	q.bosung(y);
	q.inds();
	q.sapxep();
	cout<<"\n Sau khi sap xep ";
	q.inds();
	getch();
}
