/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *copy = nullptr;
        unordered_map<Node*, Node*> oldToCopy;
        oldToCopy[nullptr] = nullptr;
        while (head) {
            auto [it, inserted] = oldToCopy.try_emplace(head, nullptr);
            if (inserted) {
                it->second = new Node(head->val);
            }
            auto [nIt, nInserted] = oldToCopy.try_emplace(head->next, nullptr);
            if (nInserted) {
                nIt->second = new Node(head->next->val);
            }
            auto [rIt, rInserted] = oldToCopy.try_emplace(head->random, nullptr);
            if (rInserted) {
                rIt->second = new Node(head->random->val);
            }
            it->second->next = nIt->second;
            it->second->random = rIt->second;
            copy = copy ? copy : it->second;
            head = head->next;
        }
        return copy;
    }
};