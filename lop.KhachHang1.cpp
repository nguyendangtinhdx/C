#include<conio.h>
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
	class khachhang
	{
		private:
			char *tenchuho, *diachi;
			int cscu, csmoi,tien;
		public:
			khachhang *next;
			khachhang(){}
			khachhang(char *ten, char *dc,int moi, int cu, khachhang *n)
			{
			//	tenchuho=new char[strlen(ten)+1];
			//	diachi=new char[strlen(dc)+1];
				strcpy(tenchuho,ten);
				strcpy(diachi,dc);
				csmoi=moi;
				cscu=cu;
				next=n;
			}
			void xuat()
			{
				cout<<"\n\t "<<tenchuho<<"\t "<<diachi<<"\t "
				<<csmoi<<"\t "<<cscu<<"\t "<<tien<<"dong";
				
			}
			char *gettenchuho()
			{
				return tenchuho;
			}
			char *getdiachi()
			{
				return diachi;
			}
			int getcsmoi()
			{
				return csmoi;
			}
			int getcscu()
			{
				return cscu;
			}
			int getchiso()
			{
				return csmoi-cscu;
			}
			long tratien()
			{
				if(getchiso()<=50)
					return getchiso()*1200;
				else if(getchiso()>50&&getchiso()<=100)
					return 50*1200 + (getchiso()-50)*1500;
				else	// >100
					return 50*1200 + 50* 1500 + (getchiso()-100)*1800;
			}
	};

	class list
	{
		private:
			khachhang *first;
		public:
			list()
			{
				first=NULL;
			}
			void bosung(khachhang *r);
		//	void nhap();
			void in();
			void tratienmax();
	};
/*void list::nhap()
{
	char ten[50], dc[50];
	int moi, cu;
	do
	{
		cout<<"\n Ten chu ho: ";
		fflush(stdin);
		gets(ten);
		if(strcmp(ten,"")!=0)
		{
			cout<<"\n Dia chi: ";
			gets(dc);
			cout<<"\n Chi so moi: ";
			cin>>moi;
			cout<<"\n Chi so cu: ";
			cin>>cu;
			khachhang *p=new khachhang(ten,dc,moi,cu);
					p->next=first;
					first=p;
		}
	}while(strcmp(ten,"")!=0);
}*/
void list::bosung(khachhang *q)
{	
	q->next=first;
	first=q;
}
void list::in()
{
	
	khachhang *p=first;
	cout<<"\n\t TenCH\t DiaChi\t csCU\t csMOI\t TIEN";
	while(p!=NULL)
	{
		p->xuat();
		p=p->next;
	}
}

void list::tratienmax()
{
	khachhang *p=first;
	cout<<"\n Danh sach khach hang co tien phai tra cao nhat: ";
	cout<<"\n\t TenCH\t DiaChi\t csCU\t csMOI\t TIEN";
	int max;
	max=first->tratien();
	while(p!=NULL)
	{
		if(p->tratien()>max)
			max=p->tratien();
				if(max==p->tratien())	
		cout<<"\n\t "<<p->gettenchuho()<<"\t "<<p->getdiachi()<<"\t "
		<<p->getcsmoi()<<"\t "<<p->getcscu()<<"\t "<<p->tratien()<<"dong";
		p=p->next;
	}
}
int main()
{
	list s;
//	s.nhap()
//	s.in();
	char ten[50], dc[50];
	int cu,moi;
	while(true)
	{
//	cout<<"\n Bo sung 1 khach hang: ";
		cout<<"\n Ten chu ho: ";
		fflush(stdin);
		gets(ten);
		if(strcmp(ten,"")!=0)
		
			cout<<"\n Dia chi: ";
			gets(dc);
			cout<<"\n Chi so moi: ";
			cin>>moi;
			cout<<"\n Chi so cu: ";
			cin>>cu;
		
			khachhang *p=new khachhang(ten,dc,moi,cu,NULL);
		s.bosung(p);
	}
	s.in();
//	s.tratienmax();
	getch();
}
