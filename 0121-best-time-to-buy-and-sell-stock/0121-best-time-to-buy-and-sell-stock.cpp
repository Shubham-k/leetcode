class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPriceOfStock = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > minPriceOfStock) {
                maxProfit = max(maxProfit, prices[i] - minPriceOfStock);
            }
            minPriceOfStock = min(minPriceOfStock, prices[i]);
        }

        return maxProfit;
    }
};