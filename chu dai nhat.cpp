#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

char *findWordMax(char *s)
{
	int i;
	int flag = 0;
	int lenWord;
	int startIndexWord, endIndexWord;
	
	int lenWordMax = 0;
	int startIndexWordMax, endIndexWordMax;
	
	char *wordMax;
	
	for (i=0; i<strlen(s); i++)
	{
		if (s[i]==32)
		{
			if (flag == 1)
			{
				flag = 0;
				endIndexWord = i-1;
				lenWord = (endIndexWord - startIndexWord) + 1;
				if (lenWord > lenWordMax)
				{
					lenWordMax = lenWord;
					startIndexWordMax = startIndexWord;
					endIndexWordMax = endIndexWord;
				}				
			}
		}
		else
		{
			if (flag == 0)
			{
				flag = 1;
				startIndexWord = i;
			}
		}
	}
	
	wordMax = (char*)malloc(lenWordMax + 1);
	for (i=0; i<lenWordMax; i++)
		wordMax[i] = s[i+startIndexWordMax];
	wordMax[lenWordMax] = '\0';
	
	return wordMax;
}

int main()
{
	char s[100];
	char *word;
	
	printf("Nhap chuoi: ");
	gets(s);	
	word = findWordMax(s);
	
	printf("Tu lon nhat '%s' co do dai %d", word, strlen(word));
	
	return 1;
}
