#include<conio.h>
#include<iostream>
#include<math.h>
using namespace std;
float x,y,bk,a,b,c;
float hcn(float x, float y,float &s,float &p)
{
	s= x*y;
	p=(x+y)*2;
}
float ht(float bk)
{
	return 3.14*bk*bk;
}
float htg(float a,float b,float c)
{
	if(a==b==c)
		return (pow(a,2)*sqrt(3))/4;
	if(a==b)
		return 0.5*c*sqrt(a*a-pow(c/2,2));
	if(b==c)
		return 0.5*a*sqrt(b*b-pow(a/2,2));
	if(c==a)
		return 0.5*b*sqrt(c*c-pow(b/2,2));
	if(a*a==b*b+c*c)
		return 0.5*b*c;
	if(b*b==a*a+c*c)
		return 0.5*a*c;
	if(c*c==a*a+b*b)
		return 0.5*a*b;
	else return 0;
}
int main()
{
	cout<<"\n Nhap x = ";
	cin>>x;
	cout<<"\n Nhap y = ";
	cin>>y;
	hcn(x,y,a,b);
	cout<<"\n S HCN = "<<a<<"\n P HCN = "<<b;
	cout<<"\n Nhap BK = ";
	cin>>bk;
	cout<<"\n S HT = "<<ht(bk);
	cout<<"\n Nhap canh a = ";
	cin>>a;
	cout<<"\n Nhap canh b = ";
	cin>>b;
	cout<<"\n Nhap canh c = ";
	cin>>c;
	cout<<"\n S HTG = "<<htg(a,b,c);
}
