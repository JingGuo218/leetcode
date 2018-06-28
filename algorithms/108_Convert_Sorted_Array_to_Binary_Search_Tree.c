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
bool recur(struct TreeNode** node,int* nums, int numsSize){
    
    if (numsSize == 0) return true;
    
    *node = malloc(sizeof(struct TreeNode));
    (*node)->val = nums[numsSize/2];
    (*node)->left = NULL;
    (*node)->right = NULL;
    
    printf("%d, %d\n",(*node)->val,numsSize);

    return recur(&((*node)->left),&nums[0],numsSize/2)&&
           recur(&((*node)->right),&nums[numsSize/2+1],numsSize-1-numsSize/2) ;

}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    
    if(numsSize==0) return NULL;
    
    struct TreeNode*  head = malloc(sizeof(struct TreeNode));
    head->val=nums[numsSize/2];
    head->left=NULL;
    head->right=NULL;
    
    if(numsSize==1) return head;
    
    if ( recur(&head->left,&nums[0],numsSize/2)&&
         recur(&head->right,&nums[numsSize/2+1],numsSize-1-numsSize/2) ){
        return head;      
    }else{
        return NULL;
    }
    
}