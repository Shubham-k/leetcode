class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 0 1 2  3
        // 3 2 3
        // 3 5 8

        unordered_map<int, int> m;
        vector<int> v;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(target - nums[i]) == m.end()) {
                m.insert({nums[i], i});
            } else {
                v.push_back(m[target - nums[i]]);
                v.push_back(i);
                break;
            }
        }

        return v;
    }
};