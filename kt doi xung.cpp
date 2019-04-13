/*5 Câu 14: M?t xâu du?c g?i là d?i x?ng n?u d?c t?tru?c ra sau gi?ng 
v?i d?c t? sau ra tru?c. Ch? quan tâm ký t?ch? cái (t? A-Z và a-z),
 các ký t? còn l?i b? qua, không phân bi?t hoa-thu?ng. Ví d?:“Noel 
 sees Leon” hay “Noel sees 1 Leon.” là các xâu d?i x?ng.S?  d?ng  
 m?t  ngôn  ng?  l?p  trình  b?t  k?d?  vi?t  hàm  ki?m  tra  m?t 
  xâu  có d?i  x?ng hay không?*/
#include<conio.h>

 char isAlpha(char ch)
  { return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); } 
  char toLowerCase(char ch)
   { if (ch < 'a') return ch + 'a' - 'A'; } 
   bool isSymmetric(char *str, int length) 
   { int headIndex = 0;
    int tailIndex = length - 1; 
	while (headIndex < tailIndex) 
	{ if (!isAlpha(str[headIndex])) {    
	                  headIndex++; continue;   
	            } if (!isAlpha(str[tailIndex])) 
				{                      tailIndex--; continue;      }
				 if (toLowerCase(str[headIndex]) != toLowerCase(str[tailIndex]))
				  return 0;             
				    headIndex++;             
				  tailIndex--;
			}
			return 1;
		}
int main()
{
	char s[50];
	cout<<"\nn Nhap chuoi: ";
	gets(s);
	
}

