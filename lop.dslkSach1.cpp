#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
	class sach
	{
		char *ma, *ten;
		int namxb;
		public: 
			sach *next;
			sach(char *m, char *t, int nam)
			{
				ma= new char[strlen(m)+1];
				ten= new char[strlen(t)+1];
				strcpy(ma,m);
				strcpy(ten,t);
				namxb=nam;
			}
			char *getma()
			{
				return ma;
			}
			char *getten()
			{
				return ten;
			}
			int getnamxb()
			{
				return namxb;
			}
			int nam()
			{
				if(namxb>2000)
					return 1;
					return 0;
			}
			void get(char *m, char *t, int nam)
			{
				ma= new char[strlen(m)+1];
				ten= new char[strlen(t)+1];
				strcpy(ma,m);
				strcpy(ten,t);
				namxb=nam;
			}
	};
	class list
	{
		sach *first;
		char ma[50], ten[50];
		int namxb;
		public:
			list()
			{
				first=NULL;
			}
			void nhap()
			{
				do
				{
					cout<<"\n Ma sach: ";
					fflush(stdin);
					gets(ma);
					if(strcmp(ma,"")!=0)
					{
						if(tim(ma)==NULL)			
						{
							cout<<"\n Ten sach: ";
							gets(ten);
							cout<<"\n Nam xuat ban: ";
							cin>>namxb;
							sach *p = new sach(ma,ten,namxb);
							p->next=first;
							first=p;
						}
					}
				}while(strcmp(ma,"")!=0);
			}
			void in()
			{
				cout<<"\n\t MaSach\t TenSach NamXB ";
				sach *p=first;
				while(p!=NULL)
				{
				//	if(p->nam()==1)
					{
						cout<<"\n\t "<<p->getma()<<"\t "<<p->getten()<<"\t "<<p->getnamxb();
					}
					p=p->next;
				}
			}
			sach *tim(char *m)
			{
				sach *p=first;
				while(p!=NULL&&strcmp(p->getma(),m)!=0)
					p=p->next;
				return p;
			}
			void sapxep()
			{
				sach *p,*q;
				char m[50],t[50];
				int n;
				if(first!=NULL)
					for(p=first;p->next!=NULL;p=p->next)
						for(q=p->next;q!=NULL;q=q->next)
							if(strcmp(p->getma(),q->getma())>0)
							{
								strcpy(m,p->getma());
								strcpy(t,p->getten());
								n=p->getnamxb();
								p->get(q->getma(),q->getten(),q->getnamxb());
								q->get(m,t,n);
							}
			}
			void xoa(char *r)
			{
				while(first!=NULL&&strcmp(first->getma(),r)==0)
				{
					sach *x = first;
					first=first->next;
					delete(x);
				}
				if(first!=NULL)
				{
					sach *p=first;
					while(p->next!=NULL)
					{
						if(strcmp(p->next->getma(),r)==0)
						{
							sach *x = p->next;
							p->next=p->next->next;
							delete(x);
						}
						else
							p=p->next;
					}
				}
			}
			void bosung(sach *p)
			{
				p->next=first;
				first=p;	
			}
	};
int main()
{
	list s;
	s.nhap();
	s.in();
	char m[50];
	cout<<"\n Nhap ma can tim: ";
	gets(m);
	sach *p=s.tim(m);
	if(p!=NULL)
	{
		cout<<"\n Da tim thay ";
	}
	else
	{
		cout<<"\n Khong tim thay ";
	}
	cout<<"\n Sau khi sap xep: ";
	s.sapxep();
	s.in();
	char mm[50];
	cout<<"\n Nhap ma can xoa: ";
	gets(mm);
	s.xoa(mm);
	cout<<"\n Sau khi xoa: ";
	s.in();
	char ma[50],ten[50];
	int namxb;
	cout<<"\n Bo sung 1 cuon sach: ";
	cout<<"\n Ma sach: ";
	gets(ma);
	cout<<"\n Ten sach: ";
	gets(ten);
	cout<<"\n Nam xuat ban: ";
	cin>>namxb;
	sach *q=new sach(ma,ten,namxb);
	s.bosung(q);
	cout<<"\n Sau khi bo sung: ";
	s.in();
	getch();
}
