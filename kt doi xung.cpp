/*5 C�u 14: M?t x�u du?c g?i l� d?i x?ng n?u d?c t?tru?c ra sau gi?ng 
v?i d?c t? sau ra tru?c. Ch? quan t�m k� t?ch? c�i (t? A-Z v� a-z),
 c�c k� t? c�n l?i b? qua, kh�ng ph�n bi?t hoa-thu?ng. V� d?:�Noel 
 sees Leon� hay �Noel sees 1 Leon.� l� c�c x�u d?i x?ng.S?  d?ng  
 m?t  ng�n  ng?  l?p  tr�nh  b?t  k?d?  vi?t  h�m  ki?m  tra  m?t 
  x�u  c� d?i  x?ng hay kh�ng?*/
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

