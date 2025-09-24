class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        // 0 1 2 3 4
        // 0,1,0,3,12
        // 1,0,0,3,12
        // 1,3,0,0,12

        int latestIndexOfZero = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                if (latestIndexOfZero == -1) {
                    latestIndexOfZero = i;
                }
            } else {
                if (latestIndexOfZero > -1) {
                    nums[latestIndexOfZero] = nums[i];
                    nums[i] = 0;
                    latestIndexOfZero = latestIndexOfZero + 1;
                }
            }
        }
    }
};