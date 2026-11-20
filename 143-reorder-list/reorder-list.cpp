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
    void reorderList(ListNode* head) {
        ListNode* copy = head;
        int n = 0;
        while (copy) {
            n++;
            copy = copy->next;
        }
        vector<ListNode*> arr(n, nullptr);
        copy = head;
        int i = 0;
        while (copy) {
            arr[i] = copy;
            i++;
            copy = copy->next;
        }
        for (i = 0; i < n / 2; ++i) {
            arr[i]->next = arr[n - 1 - i];
            arr[n - 1 - i]->next = arr[i + 1];
        }
        arr[i]->next = nullptr;
    }
};
