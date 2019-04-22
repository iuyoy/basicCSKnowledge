/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// O(n) a litte complex
class Solution {
  public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *p = new ListNode(0);
        p->next = head;
        head = p;
        int i = 1;
        for (; i < m; ++i, p = p->next)
            ;
        ListNode *reverse = new ListNode(0);
        reverse->next = p->next;
        ListNode *end = p->next;
        ListNode *back = end->next;
        for (; i < n; ++i) {
            ListNode *temp = back->next;
            back->next = reverse->next;
            reverse->next = back;
            back = temp;
        }
        end->next = back;
        p->next = reverse->next;
        return head->next;
    }
};