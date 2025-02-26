class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // 1 2 3 4  3 1 2 3 4  3
        // 2 3 4 -1 4 2 3 4 -1 -1

        // 3   4 3 2 1 3 4  3 2 1
        // -1 -1 4 3 2 4 -1 4 3 2
        int n = nums.size();
        nums.resize(n * 2);
        for (int i = n; i < nums.size(); i++) {
            nums[i] = nums[i - n];
        }

        vector<int> ans;
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            int res = st.empty() ? -1 : st.top();
            st.push(nums[i]);
            ans.push_back(res);
        }
        reverse(ans.begin(), ans.end());
        vector<int> firstHalf(ans.begin(), ans.begin() + ans.size() / 2);

        return firstHalf;
    }
};