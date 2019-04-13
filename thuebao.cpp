#include <stdio.h>
#include <conio.h>
#include <string.h>
struct Thuebao
{
	char matp[6];
	char tentp[30];
	long stb;
}a[100];int n;
int trungma(Thuebao a[], int k, char matp[])
 {
	for(int i=0; i<k; i++)
		if(strcmp(a[i].matp,matp)==0)
		{
			printf("\nMa thanh pho da co, bam phim bat ky de chay lai.\n");
			getch();
			return 1;
		}	
	return 0;//khong trung ma
}
void nhap(Thuebao a[],int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		do
		{
			printf("\nNhap vao ma thanh pho: ");
			fflush(stdin);
			gets(a[i].matp);
			
		}
		while(trungma(a, i, a[i].matp));
		printf("\nTen thanh pho: ");
		gets(a[i].tentp);
		printf("\nSo thue bao: ");
		scanf("%d",&a[i].stb);
	}
}
Thuebao *Tim(char ma[6])
{
	for(int i=0;i<n;i++)
		if(strcmp(a[i].matp,ma)==0)
			return &a[i];
	return NULL;
}
void Tang(char ma[6], int soluong)
{
	Thuebao *tk;
	tk=Tim(ma);
	if(tk!=NULL)
		tk->stb=tk->stb+soluong;
	else
	{
		strcpy(a[n].matp,ma);
		printf("\nNhap ten thanh pho:");
		fflush(stdin);
		gets(a[n].tentp);
		a[n].stb=soluong;
		n++;
	}
}

void Hienthi(Thuebao a[], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("\nMa thanh pho:%s", a[i].matp);
		printf("\nTen thanh pho:%s", a[i].tentp);
		printf("\nSo thue bao:%ld", a[i].stb);
	}	
}
int main()
{
	Thuebao a[100];
	int n,soluong;
	char ma[6];
	printf("\nNhap so luong thanh pho:");
	scanf("%d", &n);
	nhap(a,n);
	printf("\Nhap them ma thanh pho:");
	fflush(stdin);
	gets(ma);
	printf("\nNhap so luong thue bao:");
	scanf("%d", &soluong);
	Tang(ma, soluong);
	Hienthi(a,n);
	getch();
	return 1;
	
}
