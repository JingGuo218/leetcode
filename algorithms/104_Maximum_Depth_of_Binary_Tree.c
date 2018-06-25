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

Approach: Recursive

***************************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int recurMaxDepth(int depth, struct TreeNode* node){
    int retFromLeftTree=0;
    int retFromRightTree=0;
     
    if( (node->left == NULL)&& (node->right == NULL)) {
        return depth;
    }else if (node->left == NULL){
        retFromRightTree = recurMaxDepth(depth+1,node->right);
        retFromLeftTree = depth;
    }else if (node->right == NULL){
        retFromLeftTree = recurMaxDepth(depth+1,node->left);
        retFromRightTree = depth;
    }else{
        retFromRightTree = recurMaxDepth(depth+1,node->right);
        retFromLeftTree = recurMaxDepth(depth+1,node->left);
    }
    
    if (retFromLeftTree > retFromRightTree) return retFromLeftTree;
    else return retFromRightTree;
}

int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    else return recurMaxDepth(1,root);
}