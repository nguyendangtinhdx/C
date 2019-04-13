#include<conio.h>
#include<stdio.h>
#include<string.h>
int main()
{
	char s[50];
	int n,i,dem,j,k;
	printf("\n Nhap chuoi: ");
	fflush(stdin);
	gets(s);
	n=strlen(s);
	for(i=0;i<n;i++)
		if(s[i]!=32)
		{
			dem=1;
			for(j=n-1;j>i;j--)
				if(s[i]==s[j])
			 		{
			 		dem=dem+1;
			 		for(k=j;k<n;k++)
			 			s[k]=s[k+1];
			 			n--;
			 		}
			printf("\n Chuoi co %d chu %c",dem,s[i]);
		}
}
