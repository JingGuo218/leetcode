/*************************************************************************************** 
Source : https://leetcode.com/problems/single-number/description/
Author : Jing Kuo

Description:
    Given a non-empty array of integers, every element appears twice except for one. 
    Find that single one.
    Note:
    Your algorithm should have a linear runtime complexity. 
    Could you implement it without using extra memory?

Example:
    Input: [4,1,2,1,2]
    Output: 4

Complexity:
    Time:O(n)
    Space:O(1)

Beats:100% 

Approach:
    a ^ 0 = a
    a ^ a = 0
    a ^ b ^ a = b
***************************************************************************************/

int singleNumber(int* nums, int numsSize) {
    
    if(1 == numsSize)
    {
        return nums[0];
    }
  
    while(numsSize > 1)
    {
        nums[0] ^= nums[--numsSize] ;
    }
    
    return nums[0];
}

