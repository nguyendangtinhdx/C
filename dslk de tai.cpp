#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
	struct detai
	{
		char madt[30];
		char htgv[30];
		char tendt[30];
		detai *next;
	};
detai *nhap(detai *f)
{
	char ms[30];
	detai *p;
	do
	{
		printf("\n Ma de tai: ");
		fflush(stdin);
		gets(ms);
		if(strcmp(ms,"")==0)
		break;
		else
		{
			p=(detai*)malloc(sizeof(detai));
			strcpy(p->madt,ms);
			printf("\n Ho ten giao vien: ");
			fflush(stdin);
			gets(p->htgv);
			printf("\n Ten de tai: ");
			fflush(stdin);
			gets(p->tendt);
		}
	//	else
	//	break;
		p->next=f;
		f=p;
	}while(1);//strcmp(ms,"")!=0
	return f;
}
void in(detai *f)
{
	detai *p;
	p=f;
	printf("\n\t MaDT\t HTGV\t TenDT ");
	while(p!=NULL)
	{
		printf("\n\t %s\t %s\t %s",p->madt,p->htgv,p->tendt);
		p=p->next;	
	}
}

void inthongtin(detai *f)
{
	int ok=0;
	detai *p;
	p=f;
		printf("\n Da tim duoc ma de tai: ");
	while(p!=NULL)
	{
		if(strncmp(p->madt,"B2014_DHKH",10)==0)
		{
			printf("\n\t %s\t %s\t %s",p->madt,p->htgv,p->tendt);
			ok=1;
		}
		p=p->next;
	}
	if(ok==0)
		printf("\n Khong co ma nao ");
}
/*
detai *tim(detai *f,char ms[10])
{
	detai *p;
	for(p=f;p!=NULL;p=p->next)
	{
		if(strcmp(p->madt,ms)==0)
		{
			printf("\n\t %s\t %s\t %s",p->madt,p->htgv,p->tendt);
			return p;
		}
	}
	return NULL;
}*/
detai *bosung(detai *f,char ms[],char ht[],char dt[])
{
	detai *p,*q;
	p=f;
	while(p!=NULL)
	{
		if(strcmp(p->madt,ms)==0)
			break;
		p=p->next;
	}
	if(p==NULL)
	{
		q=(detai*)malloc(sizeof(detai));
		strcpy(q->madt,ms);
		strcpy(q->htgv,ht);
		strcpy(q->tendt,dt);
	}
	q->next=f;
	f=q;
	return f;
}

detai *luu(detai *f)
{
	detai *first=NULL,*p;
	FILE *ff=fopen("LUU2015.DAT","wb");
	while(!feof(ff))
	{
		p=(detai*)malloc(sizeof(detai));
		fwrite(p,sizeof(ff),1,ff);
		p->next=NULL;
		if(first==NULL)
			first=p;
		else
		{
			p->next=first;
			first=p;
		}
	}
	fclose(ff);
	return f;
}

void mo(detai **f)
{
	FILE *ff=fopen("LUU2015.DAT","rb");
	while(!feof(ff))
	{
		fread(*f,sizeof(ff),1,ff);
	}
	fclose(ff);
}

int main()
{
	char ms[30],ht[30],dt[30];
	detai *f,*q;
	f=NULL;
	f=nhap(f);
	in(f);
	printf("\n");
	inthongtin(f);
	printf("\n Nhap ma so: ");
	gets(ms);
	printf("\n Ma : ");
	gets(ms);
	printf("\n HTGV: ");
	gets(ht);
	printf("\n Ten dt: ");
	gets(dt);
	f=bosung(f,ms,ht,dt);
	in(f);
	f=luu(f);
	mo(&f);
	getch();
}
