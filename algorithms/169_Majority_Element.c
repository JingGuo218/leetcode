/*************************************************************************************** 
Source : https://leetcode.com/problems/majority-element/description/
Author : Jing Kuo

Description:
    Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
    You may assume that the array is non-empty and the majority element always exist in the array.
Example:
    Input: [2,2,1,1,1,2,2]
    Output: 2

Complexity:
    Time:O(n)
    Space:O(1)

Beats: 100% 

Approach:
    1. sorting and take medium element. T:O(n), S:O(1).
    2. using hash. T:O(n), S:O(n).
    3. Below approach, also called Boyer-Moore
***************************************************************************************/
int majorityElement(int* nums, int numsSize) {
    int candidate=*nums;
    int cnt=1;
    for (int i=1;i<numsSize;i++){
        
        if (cnt==0) candidate=nums[i];
        
        if(nums[i]!=candidate){
            cnt--;
        }else{
            cnt++;
        }  
    }
    return candidate;
}