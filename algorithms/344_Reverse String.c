char* reverseString(char* s) {
     int l = 0;
     int r = strlen(s)-1;
     char tmp;

     while(l<r)
     {
         tmp = s[l];
         s[l] = s[r];
         s[r] = tmp;
         l++;
         r--;
     }
 
     return s;
}