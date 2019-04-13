#include<conio.h>
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
	class thuvien
	{
		private:
			char ma[50],ten[500];
			int gia,nxb;
		public:
			void nhap()
			{
				cout<<"\n Ma sach: ";
				fflush(stdin);
				gets(ma);
				cout<<"\n Ten sach: ";
				gets(ten);
				cout<<"\n Nam xuat ban: ";
				cin>>nxb;
				cout<<"\n Gia: ";
				cin>>gia;
			}
			void in()
			{
				cout<<"\n\t "<<ma<<"\t "<<ten<<"\t "<<nxb<<"\t "<<gia;
			}
			char *getma()
			{
				return ma;
			}
			char *getten()
			{
				return ten;
			}
			int getnxb()
			{
				return nxb;
			}
			int getgia()
			{
				return gia;
			}

	};
int main()
{
	int i,j,n;
	thuvien sach[50];
	cout<<"\n Nhap so luong sach: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		sach[i].nhap();
	}
	cout<<"\n\t MaSach TenSach\t NXB\t Gia ";
	for(i=0;i<n;i++)
	{
		sach[i].in();
	}
/*	cout<<"\n Cac cuon sach co gia tien lon nhat: ";
	int max=sach[0].getgia();
	for(i=0;i<n;i++)
		if(sach[i].getgia()>max)
			max=sach[i].getgia();
			for(i=0;i<n;i++)
				if(sach[i].getgia()==max)
						sach[i].in();*/
						
	cout<<"\n Cac cuon sach co NXB > 2010: ";
	char m[50],t[50];
	int na,a1,g,k;
	for(i=0;i<n;i++)
	{
	//	if(sach[i].getnxb()>2010)
		{
		for(k=0;k<n-1;k++)
		for(j=k+1;j<n;j++)
			if(strcmp(sach[k].getma(),sach[j].getma())>0)
			{		
			strcpy(m,sach[k].getma());
			strcpy(sach[k].getma(),sach[j].getma());
			strcpy(sach[j].getma(),m);
			strcpy(t,sach[k].getten());
			strcpy(sach[k].getten(),sach[j].getten());
			strcpy(sach[j].getten(),t);
		/*	na=sach[k].getnxb();
			sach[k].getnxb()=sach[j].getnxb();
			sach[j].getnxb()=na;
			g=sach[k].getgia();
			sach[k].getgia()=sach[j].getgia();
			sach[j].getgia()=g;*/
			}		
		}
		cout<<"\n\t "<<sach[i].getma()<<"\t "<<sach[i].getten()<<"\t "<<sach[i].getnxb()<<"\t "<<sach[i].getgia();
		
	}
	getch();
}
