#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
int kt(char *s)
{
	for(int i=0;i<strlen(s);i++)
	{
		if(strncmp(s,"tran",4)==0)
		return 1;
		return 0;
	}
}	
int main()
{
	int n,dem=0;
	char s[100];
	printf("\n Nhap so luong sinh vien: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("\n Nhap ten: ");
		fflush(stdin);
		gets(s);
		if(strncmp(s,"tran",4)==0)
		dem++;
	}
	printf("\n Co %d nguoi co ho TRAN ",dem);
}

