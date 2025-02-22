class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minElement = prices[0];
        int res = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > minElement) {
                res = max(prices[i] - minElement, res);
            }
            minElement = min(minElement, prices[i]);
        }

        return res;
    }
};