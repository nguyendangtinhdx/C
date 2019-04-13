#include<stdio.h>
#include<conio.h>
#include<string.h>
char *reverse(char *s)
{
	int i,j,x;
	for(i=0,j=strlen(s)-1;i<j;i++,j--)
	{
		x=s[i];
		s[i]=s[j];
		s[j]=x;
	}
	return s;
}
int main()
{
	char s[50];
	printf("\n Nhap chuoi: ");
	gets(s);
	printf("\n Chuoi reverse la: %s",reverse(s));
	getch();
}

