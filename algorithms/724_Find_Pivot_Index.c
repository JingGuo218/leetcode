/*************************************************************************************** 
Source : https://leetcode.com/problems/find-pivot-index/solution/
Author : Jing Kuo

Description:
    Given an array of integers nums, write a method that returns the "pivot" index of this array.
    We define the pivot index as the index where the sum of the numbers to the left of the index is equal to the sum of the numbers to the right of the index.
    If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.

Example:
    Input: 
    nums = [1, 7, 3, 6, 5, 6]
    Output: 3

    Input: 
    nums = [-1, -1, -1, 0, 1, 1]
    Output: 0

Complexity:
    Time:O(n)
    Space:O(1)

Beats: 100% 

Approach: 

***************************************************************************************/
int pivotIndex(int* nums, int numsSize) {
    
    if (numsSize==0) return -1;
    
    int total=0;
    int sum=0;
    int idx=0;
    
    for(;idx<numsSize;idx++){
        total+=nums[idx];
    }
    
    for(idx=0;idx<numsSize;idx++){
        if ((sum<<1) == (total-nums[idx])) return idx;
        else sum+=nums[idx];
    }
    
    return -1;   
}