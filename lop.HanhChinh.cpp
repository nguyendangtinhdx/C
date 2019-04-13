#include<conio.h>
#include<stdio.h>
#include<iostream>
using namespace std;
class danhhieu
{
	char ten[50], ngaysinh[50], khoa[50];
public:
	void nhap()
	{
		cout << "\n Ten: ";
		fflush(stdin);
		gets(ten);
		cout << "\n Ngay sinh: ";
		gets(ngaysinh);
		cout << "\n Khoa: ";
		gets(khoa);
	}
	void in()
	{
		cout << "\n\t " << ten << "\t " << ngaysinh << "\t  " << khoa;
	}
	virtual int xeploai()
	{
		return 0;
	}
};
class giangday : public danhhieu
{
	int gio;
public:
	giangday(){}
	void nhap()
	{
		danhhieu::nhap();
			cout << "\n Gio: ";
		cin >> gio;
	}
	void in()
	{
		danhhieu::in();
			cout <<"\t "<< gio;
	}
	int xeploai()
	{
		if (gio >= 280)
			return 1;
		return 0;
	}
};
class hanhchinh : public danhhieu
{
	int gio;
public:
	void nhap()
	{
		danhhieu::nhap();
			cout << "\n Gio: ";
		cin >> gio;
	}
	void in()
	{
		danhhieu::in();
			cout << "\t " << gio;
	}
	int xeploai()
	{
		if (gio >= 700)
			return 1;
		return 0;
	}
};
int main()
{
	danhhieu *s[100];
	int n, i,tl;
	cout << "\n Nhap so doi tuong: ";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cout << "\n Nhap 1-GiangDay or 2-HanhChinh: ";
		cin >> tl;
		if (tl == 1)
		{
			giangday *p = new giangday;
			p->nhap();
			s[i] = p;
		}
		else
		{
			hanhchinh *p = new hanhchinh;
			p->nhap();
			s[i] = p;
		}
	}
	cout<<"\n Danh sach cac can bo duoc Lao Dong Tien Tien A: ";
	cout << "\n\t Ten\t NgaySinh Khoa";
	for (i = 0; i < n;i++)
	if (s[i]->xeploai() == 1)
	{
		s[i]->in();
	}
	getch();
}


