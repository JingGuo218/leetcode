/*************************************************************************************** 
Source : https://leetcode.com/problems/first-unique-character-in-a-string/description/
Author : Jing Kuo

Description:Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Example:
    s = "leetcode"
    return 0.

    s = "loveleetcode",
    return 2.

Complexity:
    Time:O(1)
    Space:O(1)

Beats: 100% 

Approach: 

***************************************************************************************/
int firstUniqChar(char* s) {
    int HASH['z'+1]={0};  
    char *c=s;
    
    while(*c!='\0'){
        HASH[*c-'a']+=1;
        c++;
    }
    
    for(int i=0;s[i]!='\0';i++){
        if(HASH[s[i]-'a']==1) return i;
    }
    
    return -1;
}