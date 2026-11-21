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
    ListNode* getSmaller(ListNode *&list1, ListNode *&list2) {
        if (!list2 || (list1 && list1->val < list2->val)) {
            ListNode *head = list1;
            list1 = list1->next;
            return head;
        }
        ListNode *head = list2;
        list2 = list2->next;
        return head;
    }

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }
        ListNode *iter = getSmaller(list1, list2), *head = iter;
        while (list1 || list2) {
            iter->next = getSmaller(list1, list2);
            iter = iter->next;
        }
        return head;
    }
};