#include<conio.h>
#include<math.h>
#include<iostream>
using namespace std;
	class dathuc
	{
		int heso[50],bac,i;
		public:
			void nhap()
			{
				cout<<"\n Bac: ";cin>>bac;
				for(i=bac;i>=0;i--)
				{
					cout<<"\n He so bac "<<i<<" :";cin>>heso[i];
				}
			}
			void in()
			{
				for(i=bac;i>=0;i--)
				{
					if(heso[i]>0)
					{
						cout<<heso[i]<<"x^"<<i<<" + ";
					}
					else
					{
						cout<<heso[i]<<"x^"<<i<<" + ";
					}
				}
			}
			dathuc operator +(dathuc d2)
			{
				dathuc c;
				if(bac>d2.bac)
				{
					c.bac=bac;
					for(i=0;i<=d2.bac;i++)
					c.heso[i]=heso[i] + d2.heso[i];
					for(i=d2.bac+1;i<=bac;i++)
					c.heso[i]=heso[i];
				}
				else
				{
					c.bac=d2.bac;
					for(i=0;i<=d2.bac;i++)
					c.heso[i]=heso[i] + d2.heso[i];
					for(i=bac+1;i<=d2.bac;i++)
					c.heso[i]=d2.heso[i];
				}
				return c;
			}
	};
int main()
{
	dathuc d1, d2, d;
	d1.nhap();
	d1.in();
	d2.nhap();
	d2.in();
	d=d1+d2;
	cout<<"\n Sau khi cong: ";
	d.in();
	getch();
}
