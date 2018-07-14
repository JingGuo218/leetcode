/*************************************************************************************** 
Source : https://leetcode.com/problems/implement-strstr/description/
Author : Jing Kuo

Description:
    Implement strStr().
    Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example:
    Input: haystack = "hello", needle = "ll"
    Output: 2

Complexity:
    Time:O(n*m)
    Space:O(1)

Beats: 100% 

Approach: 

***************************************************************************************/
int strStr(char* haystack, char* needle) {
    int strlenHaystack,strlenNeedle;

    if ((haystack==NULL)||(needle==NULL)) return 0;
    
    strlenHaystack=strlen(haystack);
    strlenNeedle=strlen(needle);
    if(strlenNeedle==0) return 0;
    
    //if (strlenNeedle > strlenHaystack) return -1;  for loop has done this
    
    for(int idx=0;idx<=(strlenHaystack-strlenNeedle);idx++){
        if (strncmp(&haystack[idx],needle,strlenNeedle)==0) return idx;
    }
    return -1;
}