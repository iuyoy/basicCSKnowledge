/*
Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // Iteratively
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* ret = NULL;
        while(head != NULL){
            ListNode* temp = head;
            head = head->next;
            temp->next = ret;
            ret = temp;
        }
        return ret;
    }
};

// recursively

class Solution {
public:
    // return the reversed sub-list
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next == NULL)
            return head;
        // thus, the parameter (head->next) is the last node of the sub-list.
        ListNode* newHead = reverseList(head->next);
        // so the head is the next of the (head->next), to be the new end.
        head->next->next = head;
        // and finally, the next of head is NULL.
        head->next = NULL;
        return newHead;
    }
};
