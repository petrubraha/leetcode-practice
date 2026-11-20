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
        ListNode *head = new ListNode(), *copy = head;
        int carry = 0;
        while (l1 && l2) {
            int sum = l1->val + l2->val + carry;
            head->next = new ListNode(sum % 10);
            carry = sum / 10;
            head = head->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* ptr = l1 ? l1 : l2;
        while (ptr) {
            int sum = ptr->val + carry;
            head->next = new ListNode(sum % 10);
            carry = sum / 10;
            head = head->next;
            ptr = ptr->next;
        }
        if (carry) {
            head->next = new ListNode(1);
        }
        ListNode* res = copy->next;
        delete copy;
        return res;
    }
};
