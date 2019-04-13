#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void nhap(char *s[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		fflush(stdin);
		s[i]=(char*)malloc(50*sizeof(char));
		printf("\n Nhap ten: ");
		gets(s[i]);
	}
}
void in(char *s[],int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("\n %d: %s",i+1,s[i]);
}
int strcmp(char *t,char *p)
{
	int i;
	for(i=0;t[i]==p[i];i++)
	if(t[i]==NULL)
	return 0;
	return t[i]-p[i];
}
char dao(char *s[])
{
	int i;
	char c[255];
	for(i=strlen(*s)-1;i>=0;i--)
	if(s[i]==" ")
	{
		strcat(strcat(c,*s+i+1)," ");
		s[i]=NULL;
	}
	strcat(c,*s);
//	return c;
}
void sapxep(char *s[],int n)
{
	char *x;
	int i,j,k,d=0,y;
	x=(char*)malloc(50*sizeof(char));
/*	for(y=strlen(*s)-1;y>=0;y--)
	{
		if(s[y]==" ")		
		break;
		d++;
	}
	printf(" %d",d);
*/	for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
	if(dao(s[i])>dao(s[j]))
	{
		x=s[i];
		s[i]=s[j];
		s[j]=x;
	}
}
int main()
{
	char *s[100];
	int n;
	printf("\n Nhap so sinh vien: ");
	scanf("%d",&n);
	nhap(s,n);
//	dao(s,n);
	sapxep(s,n);
	in(s,n);
	getch();
}
