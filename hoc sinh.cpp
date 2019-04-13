#include<stdio.h>
#include<conio.h>
#include<string.h>
	struct hocsinh
	{
		char ma[100],lop[100];
		int diem;
	};
int trungma(hocsinh hs[],int n,char ms[])
{
	int i;
	for(i=0;i<n;i++)
	{
		if(strcmp(hs[i].ma,ms)==0)
		{
			printf("\n Ma trung, xin nhap lai !");
			return 1;
		}
	}
	return 0;
}
void nhap(hocsinh hs[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		do
		{
			printf("\n Ma: ");
			fflush(stdin);
			gets(hs[i].ma);
		}while(trungma(hs,i,hs[i].ma));
		printf("\n Lop: ");
		gets(hs[i].lop);
		printf("\n Diem: ");
		scanf("%d",&hs[i].diem);
	}
}
void in(hocsinh hs[],int n)
{
	printf("\n\t Ma\t Lop\t Diem");
	for(int i=0;i<n;i++)
	printf("\n\t %s\t %s\t %d",hs[i].ma,hs[i].lop,hs[i].diem);
}
void dao(hocsinh *s,hocsinh *t)
{
	hocsinh x;
	x=*s;
	*s=*t;
	*t=x;
}
void sapxep(hocsinh hs[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(strcmp(hs[i].ma,hs[j].ma)>0)
			dao(&hs[i],&hs[j]);
}
void xoa(hocsinh hs[],int *n)
{
	int i=0,j;
	do
	{
		if(hs[i].diem<5)
		{
			for(j=i;j<*n;j++)
				hs[j]=hs[j+1];
				(*n)--;
		}
		else
			i++;
	}
	while(i<*n);
}
void bosung(hocsinh hs[],int *n,char m[],char l[],int d)
{
	int i,ok=0;
	hocsinh p;
	for(i=0;i<*n;i++)
	if(strcmp(hs[i].ma,m)==0)
	{
		hs[i].diem+=d;
		ok=1;
		break;
	}
	if(ok==0)
	{
		strcpy(hs[*n].ma,m);
		strcpy(hs[*n].lop,l);
		hs[*n].diem=d;
		(*n)++;
	}
}
void luu(hocsinh hs[],int n)
{
	FILE *f=fopen("HOCSINH.DAT","wt");
	if(f==NULL)
	{
		printf("\n Khong mo duoc FILE");
		return;
	}
	for(int i=0;i<n;i++)
		if(strcmp(hs[i].ma,"a")==0)
			fwrite(&hs[i],sizeof(hocsinh),1,f);
	fclose(f);
}
int main()
{
	hocsinh s[100];
	char m[50],l[50];
	int n,d;
	printf("\n Nhap so hoc sinh: ");
	scanf("%d",&n);
	nhap(s,n);
	in(s,n);
/*	printf("\n Danh sach sap xep theo DIEM giam dan");
	sapxep(s,n);
	in(s,n);
*/
/*	xoa(s,&n);
	printf("\n Danh sach sau khi xoa: ");
	in(s,n);
*/
/*	printf("\n Bo sung 1 hoc sinh: ");
	fflush(stdin);
	printf("\n Ma: ");
	gets(m);
	printf("\n Lop: ");
	gets(l);
	printf("\n Diem: ");
	scanf("%d",&d);
	bosung(s,&n,m,l,d);
	in(s,n);
*/
	luu(s,n);
	getch();	
}
