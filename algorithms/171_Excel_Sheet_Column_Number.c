/*************************************************************************************** 
Source : https://leetcode.com/problems/excel-sheet-column-number/description/
Author : Jing Kuo

Description:
    Given a column title as appear in an Excel sheet, return its corresponding column number.

Example:
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...

    Input: "A"
    Output: 1
    Input: "AB"
    Output: 28

Complexity:
    Time:O(n)
    Space:O(1)

Beats: 100% 

Approach: 

***************************************************************************************/

int titleToNumber(char* s) {
    int retSum=0;
    
    if (s==NULL) return 0;
    
    while(*s != '\0'){
        retSum *= 26;
        retSum += (*s)-'A'+1;
        s++;
    }
    
    return retSum;
}