#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
	struct hanghoa
	{
		char ma[30],ten[30];
		int gia,soluong;
	};
int trungma(hanghoa a[],int n,char ms[])
{
	for(int i=0;i<n;i++)
		if(strcmp(a[i].ma,ms)==0)
//		{
			printf("\n Ma trung, xin nhap lai ! ");
			return 1;
//		}
	return 0;
}
void nhap(hanghoa hh[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		fflush(stdin);
		do
		{
			printf("\n Ma: ");
			gets(hh[i].ma);
		}while(trungma(hh,i,hh[i].ma));
		
		printf("\n Ten: ");
		gets(hh[i].ten);
		printf("\n Gia: ");
		scanf("%d",&hh[i].gia);
		printf("\n So luong: ");
		scanf("%d",&hh[i].soluong);
	}
}
void doi(hanghoa *p,hanghoa *t)
{
	hanghoa x;
	x=*p;
	*p=*t;
	*t=x;
}
void in(hanghoa hh[],int n)
{
	int i,j;
	printf("\n\t Ma\t Ten\t Gia\t SoLuong ");
	for(i=0;i<n;i++)
	printf("\n\t %s\t %s\t %d\t %d ",hh[i].ma,hh[i].ten,hh[i].gia,hh[i].soluong);
		
}
void sapxep(hanghoa hh[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(strcmp(hh[i].ma,hh[j].ma)>0)
			{
				doi(&hh[i],&hh[j]);
			}
}
void thongke(hanghoa hh[],int n)
{
	int i,max=0;
	printf("\n Hang hoa co so luong lon nhat la: ");
	for(i=0;i<n;i++)
		if(hh[i].soluong>max)
			max=hh[i].soluong;
				for(i=0;i<n;i++)
					if(hh[i].soluong==max)
						printf("\n\t %s\t %s\t %d\t %d ",hh[i].ma,hh[i].ten,hh[i].gia,hh[i].soluong);
		
}
void bosung(hanghoa hh[],int *n)
{
	hanghoa p;
	int i,ok=0;
	printf("\n Bo sung 1 mat hang hoa: ");
	fflush(stdin);
	printf("\n Ma: ");
	gets(p.ma);
	printf("\n Ten: ");
	gets(p.ten);
	printf("\n Gia: ");
	scanf("%d",&p.gia);
	printf("\n So luong: ");
	scanf("%d",&p.soluong);
	for(i=0;i<*n;i++)
	{
		if(strcmp(hh[i].ma,p.ma)==0)
		{
			hh[i].soluong+=p.soluong;
			ok=1;
			break;
		}
	}
	if(ok==0)
	{
		strcpy(hh[*n].ma,p.ma);
		strcpy(hh[*n].ten,p.ten);
		hh[*n].gia=p.gia;
		hh[*n].soluong=p.soluong;
		(*n)++;
	}	
}
int main()
{
	hanghoa s[100];
	int n;
	printf("\n Nhap so hang hoa: ");
	scanf("%d",&n);
	nhap(s,n);
	sapxep(s,n);
	in(s,n);
	thongke(s,n);
	bosung(s,&n);
	in(s,n);
	getch();
}
