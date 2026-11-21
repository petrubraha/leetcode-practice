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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = nullptr;
        if (list1 == nullptr) {
            if (list2 == nullptr) {
                return nullptr;
            }
            head = list2;
            list2 = list2->next;
        } else {
            if (list2 == nullptr) {
                head = list1;
                list1 = list1->next;
            } else {
                if (list1->val > list2->val) {
                    head = list2;
                    list2 = list2->next;
                } else {
                    head = list1;
                    list1 = list1->next;
                }
            }
        }
        ListNode *iter = head;
        while (list1 && list2) {
            if (list1->val > list2->val) {
                iter->next = list2;
                iter = iter->next;
                list2 = list2->next;
            } else {
                iter->next = list1;
                iter = iter->next;
                list1 = list1->next;
            }
        }
        if (list1) {
            iter->next = list1;
        } else if (list2) {
            iter->next = list2;
        }
        return head;
    }
};
/**
1->2
5
2->4
*/