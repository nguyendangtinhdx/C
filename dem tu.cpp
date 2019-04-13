#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
int main()
{
	int dem=0,i;
	char s[50];
	printf("\n Nhap chuoi: ");
	gets(s);
	if(s[0]==' ')
		dem=0;
	else
		dem=1;
	for(i=0;i<strlen(s)-1;i++)
		if(s[i]==' '&&s[i+1]!=' ')
			dem++;
	printf("\n Chuoi co %d tu",dem);
	getch();
}
