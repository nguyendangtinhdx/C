/*Câu 15: Cho m?t t?, d?o l?n v?trí các ch? cái trong t? này, ta
 du?c t? m?i. T? m?i này du?c g?i là “Anagram” c?a t? ban d?u.
  Ví d?: cinema và iceman, momdad và dadmom. S?  d?ng  m?t 
   ngôn  ng?  l?p  trình  b?t  k?d?vi?t  hàm  ki?m  tra hai 
    t?  có  ph?i  là Anagrams c?a nhau hay không? (ch? xét
	 các ký t?ti?ng anh, phân bi?t hoa/thu?ng).*/
	 char areStringsAnagrams(char *a, int lengtha, char *b, int lengthb)
	  { int freqa[128] = { 0 };
	   int freqb[128] = { 0 };
	    if (lengtha != lengthb) 
		return 0; 
		for (int i = 0; i < lengtha; i++) 
		{               freqa[a[i]]++;               freqb[b[i]]++;        } 
		for (int i = 0; i < 128; i++) if (freqa[i] != freqb[i]) 
		return 0;
		return 1;
	}
