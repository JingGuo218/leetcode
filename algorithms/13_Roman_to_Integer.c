/*************************************************************************************** 
Source : https://leetcode.com/problems/roman-to-integer/description/
Author : Jing Kuo

Description:
    Symbol       Value
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000

Example:
    Input: "IV"
    Output: 4

    Input: "MCMXCIV"
    Output: 1994
    Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

Complexity:
    Time:O(n)
    Space:O(1)

Beats: 100% 

Approach/Note: A good question is to use switch to map int.
    May it be fater rathan than array index mapping if CPU support some 
    assembly code to eecute switch faster.

***************************************************************************************/
/*int RomanMapToIntFun(char charIn){
    switch(charIn)
    {
            case'I':return 1;
            case'V':return 5;
            case'X':return 10;
            case'L':return 50;
            case'C':return 100;
            case'D':return 500;
            case'M':return 1000;
    }
    return 0;
}*/

int romanToInt(char* s) {
    int RomanMapToInt['X'+1];
    int retSum=0;
    int curInt=0;
    int preInt=1001;
    
    RomanMapToInt['I']=1;
    RomanMapToInt['V']=5;
    RomanMapToInt['X']=10;
    RomanMapToInt['L']=50;
    RomanMapToInt['C']=100;
    RomanMapToInt['D']=500;
    RomanMapToInt['M']=1000;
    
    if(s==NULL) return 0;
    
    while(*s!='\0'){
        curInt = RomanMapToInt[*s];
        //curInt = RomanMapToIntFun(*s);
        
        retSum +=curInt;
        
        if(preInt < curInt){
            retSum -= preInt*2 ;
        }
        
        preInt=curInt;
        s++;
    }       
        
    return retSum;
}

/*  less eficeient,
int romanToInt(char* s) {
    char preChar=0;
    int retSum=0;
    int addedNum=0;
    
    if(s==NULL) return 0;
    
    while(*s!='\0'){
        switch(*s){
            case 'I':
                addedNum=1;
                break;
            case 'V':
                if (preChar=='I') addedNum=3;
                else addedNum=5;
                break;
            case 'X':
                if (preChar=='I') addedNum=8;
                else addedNum=10;
                break;    
            case 'L':
                if (preChar=='X') addedNum=30;
                else addedNum=50;
                break;
            case 'C':
                if (preChar=='X') addedNum=80;
                else addedNum=100;
                break;
            case 'D':
                if (preChar=='C') addedNum=300;
                else addedNum=500;
                break;
            case 'M':
                if (preChar=='C') addedNum=800;
                else addedNum=1000;
                break;
            default:
                addedNum=0;
                break;
        }
                    
        retSum += addedNum;
        preChar=*s;
        s++;
    }
    
    return retSum;
}*/