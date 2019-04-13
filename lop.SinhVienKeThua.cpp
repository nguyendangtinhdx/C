#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
	class sinhvien
	{
		char ten[50];
		protected:
			int sbd;
		public:
			void nhap()
			{
				fflush(stdin);
				cout<<"\n Ten: "; gets(ten); 
				cout<<"\n So ban danh: "; cin>>sbd;
			}
			void in()
			{
				cout<<"\n\t Ten\t SBD\t Mon1\t Mon2\t UuTien";
				cout<<"\n\t "<<ten<<"\t "<<sbd;
			}
	};
	class diem: public sinhvien
	{
		protected:
			float d1,d2;
		public:
			void nhap1()
			{
				cout<<"\n Mon 1: "; cin>>d1;
				cout<<"\n Mon 2: "; cin>>d2;
			}
			void in1()
			{
		//		cout<<"\t Mon1\t Mon2 ";
				cout<<"\t "<<d1<<"\t "<<d2;
			}
	};
	class uutien
	{
		protected: 
			float u;
		public:
			void nhap2()
			{
				cout<<"\n Nhap diem uu tien: "; cin>>u;
			}
			void in2()
			{
				cout<<"\t "<<u;
			}
	};
	class ketqua: public diem, public uutien
	{
		float s;
		public:
			void tong()
			{
				s = d1+d2+u;
				in();
				in1();
				in2();
				cout<<"\n Tong diem la: "<<s;
			}
	};
int main()
{
	int i,n;
	ketqua sv[100];
	cout<<"\n Nhap so sinh vien: "; cin>>n;
	for(i=0;i<n;i++)
	{
		sv[i].nhap();
		sv[i].nhap1();
		sv[i].nhap2();				
	}
	for(i=0;i<n;i++)
	{
		sv[i].tong();		
	}
	getch();
}
