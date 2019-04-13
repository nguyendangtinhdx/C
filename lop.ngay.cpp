#include<conio.h>
#include<iostream>
using namespace std;
	class date
	{
		int d,m,y;
		public:
			int nhuan()
			{
				return (y%4==0&&y%100!=0||y%400==0);
			}
			int thang()
			{
				return (m==4||m==6||m==9||m==11)?30:(m==2)?28+nhuan():31;
			}
			int thang1()
			{
				return (m==5||m==7||m==10||m==12)?30:(m==3)?28+nhuan():31;
			}
			void nhap()
			{
				int s,k;
				do
				{
					cout<<"\n Ngay: ";
					cin>>d;
					cout<<"\n Thang: ";
					cin>>m;
					cout<<"\n Nam: ";
					cin>>y;			
					s=thang();
					if((d>0&&d<=s)&&(m>0&&m<=12)&&y>0)
						k=1;
					else
					{
						cout<<"\n Ngay khong hop le !";
						k=0;
					}
				}while(k==0);
			}
			int ngay()
			{
				return nhuan()?366:365;
			}
			void in()
			{
				cout<<"\n Ngay-Thang-Nam: "<<d<<"-"<<m<<"-"<<y;
			}
			date next()
			{
				if(++d>thang())
				{
					d=1;
					if(++m>12)
					{
						m=1;
						y++;
					}
				}
				return *this;
			}
			date before()
			{
				if(d-1==0)
				{
					d=thang1();
					if(m==1)
					{
						m=12;
						y--;
					}
					else
					{
						m--;
					}
				}
				else
					d--;
				return *this;
			}
			int sosanh(date s)
			{
				return (y>s.y)?1:(y<s.y)?-1:(m>s.m)?1:(m<s.m)?-1:(d>s.d)?1:(d<s.d)?-1:0;
			}
	};
int main()
{
	date n,n1;
	n.nhap();
	n.in();
/*	cout<<"\n Ngay tiep theo la: ";
	n.next();
	n.in();
	cout<<"\n Ngay hom truoc la: ";
	n.before();
	n.before();
	n.in();
	cout<<"\n So ngay cua nam do la: "<<n.ngay();*/
	
	n1.nhap();
	n1.in();	
	if(n.sosanh(n1)==1)
	{
		cout<<"\n Truoc > Sau ";
	}
	else if(n.sosanh(n1)==-1)
	{
		cout<<"\n Truoc < Sau ";
	}
	else
		cout<<"\n Truoc = Sau ";
	getch();
}
