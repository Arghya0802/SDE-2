/*
 * Problem: Letter Combinations of a Phone Number
 * Question: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 *
 * Revision: At each digit, choose one mapped letter, append it to the current
 * combination, recurse to the next digit, and remove it while backtracking.
 * A complete combination is recorded when every digit has been processed.
 *
 * Time: O(4^n * n), including construction of the output strings
 * Auxiliary space: O(n), excluding the output
 */

class Solution {
private:
unordered_map<int, string> phoneMap = {
    {2, "abc"},
    {3, "def"},
    {4, "ghi"},
    {5, "jkl"},
    {6, "mno"},
    {7, "pqrs"},
    {8, "tuv"},
    {9, "wxyz"}
};

vector<string> ans;

void solve(int ind, string &s, string &digits)
{
    if(ind == digits.size())
    {
        ans.push_back(s);
        return;
    }

    int phoneNumber = (digits[ind] - '0');
    string curr = phoneMap[phoneNumber];

    for(int i = 0; i < curr.size(); i++)
    {
        s += curr[i];
        solve(ind + 1, s, digits);
        s.pop_back();
    }

    return;
}

public:
    vector<string> letterCombinations(string digits) 
    {
        string s = "";

        solve(0, s, digits);

        return ans;
    }
};
