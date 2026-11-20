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
        Node *iter = head;
        while (iter) {
            seen[iter] = new Node(iter->val);
            iter = iter->next;
        }
        iter = head;
        while (iter) {
            Node *other = seen[iter];
            other->next = seen[iter->next];
            other->random = seen[iter->random];
            iter = iter->next;
        }
        return seen[head];
    }
};
