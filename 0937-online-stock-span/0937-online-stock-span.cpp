class StockSpanner {
public:
    int index;
    stack<pair<int, int>> s;
    StockSpanner() { index = -1; }

    int next(int price) {
        if (s.empty()) {
            index++;
            s.push({price, index});
            return index + 1;
        }

        if (s.top().first > price) {
            index++;
            int res = index - s.top().second;
            s.push({price, index});
            return res;
        } else {
            while (!s.empty() && s.top().first <= price) {
                s.pop();
            }
            index++;
            if (s.empty()) {
                s.push({price, index});
                return index + 1;
            } else {
                int res = index - s.top().second;
                s.push({price, index});
                return res;
            }
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */