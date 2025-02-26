class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    return false;
                }
                if (!isBracketMatching(st.top(), s[i])) {
                    return false;
                }

                st.pop();
            }
        }

        return st.empty() == true;
    }

    bool isBracketMatching(char a, char b) {
        if (a == '(' && b == ')') {
            return true;
        }

        if (a == '[' && b == ']') {
            return true;
        }

        if (a == '{' && b == '}') {
            return true;
        }

        return false;
    }
};