#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
	struct sach
	{
		char ma[50],ten[50];
		int gia;
		sach *next;
	};
int trungma(sach *f,char ms[])
{
	sach *p;
	for(p=f;p!=NULL;p=p->next)
	{
		if(strcmp(p->ma,ms)==0)
		{
			printf("\n Ma trung, xin nhap lai ");
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
		
			p=(sach*)malloc(sizeof(sach));
			strcpy(p->ma,m);
			printf("\n Ten sach: ");
			gets(p->ten);
			printf("\n Gia: ");
			scanf("%d",&p->gia);
			p->next=NULL;
			if(f==NULL)
				f=p;
			else
			{
				sach *r=f;
				while(r->next!=NULL)
				r=r->next;
				r->next=p;
			}
	}while(1);
	return f;
}
void in(sach *f)
{
	sach *p;
	printf("\n\t Ma\t Ten\t Gia ");
	for(p=f;p!=NULL;p=p->next)
	{
		printf("\n\t %s\t %s\t %d",p->ma,p->ten,p->gia);
	}
}
void sapxep(sach *f)
{
	char m[50],t[50];
	int g;
	sach *p,*r;
	for(p=f;p!=NULL;p=p->next)
		for(r=p->next;r!=NULL;r=r->next)
			if(strcmp(p->ma,r->ma)>0)
		//	if(p->gia>r->gia)
			{
				strcpy(m,p->ma);
				strcpy(p->ma,r->ma);
				strcpy(r->ma,m);
				strcpy(t,p->ten);
				strcpy(p->ten,r->ten);
				strcpy(r->ten,t);
				g=p->gia;
				p->gia=r->gia;
				r->gia=g;
			}
}

sach *xoa(sach **f)
{
	sach *p;
	p=*f;
	while(p!=NULL)
	{
		if(p->gia<5)
		{
			if(p==*f)
			{
				*f=(*f)->next;
				free(p);
				p=*f;
			}
			else
			{
				sach *r=*f;
				while(r->next!=p)
					r=r->next;
					r->next=p->next;
					free(p);
					p=r->next;
			}
		}
		else
			p=p->next;
	}
	return *f;
}
sach *bosung(sach *f,char m[50],char t[50],int g)
{
	int ok=0;
	sach *p,*r;
	for(p=f;p!=NULL;p=p->next)
	{
		if(strcmp(p->ma,m)==0)
		{
			break;
		}
	}
	if(p==NULL)
	{
		p=new(sach);
		strcpy(p->ma,m);
		strcpy(p->ten,t);
		p->gia=g;
		p->next=NULL;
	}
	if(f==NULL)
		f=p;
	else
	{
		r=f;
		while(r->next!=NULL)
		r=r->next;
		r->next=p;
	}
	return f;
}
void luu(sach *f)
{
	sach *p=f;
	FILE *ff=fopen("TINH.DAT","wb");
	if(ff!=NULL)
	{
		while(p!=NULL)
		{
			if(strcmp(p->ma,"TINH")==0)
				fwrite(&p,sizeof(sach),1,ff);
				p=p->next;
		}
	}
	fclose(ff);
}
int main()
{
	char m[50],t[50];
	int g;
	sach *f;
	f=NULL;
	f=nhap(f);
	in(f);
	printf("\n Danh sach sap xep Ma Sach theo thu tu ABC ");
	sapxep(f);
	in(f);
	f=xoa(&f);
	printf("\n Danh sach sau khi xoa: ");
	in(f);
	printf("\n Bo sung 1 dau sach: ");
	printf("\n Ma sach: ");
	gets(m);
	printf("\n Ten sach: ");
	gets(t);
	printf("\n Gia: ");
	scanf("%d",&g);
	f=bosung(f,m,t,g);
	in(f);
	luu(f);
	getch();
}
