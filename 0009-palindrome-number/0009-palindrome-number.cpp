class Solution {
public:
    bool isPalindrome(int x) {
        long int rev = 0;
        int dup = x;

        while (dup > 0) {
            int rmd = dup % 10;
            rev = (rev * 10) + rmd;
            dup = dup / 10;
        }

        return rev == x;
    }
};