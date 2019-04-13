#include<stdio.h>
#include<conio.h>
#include<string.h>
char *replace(char *s, char *s1, char *s2)
{
	int i=0,j,luu;
	int len=strlen(s),len1=strlen(s1),len2=strlen(s2);
	if(len1!=0)
	{
		while(i<len)
		{
			if(s[i]==s1[0])
			{
				j=0;
				luu=i;
				while(s[luu++]==s1[j++]&&j<len1);
					if(j==len1)
					{
						memmove(&s[i+len2],&s[i+len1],len-len1-i+1);
						memcpy(&s[i],s2,len2);
						len=len-len1+len2;
						i+=len2;
					}
					else i++;
			}
			else i++;
		}
	}
	return s;
}
int main()
{
	char s[100],s1[100],s2[100];
	printf("\n Nhap chuoi : ");
	gets(s);
	printf("\n Nhap chuoi can tim : ");
	gets(s1);
	printf("\n Nhap chuoi thay the : ");
	gets(s2);
	printf("\n Chuoi thay the thanh: %s",replace(s,s1,s2));
	getch();
}
