/*
 * Problem: Integer to Roman
 * Question: https://leetcode.com/problems/integer-to-roman/
 *
 * Revision: Process Roman tokens from largest to smallest. Repeatedly append
 * the largest token that does not exceed the remaining value. Subtractive
 * forms such as IV, IX, XL, XC, CD, and CM are included as normal tokens.
 *
 * Time: O(1) for the constrained range 1 through 3999
 * Auxiliary space: O(1), excluding the output string
 */

class Solution {
public:
    string intToRoman(int num) 
    {
        vector<pair<int, string>> symbolsMap = {
            {1 ,"I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"},
            {1000, "M"}
        };
        
        string ans = "";

        for(int i = 12; i >= 0; i--)
        {
            int val = symbolsMap[i].first;
            string romanVal = symbolsMap[i].second;

            if(num == 0) break;
            if(val > num) continue;

            if(i == 1 || i == 3 || i == 5 || i == 7 || i == 9 || i == 11)
            {
                ans += romanVal;
                num -= val; 
                continue;
            }

            int noOfTimes = num / val;

            for(int k = 0; k < noOfTimes; k++) 
                ans += romanVal;

            num %= val;
        }

        return ans;
    }
};
