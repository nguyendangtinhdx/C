#include<stdio.h>
#include<conio.h>
int main()
{
	char s[50];
	int ns,can,chi;
	printf("\n Ten: ");
	gets(s);
	printf("\n Nam sinh: ");
	scanf("%d",&ns);
	can=ns%10;
	chi=ns%12;
	printf("\n %s Tuoi : ",s);
	switch(can)
	{
		case 0: printf("\n Canh ");break;
		case 1: printf("\n Tan ");break;
		case 2: printf("\n Nham ");break;
		case 3: printf("\n Quy");break;
		case 4: printf("\n Giap ");break;
		case 5: printf("\n At ");break;
		case 6: printf("\n Binh ");break;
		case 7: printf("\n Dinh ");break;
		case 8: printf("\n Mau ");break;
		case 9: printf("\n Ky ");break;
	}
	switch(chi)
	{
		case 0: printf("Than");break;
		case 1: printf("Dau");break;
		case 2: printf("Tuat");break;
		case 3: printf("Hoi");break;
		case 4: printf("Ty");break;
		case 5: printf("Suu");break;
		case 6: printf("Dan");break;
		case 7: printf("Meo");break;
		case 8: printf("Thin");break;
		case 9: printf("Ty.");break;
		case 10: printf("Ngo");break;
		case 11: printf("Mui");break;		
	}
	getch();
}
