class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 012345678
        // cadbzabcd
        int left = 0;
        int right = 0;
        unordered_map<char, int> m;
        int maxLength = 0;

        while (right < s.length()) {
            if (m.find(s[right]) == m.end()) {
                m.insert({s[right], right});
            } else {
                if (m[s[right]] >= left) {
                    left = m[s[right]] + 1;
                }
                m[s[right]] = right;
            }

            maxLength = max(maxLength, right - left + 1);
            right++;
        }
        return maxLength;
    }
};