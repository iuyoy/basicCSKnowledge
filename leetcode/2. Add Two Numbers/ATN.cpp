/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* add(ListNode* l1, ListNode* l2, bool carry){
        if(l2 != NULL || carry != false){
            int val = carry;
            if(l2 != NULL){
                val += l2->val;
                l2 = l2->next;
            }
            if(l1 != NULL){
                l1->val += val;
            }else{
                l1 = new ListNode(val);
            }
            if(l1->val>=10){
                l1->val -= 10;
                carry = true;
            }else
                carry = false;
            l1->next = add(l1->next, l2, carry);
        }

        return l1;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2, false);
    }
};
