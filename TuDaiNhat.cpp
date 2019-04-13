#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
char *max(char *s)
{
	char p[100],q[100];
	int i=0,j,max=0;
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
					p[j]=NULL;
			}
			if(strlen(p)>max)
			{
				max=strlen(p);
				strcpy(q,p);
			}
		}
		else i++;
	}
	return q;
}

int main()
{
	char *s,*p;
	s=(char*)malloc(50*sizeof(char));
	printf("\n Nhap chuoi: ");
	gets(s);
	p=max(s);
	printf("\n Tu dai nhat la: %s \n Co do dai = %d",p,strlen(p));
	getch();
}
