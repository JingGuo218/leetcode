/*************************************************************************************** 
Source : https://leetcode.com/problems/climbing-stairs/description/
Author : Jing Kuo

Description:
    You are climbing a stair case. It takes n steps to reach to the top.

    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

    Note: Given n will be a positive integer.

Example:
    Input: 2
    Output: 2
    Explanation: There are two ways to climb to the top.
    1. 1 step + 1 step
    2. 2 steps

Complexity:
    Time:O(n)
    Space:O(1)

Beats: 100% 

Approach:
    1. current:like FIB
    2. recursive. T:O(2^n), S:O(n)
    3. recursive with memoization. T:O(n), S:O(n)
    4. O(nlog n)
        Fibonacci Formula:f(n)= .....
        pow method takes log(n)log(n) time.
***************************************************************************************/
int climbStairs(int n) {
    
    /* recursive way
    if (n==0) return 0;
    if (n==1) return 1;
    if (n==2) return 2;
    
    return climbStairs(n-1)+climbStairs(n-2);*/
    
    int ret=0;
    int pre_1st_num=1;
    int pre_2nd_num=2;
    
    if (n==0) return 0;
    if (n==1) return 1;
    if (n==2) return 2;
    
    for(int i=0;i< (n-2);i++){
        ret=pre_1st_num+pre_2nd_num;
        pre_1st_num=pre_2nd_num;
        pre_2nd_num=ret;
    }
    
    return ret;
}