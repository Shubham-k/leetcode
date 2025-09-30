class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int maxLength = 0;
        unordered_map<char, int> map;

        while (right < s.length()) {
            if (map.find(s[right]) == map.end()) {
                map.insert({s[right], right});
            } else {
                if (map[s[right]] >= left) {
                    left = map[s[right]] + 1;
                }
                map[s[right]] = right;
            }
            maxLength = max(maxLength, right - left + 1);
            right++;
        }

        return maxLength;
    }
};