class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 0 1 2 3 4 5 6 7 8
        // 7 8 9 1 2 3 4 5 6
        // target = 1

        int low = 0;
        int high = nums.size() - 1;
        int mid;

        while (low <= high) {
            mid = (low + high) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[low] <= nums[mid]) { 
                if (target < nums[mid] && target >= nums[low]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (target <= nums[high] && target > nums[mid]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};