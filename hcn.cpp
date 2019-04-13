#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
	struct hcn
	{
		float x1,x2,y1,y2;
		float s;
	};
void nhap(hcn h[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\n X1 = ");
		scanf("%f",&h[i].x1);
		printf("\n Y1 = ");
		scanf("%f",&h[i].y1);
		printf("\n X2 = ");
		scanf("%f",&h[i].x2);
		printf("\n Y2 = ");
		scanf("%f",&h[i].y2);
		h[i].s=(h[i].x2-h[i].x1)*(h[i].y1-h[i].y2);
	}
}
void in(hcn h[],int n)
{
	int i;
	float s,p;
	printf("\n Nhung toa do HCN co goc toa do O nam trong HCN la: ");
	for(i=0;i<n;i++)
	{
		if(h[i].x1<0&&h[i].x2>0&&h[i].y1>0&&h[i].y2<0)
		{
			p=(h[i].x2-h[i].x1)*2+(h[i].y1-h[i].y2)*2;
			s=(h[i].x2-h[i].x1)*(h[i].y1-h[i].y2);
			printf("\n A(%g,%g); B(%g,%g); S = %g; P = %g ",h[i].x1,h[i].y1,h[i].x2,h[i].y2,s,p);
		}
	}
}
void doi(hcn *p, hcn *r)
{
	hcn x;
	x=*p;
	*p=*r;
	*r=x;
}
void sapxep(hcn h[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(h[i].s>h[j].s)
				doi(&h[i],&h[j]);
}
void luu(hcn h[],int n)
{
	int i;
	FILE *f=fopen("HCNC.DAT","wt");
	if(f==NULL)
	{
		printf("\n Khong mo duoc FILE ");
		return;
	}
	for(i=0;i<n;i++)
		if(h[i].x1<0&&h[i].x2>0)
			fwrite(&h[i],sizeof(hcn),1,f);
	fclose(f);
}
int main()
{
	hcn s[50];
	int n;
	printf("\n Nhap so HCN: ");
	scanf("%d",&n);
	nhap(s,n);
	in(s,n);
	sapxep(s,n);
	printf("\n Nhung toa do HCN duoc sap xep theo thu tu tang dan S la : ");
	in(s,n);
	luu(s,n);
	getch();
}
