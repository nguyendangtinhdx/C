#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
	struct thietbi
	{
		char ma[50],ten[50],ngay[50];
		int gia;
		thietbi *next;
	};
thietbi* nhap(thietbi *f)
{
	thietbi *p;
	char ms[50];
	do
	{
		printf("\n Ma thiet bi: ");
		fflush(stdin);
		gets(ms);
		if(strcmp(ms,"MTB00")==0)
			break;
		else
		{
			p=(thietbi*)malloc(sizeof(thietbi));
			strcpy(p->ma,ms);
			printf("\n Ten thiet bi: ");
			gets(p->ten);
			printf("\n Ngay mua: ");
			gets(p->ngay);
			printf("\n Gia: ");
			scanf("%d",&p->gia);
		}
		p->next=f;
		f=p;
	}while(1);
	return f;
}
char *trich(thietbi *f)
{
	thietbi *p;
	char s[50],r[50];
	int i,j=0,dem=0,y;
	for(p=f;p!=NULL;p=p->next)
	{
		for(i=0;i<strlen(p->ma);i++)
		{
			if(strcmp(p->ma,"/")==0)
				break;
				dem++;
		}
		strcpy(r,p->ma);
		for(y=0;y<dem;y++)
			s[j++]=r[y];
			s[j]=NULL;
	}
	return s;
}
void in(thietbi *f,char day[])
{
	int s=0,i,j=0,y,dem=0;
	char t[50],r[50];
	thietbi *p;
	printf("\n Nhung thiet bi mau sau ngay %s",day);
	printf("\n\t Ma\t Ten\t Ngay\t Gia");
	for(p=f;p!=NULL;p=p->next)
	{
		for(i=0;i<strlen(day);i++)
		{
			if(strcmp(day,"/")==0)
				break;
				dem++;
		}
		strcpy(r,day);
		for(y=0;y<dem;y++)
			t[j++]=r[y];
			t[j]=NULL;
	//	if(strcmp(day,p->ngay)>0)
		if(strcmp(trich(f),t)<0)
		{
			s+=p->gia;
			printf("\n\t %s\t %s\t %s\t %d",p->ma,p->ten,p->ngay,p->gia);
		}
	}
	printf("\n Tong tien la: %d",s);
}
void in1(thietbi *f)
{
	thietbi *p;
	printf("\n\t Ma\t Ten\t Ngay\t Gia");
	for(p=f;p!=NULL;p=p->next)
	{
		printf("\n\t %s\t %s\t %s\t %d",p->ma,p->ten,p->ngay,p->gia);
	}
}
thietbi *xoa(thietbi **f,char ms[])
{
	int ok=0;
	thietbi *p;
	p=*f;
	while(p!=NULL)
	{
		if(strcmp(ms,p->ma)==0)
		{
			if(p==*f)
			{
				*f=(*f)->next;
				free(p);
				p=*f;
			}
			else
			{
				thietbi *r=*f;
				while(r->next!=p)
					r=r->next;
					r->next=p->next;
					p=r->next;	
			}
			ok=1;
		}
		else
			p=p->next;
	}
	if(ok==0)
	{
		printf("\n Khong tim thay thiet bi de xoa ");
	}
	return *f;
}
int main()
{
	thietbi *f;
	f=NULL;
	f=nhap(f);
	char ng[50],ms[50];
	printf("\n Nhap ngay mua: ");
	gets(ng);
	in(f,ng);
/*	in1(f);
	printf("\n Nhap ma thiet bi an xoa: ");
	gets(ms);
	f=xoa(&f,ms);
	in1(f);
*/	getch();
}
