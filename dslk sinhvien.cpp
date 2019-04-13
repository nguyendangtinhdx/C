#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
	struct sinhvien
	{
		char ten[30];
		int tuoi;
		float diem;
		sinhvien *next;
	};
sinhvien *nhap(sinhvien *f)
{
	sinhvien *p;
	char t[30];
	do
	{
		printf("\n Ten: ");
		fflush(stdin);
		gets(t);
		if(strcmp(t," ")!=0)
		{
			p=(sinhvien*)malloc(sizeof(sinhvien));
			strcpy(p->ten,t);
			printf("\n Tuoi: ");
			scanf("%d",&p->tuoi);
			printf("\n Diem: ");
			scanf("%f",&p->diem);
		}
		else break;
		p->next=f;
		f=p;
	}while(strcmp(t," ")!=0);
	return f;
}
void in(sinhvien *f)
{
	sinhvien *p;
	p=f;
	printf("\n\t Ten\t Tuoi\t Diem ");
	while(p!=NULL)
	{
		printf("\n\t %s\t %d\t %g ",p->ten,p->tuoi,p->diem);
		p=p->next;
	}
}
void sapxep(sinhvien *f)
{
	char n[30];
	int t;
	float d;
	sinhvien *p,*q;
	for(p=f;p!=NULL;p=p->next)
		for(q=p->next;q!=NULL;q=q->next)
		//	if(strcmp(p->ten,q->ten)>0)
			if(q->diem<p->diem)
			{
				strcpy(n,p->ten);
				strcpy(p->ten,q->ten);
				strcpy(q->ten,n);
				t=p->tuoi;
				p->tuoi=q->tuoi;
				q->tuoi=t;
				d=p->diem;
				p->diem=q->diem;
				q->diem=d;
			}
}
sinhvien *tim(sinhvien *f,char ht[30])
{
	sinhvien *p;
	for(p=f;p!=NULL;p=p->next)
		if(strcmp(p->ten,ht)==0)
			return p;
	return NULL;
}
void xoa(sinhvien **f)
{
	sinhvien *p,*r;
	p=*f;
	while(p!=NULL)
		if(p->diem<5)
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
		else
		p=p->next;
}
/*sinhvien *bosung(sinhvien *f)
{
	sinhvien *p;
	if(head==NULL)
	{
		head=f;
	}
	for(p=head;p->next!=NULL;p=p->next)
	p->next=f;
	return f;
}
sinhvien *chen(sinhvien *p)
{
	sinhvien *q;
	if(p==NULL||q==NULL||p==q||q->next==p)
	{
		printf("\n Khong the chen ");
	}
	p->next=q->next;
	q->next=p;
}*/

int main()
{
	char ht[30];
	sinhvien *first;
	first=NULL;
	first=nhap(first);
//	sapxep(first);
	in(first);
/*	printf("\n Nhap ho ten can tim: ");
	gets(ht);
	printf("\n Chuoi tim duoc la: %s",tim(first,ht));
*/	xoa(&first);
//	bosung(first);
//	chen(first);
	printf("\n Danh sach sau khi xoa: ");
	in(first);
	getch();
}
