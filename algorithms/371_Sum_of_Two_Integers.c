/*************************************************************************************** 
Source : https://leetcode.com/problems/sum-of-two-integers/description/
Author : Jing Kuo

Description:
    Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
    Given a = 1 and b = 2, return 3.

Complexity:
    Time:O(n)
    Space:O(1)

Beats: 100% 

Approach: recursive 

***************************************************************************************/

int getSum(int a, int b) {
    return (b==0)?a:getSum(a^b,(a&b)<<1);
}
