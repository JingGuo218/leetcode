/*************************************************************************************** 
Source : https://leetcode.com/problems/reverse-linked-list/description/
Author : Jing Kuo

Description:
    Reverse a singly linked list.

Example:
    Input: 1->2->3->4->5->NULL
    Output: 5->4->3->2->1->NULL

Complexity:
    Time:O(n)
    Space:O(1)

Beats: 100% 

Approach: 1. This is iteration
          2. Recursive

***************************************************************************************/
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* node=head;
    struct ListNode* nextNode;
    struct ListNode* preNode=NULL;
    
    if(head==NULL) return NULL;
    
    while(node!=NULL){
        nextNode=node->next;
        node->next=preNode;
        preNode=node;
        node=nextNode;
    }
    
    return preNode;
}


/* less effieicent recursive
struct ListNode* recur(struct ListNode* preNode,struct ListNode* curNode) {
    struct ListNode* nextNode;
    
    if(curNode==NULL) return preNode;
    
    nextNode=curNode->next;
    curNode->next=preNode;

    return recur(curNode,nextNode);
}

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* nextNode;

    if(head==NULL) return NULL;
    
    nextNode=head->next;
    head->next=NULL;
    
    return recur(head,nextNode);
}

*/


/* better effieicent recursive
public ListNode reverseList(ListNode head) {
    if (head == null || head.next == null) return head;
    ListNode p = reverseList(head.next);
    head.next.next = head;
    head.next = null;
    return p;
}
*/