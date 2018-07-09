/*************************************************************************************** 
Source : 
Author : Jing Kuo

Description:
    Given an integer, write a function to determine if it is a power of three.

Example:
    Input: 9
    Output: true

Complexity:
    Time:O(1)
    Space:O(1)

Beats: 100% 

Approach: 
    1. brute-force,O(log_3_n)
    2. comparing answer, O(1)
    3. Integer Limitations, O(1)

***************************************************************************************/

//brute-force O(log_3_n)
bool isPowerOfThree(int n) {
    if ((n==0)||(n<0)) return false;
    
    while((n%3)==0){
        n/=3;
    }
    
    return (n==1);
}

//comparing answer O(1)
bool isPowerOfThree(int n) {
    int powOfThreeArray[21]={1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323,4782969,14348907,43046721,129140163,387420489,1162261467,3486784401};
    
    for(int i=0;i<21;i++){
        if (n==powOfThreeArray[i]) return true;
    }
    
    return false;
}

//2147483648 (2^31)
//1162261467 (a int:maxium 3's pow)
//Integer Limitations, O(1)
bool isPowerOfThree(int n) {
    if (n<1) return false;
    
    return ((1162261467 % n)==0);
}