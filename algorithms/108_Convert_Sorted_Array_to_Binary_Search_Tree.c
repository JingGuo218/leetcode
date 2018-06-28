/*************************************************************************************** 
Source : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
Author : Jing Kuo

Description:
    Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
    For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:
    Given the sorted array: [-10,-3,0,5,9],

    One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

        0
        / \
    -3   9
    /   /
    -10  5

Complexity:
    Time:O(n)
    Space:O(n)

Beats: 21.33% 

Approach: recursive

***************************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* FindRoot(int* nums, int start, int end){
    if (start > end) return NULL;
    else{
        struct TreeNode* root = malloc(sizeof(struct TreeNode));
        int mid=(end+start+1)/2;
        root->val=nums[mid];
        root->left=FindRoot(nums,start,mid-1);
        root->right=FindRoot(nums,mid+1,end);

        return root;
    }
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return FindRoot(nums,0,numsSize-1);
}