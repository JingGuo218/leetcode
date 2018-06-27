/*************************************************************************************** 
Source : 237. Delete Node in a Linked List
Author : Jing Kuo

Description:
    Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
    Given linked list -- head = [4,5,1,9], which looks like following:
    4 -> 5 -> 1 -> 9

Example:
    Input: head = [4,5,1,9], node = 5
    Output: [4,1,9]
    Explanation: You are given the second node with value 5, the linked list
                should become 4 -> 1 -> 9 after calling your function.

Complexity:
    Time:O(1)
    Space:O(1)

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
void deleteNode(struct ListNode* node) {
    struct ListNode* next = node->next;
    *node = *next;
    free(next);
}