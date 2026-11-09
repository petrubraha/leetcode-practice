class MinStack {
    stack<int> values, minimums;
public:
    void push(int value) {
        values.push(value);
        if (minimums.empty()) {
            return minimums.push(value);
        }
        int prevTop = minimums.top();
        minimums.push(min(prevTop, value));
    }
    
    void pop() {
        values.pop();
        minimums.pop();
    }
    
    int top() {
        return values.top();
    }
    
    int getMin() {
        return minimums.top();
    }
};