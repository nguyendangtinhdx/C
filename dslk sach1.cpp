#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
	struct sach
	{
		char ma[100];
		int sl,gia;
		sach *next;
	};
int trungma(sach *f,char ms[])
{
	sach *p;
	for(p=f;p!=NULL;p=p->next)
	{
		if(strcmp(p->ma,ms)==0)
		{
			printf("\n Ma trung, xin nhap lai !");
			return 1;
		}
	}
	return 0;
}
sach *nhap(sach *f)
{
	char m[50];
	sach *p;
	do
	{
		do
		{
			printf("\n Ma sach: ");
			fflush(stdin);
			gets(m);
		}while(trungma(f,m));
		if(strcmp(m,"")==0)
			break;
		else
		{
			p=new(sach);
			strcpy(p->ma,m);
			printf("\n So luong: ");
			scanf("%d",&p->sl);
			printf("\n Gia: ");
			scanf("%d",&p->gia);
		}
		p->next=f;
		f=p;
	}while(1);
	return f;
}
void in(sach *f)
{
	sach *p;
	printf("\n\t Ma\t SL\t Gia ");
	for(p=f;p!=NULL;p=p->next)
	printf("\n\t %s\t %d\t %d",p->ma,p->sl,p->gia);
}
void sapxep(sach *f)
{
	sach *p,*q;
	char m[50];
	int s,g;
	for(p=f;p!=NULL;p=p->next)
		for(q=p->next;q!=NULL;q=q->next)
			if(strcmp(p->ma,q->ma)>0)
			{
				strcpy(m,p->ma);
				strcpy(p->ma,q->ma);
				strcpy(q->ma,m);
				s=p->sl;
				p->sl=q->sl;
				q->sl=s;
				g=p->gia;
				p->gia=q->gia;
				q->gia=g;
			}
}
sach *xoa(sach **f)
{
	sach *p,*q;
	p=*f;
	while(p!=NULL)
	{
		if(p->sl<5)
		{
			if(p==*f)
			{
				*f=(*f)->next;
				free(p);
				p=*f;
			}
			else
			{
				q=*f;
				while(q->next!=p)
					q=q->next;
					q->next=p->next;
					free(p);
					p=q->next;
					
			}
		}
		else
			p=p->next;
	}
	return *f;
}
sach *bosung(sach *f,char m[],int s,int g)
{
	sach *p,*q;
	for(p=f;p!=NULL;p=p->next)
	{
		if(strcmp(p->ma,m)==0)
			break;
	}
	if(p==NULL)
	{
		q=new(sach);
		strcpy(q->ma,m);
		q->sl=s;
		q->gia=g;
	}
	q->next=f;
	f=q;
	return f;
}
void luu(sach *f)
{
	sach *p=f;
	FILE *ff=fopen("SACH.DAT","wt");
	if(ff!=NULL)
	{
		while(p!=NULL)
		{
			if(strcmp(p->ma,"T")==0)
			fwrite(&p,sizeof(sach),1,ff);
			p=p->next;
		}
	}
	fclose(ff);
}
int main()
{
	char m[50];
	int g,s;
	sach *f;
	f=NULL;
	f=nhap(f);
	sapxep(f);
	in(f);
/*	f=xoa(&f);
	printf("\n Danh sach sau khi xoa sach co SL < 5");
	in(f);
*/
	printf("\n Bo sung 1 dau sach : ");
	printf("\n Ma sach: ");
	gets(m);
//	p=new(sach);
	printf("\n So luong: ");
	scanf("%d",&s);
	printf("\n Gia: ");
	scanf("%d",&g);
	f=bosung(f,m,s,g);
	in(f);
	luu(f);
	getch();
}
