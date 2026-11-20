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
    int getListSize(ListNode* head) {
        int n = 0;
        while (head) {
            n++;
            head = head->next;
        }
        return n;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while(head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    void mergeLists(ListNode* head1, ListNode* head2) {
        while (head1 && head2) {
            ListNode* next1 = head1->next, *next2 = head2->next;
            head1->next = head2;
            head2->next = next1;
            head1 = next1;
            head2 = next2;
        }
        if (head1) {
            head1->next = nullptr;
        } else if (head2) {
            head2->next = nullptr;
        }
    }

public:
    void reorderList(ListNode* head) {
        int n = getListSize(head);
        // get the first node of the second list.
        int i = 0;
        ListNode* copy = head;
        while (i < n / 2) {
            i++;
            copy = copy->next;
        }
        ListNode* prev = reverseList(copy);
        mergeLists(head, prev);
    }
};
