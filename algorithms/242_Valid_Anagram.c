/*************************************************************************************** 
Source : https://leetcode.com/problems/valid-anagram/description/
Author : Jing Kuo

Description: Given two strings s and t , write a function to determine if t is an anagram of s.

Example:
    Input: s = "anagram", t = "nagaram"
    Output: true

Complexity:
    Time:O(n)
    Space:O(1)

Beats: 100% 

Approach: HASH

***************************************************************************************/
bool isAnagram(char* s, char* t) {
    int Hash[26]={0};
    
    while(*s!='\0'){
        Hash[*s-'a']++;
        s++;
    }
    
    while(*t!='\0'){
        Hash[*t-'a']--;
        t++;
    }
    
    for (int i=0;i<26;i++){
        if (Hash[i]!=0) return false;
    }
    
    return true;   
}