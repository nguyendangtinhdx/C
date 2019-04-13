#include<conio.h>
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
	class sphere
	{
		int r;
		int x,y,z;
		public:
			void nhap()
			{
				cout<<"\n Hoanh do x = ";
				cin>>x;
				cout<<"\n Tung do y = ";
				cin>>y;
				cout<<"\n Cao do z = ";
				cin>>z;
				cout<<"\n Ban kinh r = ";
				cin>>r;
			}
			void in()
			{
				cout<<"\n Toa do la: ("<<x<<","<<y<<","<<z<<")"<<"\t Ban kinh = "<<r;
			}
			int dientich()
			{
				return 4*3.14*r*r;
			}
	};
int main()
{
	sphere s[50];
	int n,i;
	cout<<"\n Nhap so hinh cau: ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		s[i].nhap();
	}
	for(i=0;i<n;i++)
	{
		s[i].in();
	}
	cout<<"\n Nhung hinh cau co S max: ";
	int max=s[0].dientich();
	for(i=0;i<n;i++)
		if(s[i].dientich()>max)
			max=s[i].dientich();
			for(i=0;i<n;i++)
				if(s[i].dientich()==max)
					s[i].in();
	getch();
}
