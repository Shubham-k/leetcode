class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // 73,74,75,71,69,72,76,73
        // 74 75 76 72 72 76 -1 -1

        // 73,76,72,69,71,75,74,73
        // -1 -1 76 72 72 76 75 74

        // 74 75 76 72 72 76 -1 -1

        // =======================

        // 73,74,75,71,69,72,76,73
        // 1  1  4  2  1  1  0  0

        // calculate -> 0  0  1  1  2  4  1  1
        // elements -> 73,76,72,69,71,75,74,73
        // index ->    0  1  2  3  5  6  7  8

        // 1 1 4 2 1 1 0 0

        reverse(temperatures.begin(), temperatures.end());
        stack<pair<int, int>> s;
        vector<int> ans;

        for (int i = 0; i < temperatures.size(); i++) {

            while (!s.empty() && s.top().first <= temperatures[i]) {
                s.pop();
            }

            int res = s.empty() ? 0 : i - s.top().second;
            ans.push_back(res);
            s.push({temperatures[i], i});
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};