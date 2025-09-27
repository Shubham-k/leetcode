class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minElement = nums[0];
        int maxDifference = -1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > minElement) {
                maxDifference = max(maxDifference, nums[i] - minElement);
            }
            minElement = min(minElement, nums[i]);
        }

        return maxDifference;
    }
};