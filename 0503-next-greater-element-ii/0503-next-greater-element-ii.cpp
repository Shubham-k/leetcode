class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // 1 2 3  4  3  1 2 3 4  3
        // 2 3 4 -1  4  2 3 4 -1 -1

        // 3  4  3  2  1 3  4 3 2 1
        // -1 -1 4  3  2 4 -1 4 3 2

        // 2 3 4 -1 4 2 3 4 -1 -1
        int n = nums.size();
        nums.resize(2*n);
        for (int i = n; i < nums.size(); i++) {
            nums[i] = nums[i - n];
        }

        reverse(nums.begin(), nums.end());
        stack<int> s;
        s.push(nums[0]);

        vector<int> ans;
        ans.push_back(-1);
        for (int i = 1; i < nums.size(); i++) {
            while (!s.empty() && s.top() <= nums[i])
                s.pop();

            int res = s.empty() ? -1 : s.top();
            ans.push_back(res);
            s.push(nums[i]);
        }

        reverse(ans.begin(), ans.end());
        vector<int> firstHalf(ans.begin(), ans.begin() + ans.size()/2);
        return firstHalf;
    }
};