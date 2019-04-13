#include<conio.h>
#include<iostream>
#include<math.h>
using namespace std;
	class diem
	{
		private: float x,y;
		public: 
		void nhap()
		{
			cout<<"\n Hoanh Do: ";
			cin>>x;	
			cout<<"\n Tung Do: ";
			cin>>y;
		}
		void in()
		{
			cout<<"\n x = "<<x;
			cout<<"\n y = "<<y;
		}
		float kc(diem d1, diem d2)
		{
			return sqrt(pow(d1.x-d2.x,2)+pow(d1.y-d2.y,2));
		}
		float getx()
		{
			return x;
		}
		float gety()
		{
			return y;
		}
	};
int main()
{
	float max,max1;
	int n,i;
	diem k1,k2,d[50];
	k1.nhap();
	k1.in();
	k2.nhap();
	k2.in();
	cout<<"\n Khoang cach giua 2 diem = "<<k1.kc(k1,k2);
	max=(k1.getx()>k1.gety())?k1.getx():k1.gety();
	cout<<"\n Max Hoanh do Tung do = "<<max;
	cout<<"\n Nhap n = ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		d[i].nhap();
	}
	max1=d[0].getx();
	for(i=1;i<n;i++)
		if(d[i].getx()>max1)
			max1=d[i].getx();
	cout<<"\n Max Hoanh Do la: "<<max1;
	getch();
}
