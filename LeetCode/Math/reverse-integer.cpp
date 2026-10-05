/*
 * Problem: Reverse Integer
 * Question: https://leetcode.com/problems/reverse-integer/
 *
 * Revision: Preserve the sign, repeatedly extract the last digit from the
 * absolute value, and append it to the reversed result. Return zero when the
 * next decimal shift would exceed the signed 32-bit integer range.
 *
 * Time: O(log10(|x|))
 * Auxiliary space: O(1)
 */

class Solution {
public:
    int reverse(int x) 
    {
        if(x == INT_MAX || x == INT_MIN) return 0;

        int sign = x < 0 ? -1 : +1;

        int ans = 0;
        int val = abs(x);

        while(val != 0)
        {
            int rem = val % 10;

            if(ans * sign > INT_MAX / 10 || ans * sign < INT_MIN / 10)
                return 0;
            
            ans *= 10;
            ans += rem;
            val /= 10;
        }

        return (ans * sign);
    }
};
