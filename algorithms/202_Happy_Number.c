/*************************************************************************************** 
Source : https://leetcode.com/problems/happy-number/description/
Author : Jing Kuo

Description:
    Write an algorithm to determine if a number is "happy".
    A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example:
    Input: 19
    Output: true
    Explanation: 
    12 + 92 = 82
    82 + 22 = 68
    62 + 82 = 100
    12 + 02 + 02 = 1

Complexity:
    Time:O(1)
    Space:O(1)

Beats: 100% 

Approach: 1. using magic number 4
             all unhappy number contained 4 in  computing sum sequence
          2. Floyd Cycle detection algorithm 
             龜兔賽跑

***************************************************************************************/
bool isHappy(int n) {
    int sum=0;
    
    if (n==0) return false;
    
    while(n!=1){
        while(n!=0){
            sum+= (n%10)*(n%10);
            n/=10;
        }
        
        if (sum==4) return false;
        n=sum;
        sum=0;
        //printf("%d\n",n); 
    }
    
    return (n==1)?true:false;
}

/* approach 2
int digit2SquareSum(int n){
    int sum=0;
    while(n!=0){
        sum+= (n%10)*(n%10);
        n/=10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow=n, fast=n;
    
    if (n==0) return false;
    
    do{
        slow=digit2SquareSum(slow);
        fast=digit2SquareSum(fast);
        fast=digit2SquareSum(fast);   
        if ((slow==1)||(fast==1)) return true;
    }while(slow!=fast);
    
    return false;
}
*/
