/*C�u 15: Cho m?t t?, d?o l?n v?tr� c�c ch? c�i trong t? n�y, ta
 du?c t? m?i. T? m?i n�y du?c g?i l� �Anagram� c?a t? ban d?u.
  V� d?: cinema v� iceman, momdad v� dadmom. S?  d?ng  m?t 
   ng�n  ng?  l?p  tr�nh  b?t  k?d?vi?t  h�m  ki?m  tra hai 
    t?  c�  ph?i  l� Anagrams c?a nhau hay kh�ng? (ch? x�t
	 c�c k� t?ti?ng anh, ph�n bi?t hoa/thu?ng).*/
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
