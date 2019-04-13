#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
	struct hocphan
	{
		char ma[50],ten[50],loai[10];
		int stc;
	};
int trungma(hocphan hp[],int n,char ms[])
{
	int i;
	for(i=0;i<n;i++)
	{
		if(strcmp(hp[i].ma,ms)==0)
		{
			printf("\n Trung ma, xin nhap lai !");
			return 1;
		}
	}
	return 0;
}
void nhap(hocphan hp[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		do
		{
			printf("\n Ma hoc phan: ");
			fflush(stdin);
			gets(hp[i].ma);
		}while(trungma(hp,i,hp[i].ma));
			printf("\n Ten hoc phan: ");
			gets(hp[i].ten);
			printf("\n Loai hoc phan: ");
			gets(hp[i].loai);
			printf("\n STC: ");
			scanf("%d",&hp[i].stc);
	}
}
void in(hocphan hp[],int n,int gia)
{
	int i,t;
	printf("\n Nhung hoc phan co gia > %d",gia);
	printf("\n\t Ma\t Ten\t Loai\t STC\t Gia ");
	for(i=0;i<n;i++)
	{
		t=120*hp[i].stc*((strcmp(hp[i].loai,"TN")==0)?1.5:1);
		if(t>gia)
		{
			printf("\n\t %s\t %s\t %s\t %d\t %d",hp[i].ma,hp[i].ten,hp[i].loai,hp[i].stc,t);
		}
	}
}
void in1(hocphan hp[],int n)
{
	int i,t;
	printf("\n Nhung hoc phan TIN co STC > 3 la: ");
	printf("\n\t Ma\t Ten\t Loai\t STC");
	for(i=0;i<n;i++)
	{
		if(strncmp(hp[i].ma,"TIN",3)==0&&hp[i].stc>3)
		{
			printf("\n\t %s\t %s\t %s\t %d",hp[i].ma,hp[i].ten,hp[i].loai,hp[i].stc);
		}
	}
}
void luu(hocphan hp[],int n)
{
	FILE *f;
	int i;
	for(i=0;i<n;i++)
	{
		if(strcmp(hp[i].loai,"TN")==0)
		{
			 f=fopen("TUNHIEN.DAT","wb");
			fwrite(&hp,sizeof(hp[i]),1,f);
		}
		if(strcmp(hp[i].loai,"XH")==0)
		{
			f=fopen("XAHOI.DAT","wb");
			fwrite(&hp,sizeof(hp[i]),1,f);
		}
	}
	fclose(f);
}
int main()
{
	hocphan s[200];
	int g,n;
	printf("\n Nhap so hoc phan: ");
	scanf("%d",&n);
	nhap(s,n);
	printf("\n Nhap gia: ");
	scanf("%d",&g);
	in(s,n,g);
	in1(s,n);
	luu(s,n);
	getch();
	
}
