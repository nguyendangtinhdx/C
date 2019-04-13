#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int strlen(char *s)
{
	int i;
	for(i=0;s[i];i++);
	return i;	
}
char *chuanhoa(char *s)
{
	int i,j,m,t;
	char *c=strstr(s,"  ");
	while(c!=NULL)
	{
		t=strlen(s)-strlen(c);
		for(j=t;j<strlen(s);j++)
			s[j]=s[j+1];
			c=strstr(s,"  ");
	}
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]==' '&&(s[i+1]>=97)&&(s[i+1]<=122))
			s[i+1]-=32;
	}
	return s;
}
char *max(char *s)
{
	char p[100],q[100];
	int i=0,j,k,max=0;
	while(s[i])
	{
		j=0;
		if(s[i]!=' ')
		{
			while(s[i]!=NULL)
			{
				if(s[i]==' ')
				break;
				p[j++]=s[i++];
			}
			p[j]=NULL;
			if(strlen(p)>max)
			{
				max=strlen(p);
				strcpy(q,p);
			}
		}
		else
		i++;
	}
	return q;
}
char *ch(char *s)
{
	int i,j;
	while(s[0]==' ')
	{
		for(i=0;i<strlen(s);i++)
		s[i]=s[i+1];
	}
	while(s[strlen(s)-1]==' ')
	s[strlen(s)-1]='\0';
	for(i=0;i<strlen(s);i++)
		if(s[i]==' '&&s[i+1]==' ')
			{
				strcpy(&s[i],&s[i+1]);
				i--;
			}
	
	return s;
}
int main()
{
	int i,n,m;
	char *s,*p;
	s=(char*)malloc(50*sizeof(char));
	printf("\n Nhap chuoi: ");
	gets(s);
//	printf("\n Chuoi co do dai = %d",strlen(s));
//	printf("\n Chuoi tro thanh : %s",chuanhoa(s));
//	printf("\n Tu dai nhat la : %s",max(s));
	printf("\n ch = %s.",ch(s));
	getch();
}
