/*************************************************************************************** 
Source : https://leetcode.com/problems/count-and-say/description/
Author : Jing Kuo

Description:
    The count-and-say sequence is the sequence of integers with the first five terms as following:

    1.     1
    2.     11
    3.     21
    4.     1211
    5.     111221
    1 is read off as "one 1" or 11.
    11 is read off as "two 1s" or 21.
    21 is read off as "one 2, then one 1" or 1211.
    Given an integer n, generate the nth term of the count-and-say sequence.

    Note: Each term of the sequence of integers will be represented as a string.

Example:
    1.     1
    2.     11
    3.     21
    4.     1211
    5.     111221 
    6.     312211
    7.     13112221
    8.     1113213211
    9.     31131211131221
    10.    13211311123113112211

Complexity:
    Time:O(n^2)
    Space:O(n)

Beats:100% 

Approach: Recursive

***************************************************************************************/

char* recur(int n, char* inStr){
    char* retStrHead = malloc( strlen(inStr)*2+1);
    char* retStrPtr = retStrHead;
    char* inStrPtr = inStr;
    char preChar=*inStr;
    int cnt=0;

    while(1){
        if ((*inStrPtr!=preChar)||(*inStrPtr=='\0')) {
            *retStrPtr = '0'+ cnt;
            retStrPtr++;
            *retStrPtr = preChar;
            retStrPtr++;

            cnt=1;
            preChar=*inStrPtr;
        }else{
            cnt++; 
        }

        if (*inStrPtr=='\0'){
            break;
        }

        inStrPtr++;
    }

    *retStrPtr ='\0';
    
    if (*(inStr+1)!='\0') free(inStr);
    
    if (n==2){
        return retStrHead;
    }else{
        return recur(n-1,retStrHead);
    }
}

char* countAndSay(int n) {
    if (n==1) return "1";
    else return recur(n,"1");
}