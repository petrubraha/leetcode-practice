/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *iter = l1, *head = iter;
        int carry = 0;
        while (l1 && l2) {
            int sum = l1->val + l2->val + carry;
            l1->val = sum % 10;
            carry = sum / 10;
            iter = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode *l0 = l1 ? l1 : l2;
        iter->next = l0;
        while (l0 && carry) {
            int sum = l0->val + carry;
            l0->val = sum % 10;
            carry = sum / 10;
            iter = l0;
            l0 = l0->next;            
        }
        if (carry) {
            iter->next = new ListNode(1);
        }
        return head;
    }
};