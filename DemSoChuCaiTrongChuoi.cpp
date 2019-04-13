#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void demkt(char s[])
{
	int dem[27],i;
	strupr(s);
	for(i=0;i<27;i++)
	dem[i]=0;
	for(i=0;i<strlen(s);i++)
	if((s[i]>='A')&&(s[i]<='Z'))
		dem[s[i]-'A']++;
	else
		dem[26]++;
	for(i=0;i<26;i++)
	if(dem[i]!=0)
	printf("\n So ki tu chu cai %c la: %d",i+'A',dem[i]);
	printf("\n So ki tu khac la: %d",dem[26]);
}
int main()
{
	int i;
	char s[50];
	printf("\n Nhap chuoi: ");
	gets(s);
	demkt(s);

	getch();
}
