/*************************************************************************************** 
Source : https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
Author : Jing Kuo

Description:
    Given a binary tree, find its maximum depth.
    The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example:
    Given binary tree [3,9,20,null,null,15,7],
    return its depth = 3.

Complexity:
    Time:O(n)
    Space:O(1)

Beats:100% 

Approach: Recursive DFS

***************************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    else{
        int leftRet = maxDepth(root->left);
        int rightRet = maxDepth(root->right);
        return (leftRet>rightRet)?leftRet+1:rightRet+1;
    } 
}