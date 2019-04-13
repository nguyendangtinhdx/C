#include<conio.h>
#include<iostream>
#include<math.h>
using namespace std;
	class time
	{
		int h,m,s;
		public:
			time();
			time(int g, int tp, int gi);
			void nhap();
			void in();
			time chuanhoa();
			int operator <(time b);
			time operator +=(int n);
			int operator -(time b);
			time operator+(time t2);
			time operator++();
	};
time::time()
{
	h=m=s=0;
}
time::time(int g,int p, int gi)
{
	h=g;m=p;s=gi;
}
void time::nhap()
{
	cout<<"\n Nhap gio: ";
	cin>>h;
	cout<<"\n Nhap phut: ";
	cin>>m;
	cout<<"\n Nhap giay: ";
	cin>>s;
}
void time::in()
{
	cout<<"\n Gio:phut:giay: "<<h<<":"<<m<<":"<<s;
}
time time::chuanhoa()
{
	if(s>=60)
	{
		m=s/60+m;
		s=s%60;
	}
	if(m>=60)
	{
		h=m/60+h;
		m=m%60;
	}
	return *this;
}
int time::operator <(time b)
{
	if((h*3600+m*60+s - b.h*3600+b.m*60+b.s)<0)
		return 1;
		return 0;
}
time time::operator+=(int b)
{
	s+=b;
	chuanhoa();
	return *this;
}
int time::operator -(time b)
{
	return ((h*3600+m*60+s) - (b.h*3600+b.m*60+b.s));
}
time time::operator+(time t2)
{
	time t;
	t.h=h+t2.h;
	t.m=m+t2.m;
	t.s=s+t2.s;
	return t;
}
time time::operator++()
{
	++h;
	return *this;
}
int main()
{
	time t,p,c,s;
	t.nhap();
	t.chuanhoa();
	t.in();
	p.nhap();
	p.chuanhoa();
	p.in();
	if(t<p)
	{
		cout<<"\n Sau > ";
	}
	else
	{
		cout<<"\n Truoc > ";
	}
	int b;
	cout<<"\n Nhap so giay cong them: ";
	cin>>b;
	t+=b;
	cout<<"\n Sau khi cong: ";
	t.in();
	cout<<"\n Nhap time muon tru: ";
	c.nhap();
	c.chuanhoa();
	c.in();
	int x;
	x=t-c;
	cout<<"\n Sau khi tru: "<<x;
	cout<<"\n Nhap time muon cong: ";
	c.nhap();
	c.chuanhoa();
	c.in();
	s=t+c;
	cout<<"\n Sau khi cong: ";
	s.in();
	cout<<"\n Sau khi tang gio len 1 don vi: ";
	++t;
	t.in();
	getch();
}

