#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>
#include<iomanip>
using namespace std;
	struct sv
	{
		char ma[50],ht[50];
		int lop;
		float dtb;
		sv *next;
	};
int trungma(sv *f,char ms[])
{
	sv *p;
	for(p=f;p!=NULL;p=p->next)
	{
		if(strcmp(p->ma,ms)==0)
		{
			cout<<"\n Ma trung, xin nhap lai ! ";
			return 1;
		}
	}
	return 0;
}
sv *nhap(sv *f)
{
	char s[50];
	sv *p;
	do
	{
		do
		{
			printf("\n Ma SV: ");
			fflush(stdin);
			gets(s);
		//	cout<<"\n Ma SV: ";
		//	cin.ignore(1);
		//	cin.get(s,30);
		}while(trungma(f,s));
			if(strcmp(s,"")==0)
				break;
			else
			{
				p=new(sv);
				strcpy(p->ma,s);
				cout<<"\n Ho Ten: ";
				cin.get(p->ht,50);
				cout<<"\n Lop: ";
				cin>>p->lop;
				cout<<"\n Diem TB: ";
				cin>>p->dtb;
			}
		p->next=f;
		f=p;
	}while(1);
	return f;
}
void in(sv *f)
{
	sv *p;
	cout<<"\n\tMaSV\tHoTen\tLop\tDTB ";
	cout<<setiosflags(ios::showpoint)<<setprecision(3);
	for(p=f;p!=NULL;p=p->next)
		cout<<"\n\t"<<p->ma<<"\t"<<p->ht<<"\t"<<p->lop<<"\t"<<p->dtb;
}
void sapxep(sv *f)
{
	sv *p,*q;
	char m[50],t[50];
	int l;
	float d;
	for(p=f;p!=NULL;p=p->next)
		for(q=p->next;q!=NULL;q=q->next)
			if(p->dtb<q->dtb)
			{
				strcpy(m,p->ma);
				strcpy(p->ma,q->ma);
				strcpy(q->ma,m);
				strcpy(t,p->ht);
				strcpy(p->ht,q->ht);
				strcpy(q->ht,t);
				l=p->lop;
				p->lop=q->lop;
				q->lop=l;
				d=p->dtb;
				p->dtb=q->dtb;
				q->dtb=d;
			}
}
int main()
{
	sv *f;
	f=NULL;
	f=nhap(f);
	in(f);
	sapxep(f);
	cout<<"\n Danh sach sap xep ttt giam dan DTB: ";
	in(f);
	getch();
}
