#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv) 
{
 	int n, i, j;
 	printf("Nhap chieu cao tam giac:");
 	scanf("%d", &n);
 	for (i = 1; i <= n; i++)
	  {
 		for (j = 1; j <= n - i; j++)
 			printf(" ");
 			for (j = 1; j <= 2 * i - 1; j++)
			 printf("*");
			printf("\n");
	 }

}
