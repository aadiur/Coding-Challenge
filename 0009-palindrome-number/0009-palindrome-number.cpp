class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0)
            return false;

        int var = x;
        int rev = 0;

        while (x > 0) {
            int ld = x % 10;
            if (rev > INT_MAX/10 ||
            (rev == INT_MAX/10 && ld > INT_MAX%10))
            return 0;

            if (rev < INT_MIN/10 ||
            (rev == INT_MIN/10 && ld < INT_MIN%10))
            return 0;
            rev = rev * 10 + ld;
            x /= 10;
        }

        return rev == var;
    }
};