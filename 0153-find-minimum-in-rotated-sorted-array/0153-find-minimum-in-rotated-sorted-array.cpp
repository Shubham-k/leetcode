class Solution {
public:
    int findMin(vector<int>& nums) {
        // 0 1 2 3 4 5 6 7
        // 7 8 1 2 3 4 5 6

        int low = 0;
        int high = nums.size() - 1;
        int ans = INT_MAX;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            } else {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }
};