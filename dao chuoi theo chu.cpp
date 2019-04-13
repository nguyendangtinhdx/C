#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
char *daothutu(char *s)
{
	int i;
	char c[255];
	for(i=strlen(s)-1;i>=0;i--)
	if(s[i]==' ')
	{
		strcat(strcat(c,s+i+1)," ");
		s[i]=NULL;
	}
	strcat(c,s);
	return c;
}
int main()
{
	char s[100];
	printf("\n Nhap chuoi: ");
	gets(s);
	printf("\n Chuoi dao la: %s",daothutu(s));
	getch();
}
