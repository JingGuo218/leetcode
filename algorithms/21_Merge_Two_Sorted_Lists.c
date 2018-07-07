/*************************************************************************************** 
Source : https://leetcode.com/problems/merge-two-sorted-lists/description/
Author : Jing Kuo

Description:
    Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:
    Input: 1->2->4, 1->3->4
    Output: 1->1->2->3->4->4

Complexity:
    Time:O(n+m)
    Space:O(n+m)

Beats: 100% 

Approach: 

***************************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head=NULL;
    struct ListNode* node=NULL;
    
    while((l1!=NULL)||(l2!=NULL)){
        
        if(node==NULL){
            node=malloc(sizeof(struct ListNode)); 
            head=node;
        }else{
            node->next=malloc(sizeof(struct ListNode));
            node=node->next;
        }
        node->next=NULL;
        
        if (l2==NULL){
            node->val=l1->val;
            l1=l1->next;
        }else if (l1==NULL){
            node->val=l2->val;
            l2=l2->next;
        }else if(l1->val<l2->val){
            node->val=l1->val;
            l1=l1->next;
        }else{
            node->val=l2->val;
            l2=l2->next;
        }
    }
    
    return head;
    
}