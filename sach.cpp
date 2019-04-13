#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
	struct sach
	{
		char tensach[100];
		char masach[6];
		int soluong;
		int gia;
	};
	
int trungma(sach a[],int n,char ms[])
{
	for(int i=0;i<n;i++)
	if(strcmp(a[i].masach,ms)==0)
	{
		printf("\n Ma sach trung, vui long nhap lai !\n");
		return 1;
	}
	return 0;
}
void nhap(sach s[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{	
		fflush(stdin);
		do
		{
			printf("\n Ma sach: ");
			gets(s[i].masach);
		}	while(trungma(s,i,s[i].masach));
			
		printf("\n Ten sach: ");
		gets(s[i].tensach);
		printf("\n So luong: ");
		scanf("%d",&s[i].soluong);
		printf("\n Gia: ");
		scanf("%d",&s[i].gia);
	}
}
void in(sach s[],int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("\n %s\t\t %s\t\t %d\t\t %d d ",s[i].masach,s[i].tensach,s[i].soluong,s[i].gia);
}
int xoa(sach s[],int *n)
{
	int i=0,dem=0,j;
	do
	{
		if(s[i].soluong<5)
		{
			for(j=i;j<*n;j++)
				s[j]=s[j+1];
				dem++;
				(*n)--;
		}
		else i++;
	}while(i<*n);
	return dem;
}

void them(sach s[],int *n)
{
	int j,i,ok = 0;
	sach p;
	fflush(stdin);	
	printf("\n Bo sung 1 dau sach: ");
	printf("\n Ma sach: ");
	gets(p.masach);	
	printf("\n Ten sach: ");
	gets(p.tensach);
	printf("\n So luong: ");
	scanf("%d",&p.soluong);
	printf("\n Gia: ");
	scanf("%d",&p.gia);	
	for(i=0;i<*n;i++)
	{
		if(strcmp(s[i].masach,p.masach)==0)
		{
			s[i].soluong+=p.soluong;
			ok = 1;
			break;
		}
	}
	if (ok==0)
	{
		strcpy(s[*n].masach,p.masach);
		strcpy(s[*n].tensach,p.tensach);
		s[*n].soluong = p.soluong;
		s[*n].gia = p.gia;
		(*n)++;		
	}
}
int main()
{
	sach s[100];
	int n;
	printf("\n Nhap so luong sach: ");
	scanf("%d",&n);
	nhap(s,n);	
	printf(" Ma sach:\t Ten sach:\t So luong:\t Gia: ");
	in(s,n);	
	them(s,&n);	
	printf(" Ma sach:\t Ten sach:\t So luong:\t Gia: ");
	in(s,n);
	getch();
}

