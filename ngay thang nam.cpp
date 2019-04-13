#include<stdio.h>
#include<conio.h>
int main()
{
	int ngay,thang,nam,thu;
	printf("\n Ngay : ");
	scanf("%d",&ngay);
	printf("\n Thang : ");
	scanf("%d",&thang);
	printf("\n Nam : ");
	scanf("%d",&nam);
	if(thang<3)
	{
		thang+=12;
		nam-=1;
	}
	thu=(ngay+2*thang+3*(thang+1)/5+nam+nam/4)%7;
	switch(thu)
	{
		case 0: printf("\n Chu nhat");
		break;
		case 1: printf("\n Thu 2");
		break;
		case 2: printf("\n Thu 3");
		break;
		case 3: printf("\n Thu 4");
		break;
		case 4: printf("\n Thu 5");
		break;
		case 5: printf("\n Thu 6");
		break;
		default: printf("\n Thu 7");
		break;
	}
	getch();
}
