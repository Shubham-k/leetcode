class MinStack {
public:
    vector<pair<int, int>> v;
    int minElement;
    MinStack() { minElement = INT_MAX; }

    void push(int val) {
        minElement = min(minElement, val);
        v.push_back({val, minElement});
    }

    void pop() {
        v.pop_back();
        if (!v.size()) {
            minElement = INT_MAX;
        } else {
            minElement = v.back().second;
        }
    }

    int top() { return v.back().first; }

    int getMin() { return v.back().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */