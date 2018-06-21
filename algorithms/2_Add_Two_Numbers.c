/*************************************************************************************** 
Source : https://leetcode.com/problems/add-two-numbers/description/
Author : Jing Kuo

Description:
    You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
    Explanation: 342 + 465 = 807.

Complexity:
    Time:O(n)
    Space:O(n)

Beats:32.75%
***************************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry=0;
    int operatorA,operatorB;
    
    struct ListNode* retNode = NULL;
    struct ListNode* curNode = NULL;
    
    while( (l1!=NULL)||(l2!=NULL)||(carry!=0) )
    {
        if (curNode == NULL) curNode = malloc(sizeof(struct ListNode));
        else {
            curNode->next = malloc(sizeof(struct ListNode));
            curNode = curNode->next;
        }
        
        curNode->next=NULL;
            
        if (retNode == NULL) retNode=curNode;
            
        if (l1 == NULL) operatorA=0;
        else operatorA = l1->val;
        if (l2 == NULL) operatorB=0;
        else operatorB = l2->val;
        curNode->val = operatorA + operatorB + carry;
        
        
        if (curNode->val > 9) carry = 1;
        else carry = 0;  
        curNode->val %= 10;
        
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }
        
    return retNode;
}