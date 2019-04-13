#include<conio.h>
#include<stdio.h>
#include<iostream>
using namespace std;
	class sach
	{
		char ma[50], ten[50], tacgia[50], nhaxb[50];
		int namxb;
		public: 
			void nhap()
			{
				cout<<"\n Ma sach: ";
				fflush(stdin);
				gets(ma);
				cout<<"\n Ten sach: ";
				gets(ten);
				cout<<"\n Tac gia: ";
				gets(tacgia);
				cout<<"\n Nha xuat ban: ";
				gets(nhaxb);
				cout<<"\n Nam xuat ban: ";
				cin>>namxb;
			}
			void in()
			{
				cout<<"\n\t "<<ma<<"\t "<<ten<<"\t "<<tacgia<<"\t "<<nhaxb<<"\t "<<namxb;
			}
			int getnamxb()
			{
				if(namxb>2000)
					return 1;
					return 0;
			}
	};
int main()
{
	sach s[50];
	int n,i;
	cout<<"\n Nhap so luong sach: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		s[i].nhap();
	}
	cout<<"\n\t MaSach\t TenSach TacGia\t NhaXB\t NamXB ";
	for(i=0;i<n;i++)
	{
		if(s[i].getnamxb()==1)
			s[i].in();
	}
	getch();
}
