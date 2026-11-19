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
    ListNode* getSmaller(ListNode*& list1, ListNode*& list2) {
        if (list2  && (list1 == nullptr || list1->val > list2->val)) {
            ListNode* ptr = list2;
            list2 = list2->next;
            return ptr;
        }
        ListNode* ptr = list1;
        list1 = list1->next;
        return ptr;
    }

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }
        ListNode* head = getSmaller(list1, list2), *res = head;
        while (list1 || list2) {
            head->next = getSmaller(list1, list2);
            head = head->next;
        }
        return res;
    }
};
