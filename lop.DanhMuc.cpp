#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
	class danhmuc
	{
		char nhande[50],tacgia[50];
		protected:
			int sltk;
		public:
			danhmuc();
			void nhap();
			void in();
			virtual int khenthuong();
			int getthamkhao();
			char *gettacgia();
	};	
			danhmuc::danhmuc(){}
			void danhmuc::nhap()
			{
				cout<<"\n Nhan de: ";
				fflush(stdin);
				gets(nhande);
				cout<<"\n Tac gia: ";
				fflush(stdin);
				gets(tacgia);
				cout<<"\n So lan tham khao: ";
				cin>>sltk;
			}
			void danhmuc::in()
			{
				cout<<"\n Nhan de: "<<nhande;
				cout<<"\n Tac gia: "<<tacgia;
				cout<<"\n So lan tham khao: "<<sltk;
			}
			int danhmuc::khenthuong()
			{
				return 0;
			}
			int danhmuc::getthamkhao()
			{
				return sltk;
			}
			char * danhmuc::gettacgia()
			{
				return tacgia;
			}

	class sach: public danhmuc
	{
		char nhaxb[50];
		int lanin;
		public:
			sach();
			void nhap();
			void in();
			int khenthuong();
	};
			sach::sach(){}
			void sach::nhap()
			{
				danhmuc::nhap();
				cout<<"\n Nha xuat ban: ";
				fflush(stdin);
				gets(nhaxb);
				cout<<"\n Lan in: ";
				cin>>lanin;
			}	
			void sach::in()
			{
				danhmuc::in();
				cout<<"\n Nha xuat ban: "<<nhaxb;
				cout<<"\n Lan in: "<<lanin;
			}
			int sach::khenthuong()
			{
				if(sltk>20)
					return 1;
					return 0;
			}

	class tapchi: public danhmuc
	{
		char tentc[50];
		int sotc;
		public:
			tapchi();
			void nhap();
			void in();
			int khenthuong();
	};
			tapchi::tapchi(){}			
			void tapchi::nhap()
			{
				danhmuc::nhap();
				cout<<"\n Ten tap chi: ";
				fflush(stdin);
				gets(tentc);
				cout<<"\n So tap chi: ";
				cin>>sotc;
			}
			void tapchi::in()
			{
				danhmuc::in();
				cout<<"\n Ten tap chi: "<<tentc;
				cout<<"\n So tap chi: "<<sotc;
			}		
			int tapchi::khenthuong()
			{
				if(sltk>10)
					return 1;
					return 0;
			}
int main()
{
	danhmuc *ds[100];
	int i,n,tl;
	cout<<"\n Nhap so bai bao: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"\n Nhap loai danh muc: 1-sach; 2-tapchi: ";
		cin>>tl;
		if(tl==1)
		{
			sach *p=new sach;
			p->nhap();
			ds[i]=p;
		}
		else
		{
			tapchi *p=new tapchi;
			p->nhap();
			ds[i]=p;
		}
	}
	int max=ds[0]->getthamkhao();
	for(i=0;i<n;i++)
		if(max<ds[i]->getthamkhao())
			max=ds[i]->getthamkhao();
	for(i=0;i<n;i++)
		if(max==ds[i]->getthamkhao())
			ds[i]->in();
	for(i=0;i<n;i++)
		if(ds[i]->khenthuong()==1)
			cout<<ds[i]->gettacgia();
	getch();
}
