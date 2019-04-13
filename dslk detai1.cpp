#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
	struct detai
	{
		char ma[30],gv[30],ten[30];
		int diem;
		detai *next;
	};
detai *nhap(detai *f)
{
	char ms[30];
	detai *p;
	do
	{
		printf("\n Ma: ");
		fflush(stdin);
		gets(ms);
		if(strcmp(ms,"")==0)
			break;
		else
		{
			p=new(detai);
			strcpy(p->ma,ms);
			printf("\n Giao vien: ");
			gets(p->gv);
			printf("\n Ten de tai: ");
			gets(p->ten);
			printf("\n Diem: ");
			scanf("%d",&p->diem);
			p->next=NULL;
			if(f==NULL)
				f=p;
			else
			{
				detai *q=f;
				while(q->next!=NULL)
				q=q->next;
				q->next=p;
			}
		}	
	}while(1);
	return f;
}
void in(detai *f)
{
	detai *p;
	printf("\n\t Ma\t GV\t TenDT\t Diem ");
	for(p=f;p!=NULL;p=p->next)
	{
		printf("\n\t %s\t %s\t %s\t %d",p->ma,p->gv,p->ten,p->diem);
	}
}
void inthongtin(detai *f)
{
	int ok=0;
	detai *p;
	for(p=f;p!=NULL;p=p->next)
	{
		if(strncmp(p->ma,"2014",10)==0)
		{
			printf("\n Cac de tai tim duoc la: ");
			printf("\n\t %s\t %s\t %s\t %d",p->ma,p->gv,p->ten,p->diem);
			ok=1;
			break;
		}
	}
	if(ok==0)
		printf("\n Khong tim duoc de tai nao ");
}
detai *tim(detai *f,char ms[])
{
	detai *p;
	for(p=f;p!=NULL;p=p->next)
	{
		if(strcmp(p->ma,ms)==0)
			return p;
	}
	return NULL;
}
detai *xoa(detai **f)
{
	detai *p,*r;
	p=*f;
	while(p!=NULL)
	{
		if(p->diem<5)
		{
			if(p==*f)
			{
				*f=(*f)->next;
				free(p);
				p=*f;
			}
			else
			{
				r=*f;
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
detai *bosung(detai *f,char m[],char g[],char t[],int d)
{
	int ok=0;
	detai *q,*p;
	for(p=f;p!=NULL;p=p->next)
	{
		if(strcmp(p->ma,m)==0)
			break;
	}
	if(p==NULL)
	{
		p=new(detai);
		strcpy(p->ma,m);
		strcpy(p->gv,g);
		strcpy(p->ten,t);
		p->diem=d;
		p->next=NULL;
	}
	if(f==NULL)
		f=p;
	else
	{
		q=f;
		while(q->next!=NULL)
			q=q->next;
			q->next=p;
	}
	return f;
}
void luu_file(detai *f)
{
	detai *p=f;
	FILE *ff;
	ff=fopen("LUU.DAT","wb");
	if(ff!=NULL)
	{
		while(p!=NULL)
		{
			if(strncmp(p->ma,"B2015",5)==0)
				fwrite(p,sizeof(detai),1,ff);
				p=p->next;
		}
	}
	fclose(ff);
}
int main()
{
	char m[30],g[30],t[30],ms[30];
	int d;
	detai *f;
	f=NULL;
	f=nhap(f);
	in(f);
	inthongtin(f);
	printf("\n Tim ma so: ");
	gets(ms);
	f=tim(f,ms);
	f=xoa(&f);
	printf("\n Danh sach sau khi xoa ");
	in(f);
	printf("\n Bo sung 1 de tai ");
	printf("\n Ma: ");
	gets(m);
	printf("\n Giao vien: ");
	gets(g);
	printf("\n Ten de tai: ");
	gets(t);
	printf("\n Diem: ");
	scanf("%d",&d);
	f=bosung(f,m,g,t,d);
	in(f);
	luu_file(f);
	getch();
}
