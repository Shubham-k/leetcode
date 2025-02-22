class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // [2,3,4,5]
        // [60,40,30,24]

        vector<int> prefixProduct(nums.size() + 1);
        vector<int> suffixProduct(nums.size() + 1);
        prefixProduct[0] = 1;
        suffixProduct[nums.size()] = 1;

        for (int i = 1; i < nums.size() + 1; i++) {
            prefixProduct[i] = prefixProduct[i - 1] * nums[i - 1];
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            suffixProduct[i] = suffixProduct[i + 1] * nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            nums[i] = prefixProduct[i] * suffixProduct[i + 1];
        }

        return nums;

        // 0   1  2  3  4
        // 1   2  6  24 120
        // 120 60  20  5  1
    }
};