#include<stdio.h>
#include<conio.h>
#include<string.h>
int dem(char *s,char c)
{
	char t;
	int i,d=0,l=0,m=0;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]==c)// s[i] thuong = c thuong || s[i] hoa = c hoa
			l++;
		if(s[i]==c-32)// s[i] thuong = c hoa 
			d++;
		if(s[i]==c+32)// c nhap vao la hoa -> c+32(thuong) = s[i] thuong
			m++;
	}
	return d+l+m;
}
int main()
{
	char s[50],c;
	printf("\n Nhap chuoi: ");
	gets(s);
	printf("\n Ki tu: ");
	scanf("\n %c",&c);
	printf("\n Chuoi co %d ki tu '%c' ",dem(s,c),c);
}
