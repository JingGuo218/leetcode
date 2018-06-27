/*************************************************************************************** 
Source : https://leetcode.com/problems/contains-duplicate/description/
Author : Jing Kuo

Description:
Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example:
    Input: [1,2,3,4]
    Output: false

    Input: [1,1,1,3,3,4,3,2,4,2]
    Output: true

Complexity:
    Time:O(nlogn)
    Space:O(1)

Beats: 100% 

Approach: 1. This is sortubg+compare
          2. Can use hash, T:O(n),S:O(1S)

***************************************************************************************/
int cmp(const int *a, const int *b) {
    return *a-*b;
}

bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),cmp);

    for (int i = 1; i < numsSize; i++)
    {
        if(nums[i] == nums[i-1])    return true;
    }

    return false;
}