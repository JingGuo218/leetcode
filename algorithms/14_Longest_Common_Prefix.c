/*************************************************************************************** 
Source : https://leetcode.com/problems/longest-common-prefix/description/
Author : Jing Kuo

Description:
    Write a function to find the longest common prefix string amongst an array of strings.
    If there is no common prefix, return an empty string "".

Example:
    Input: ["flower","flow","flight"]
    Output: "fl"

Complexity:
    Time:O(length of all string)
    Space:O(1)

Beats: 100% 

Approach: 

***************************************************************************************/
char* longestCommonPrefix(char** strs, int strsSize) {
    char *retStr=strs[0];
    int i=0;
                        
    if (strsSize==0){
        retStr = malloc(sizeof(char));
        *retStr = '\0';
        return retStr; 
    } 
                  
    for(int row=1;row<strsSize;row++){
        for(i=0;(retStr[i]!='\0')&&(strs[row][i]!='\0');i++){
            if (retStr[i]!=strs[row][i]){
                break;
            }
        }
        
        if (retStr[i]!='\0') retStr[i]='\0';
    }
                              
    return retStr;
}