class Solution {
public:
    bool isBraketMatching(char a, char b) {
        if (a == '(' && b == ')')
            return true;
        else if (a == '[' && b == ']')
            return true;
        else if (a == '{' && b == '}')
            return true;
        else
            return false;
    }

    bool isValid(string s) {
        stack<char> stack;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stack.push(s[i]);
            } else {
                if (stack.empty()) {
                    return false;
                }

                if (!isBraketMatching(stack.top(), s[i])) {
                    return false;
                }

                stack.pop();
            }
        }

        return stack.empty() == true;
    }
};