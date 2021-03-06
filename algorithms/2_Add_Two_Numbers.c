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
    Space:O(1)

Beats:54% (not accurate, test time too short)
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
    
    struct ListNode* retNode = l1;
    struct ListNode* l1PretNode;
    struct ListNode* l2UsedToPutSum = l2;
    
    while( (l1!=NULL)||(l2!=NULL)||(carry!=0) )
    {    
        if (l1 == NULL) {//l1 node space is not enough to put sum, using l2 node s
            l1PretNode -> next = l2UsedToPutSum; 
            l2UsedToPutSum = l2UsedToPutSum->next;
            l1 = l1PretNode -> next;
            l1->next=NULL;
            l1->val=0;
        }
        
        if (l2 == NULL) l1->val += carry;  
        else l1->val += l2->val + carry; 
        
        if (l1->val > 9){
            carry = 1;
            l1->val -= 10;
        }
        else carry = 0;  
          
        l1PretNode = l1;
        l1 = l1->next;
        
        if (l2 != NULL) l2 = l2->next;
    }
    
        
    return retNode;
}