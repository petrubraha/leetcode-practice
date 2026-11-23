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
        deque<ListNode*> q;
        while (head) {
            q.push_back(head);
            head = head->next;
        }
        ListNode *next = nullptr, *front = nullptr, *back = nullptr;
        while (!q.empty()) {
            front = q.front();
            q.pop_front();
            if (q.empty()) {
                break;
            }
            back = q.back();
            q.pop_back();
            next = front->next;
            front->next = back;
            back->next = next;
        }
        if (next) {
            next->next = nullptr;
        }
    }
};