class MinStack {
    stack<pair<int, int>> stk;
public:
    MinStack() = default;
    
    void push(int val) {
        if (stk.empty()) {
            return stk.push(pair<int, int>(val, val));
        }
        int prevMin = stk.top().second;
        stk.push(pair<int, int>(val, min(prevMin, val)));        
    }
    
    void pop() {
        return stk.pop();
    }
    
    int top() {
        return stk.top().first;
    }
    
    int getMin() {
        return stk.top().second;
    }
};
