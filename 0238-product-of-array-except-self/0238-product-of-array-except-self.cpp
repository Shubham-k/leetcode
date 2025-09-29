class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // 0 1 2 3
        // 2 3 4 5

        int n = nums.size();
        vector<int> preficsProduct(n + 1);
        vector<int> suffixProduct(n + 1);

        // Prepare prefixProductArray
        preficsProduct[0] = 1;
        for (int i = 1; i < preficsProduct.size(); i++) {
            preficsProduct[i] = preficsProduct[i - 1] * nums[i - 1];
        }

        // Prepare suffixProductArray
        suffixProduct[suffixProduct.size() - 1] = 1;
        for (int i = suffixProduct.size() - 2; i >= 0; i--) {
            suffixProduct[i] = nums[i] * suffixProduct[i + 1];
        }

        for (int i = 0; i < n; i++) {
            nums[i] = preficsProduct[i] * suffixProduct[i + 1];
        }

        return nums;
    }
};