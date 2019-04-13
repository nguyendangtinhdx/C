#include<conio.h>
#include<iostream>
#define k 50
using namespace std;
	class mang
	{
		int a[50],n,i;
		public:
			void nhap()
			{
			//	a = new int[k];
				cout<<"\n Nhap so phan tu: ";
				cin>>n;
				for(i=0;i<n;i++)
				{
					cout<<"\n a["<<i<<"] = ";
					cin>>a[i];
				}
			}
			void in()
			{
				int i;
				for(i=0;i<n;i++)
					cout<<"  "<<a[i];
			}
			mang tong(mang s2)
			{
				mang s;
				if(n!=s2.n)
				{
					cout<<"\n So phan tu != nhau ";
				}
				else			
					for(i=0;i<n;i++)
					{										
						s.a[i]=a[i]+s2.a[i];
					}
					s.n=n;
				return s;
			}
			mang operator ++()	// tien to
			{
				for(i=0;i<n;i++)
					a[i]++;
					return *this;
			}		
			mang operator ++(int)	// hau to
			{
				mang t;
				t=*this;
				for(i=0;i<n;i++)
					++*this;
					return t;
			}
			int operator ==(mang s2)
			{
				if(n!=s2.n)
				{
					cout<<"\n So phan tu ! nhau ";
				}
				else
				{
					for(i=0;i<n;i++)
						if(a[i]==s2.a[i])
						return 1;
						return 0;
				}
			}
	};
int main()
{
	mang s,s2,s1;
	s1.nhap();
	s1.in();
	s2.nhap();
	s2.in();
/*	s=s1.tong(s2);
	cout<<"\n Sau khi cong: ";
	s.in();
	++s1;
	cout<<"\n Sau khi tang: ";
	s1.in();
	s1++;
	cout<<"\n Sau khi tang: ";
	s1.in();*/
	if(s1==s2)
	{
		cout<<"\n Hai mang bang nhau ";
	}
	else
	{
		cout<<"\n Hai mang 0 bang nhau ";
	}
	getch();
}
