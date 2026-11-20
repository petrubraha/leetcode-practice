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
        unordered_map<Node*, Node*> seen;
        seen[nullptr] = nullptr;
        Node *iter = head;
        while (iter) {
            auto [iterIt, iterInserted] = seen.try_emplace(iter, nullptr);
            if (iterInserted) {
                iterIt->second = new Node(iter->val);
            }
            auto [nextIt, nextInserted] = seen.try_emplace(iter->next, nullptr);
            if (nextInserted) {
                nextIt->second = new Node(iter->next->val);
            }
            auto [randIt, randInserted] = seen.try_emplace(iter->random, nullptr);
            if (randInserted) {
                randIt->second = new Node(iter->random->val);
            }
            iterIt->second->next = nextIt->second;
            iterIt->second->random = randIt->second;
            iter = iter->next;
        }
        return seen[head];
    }
};
