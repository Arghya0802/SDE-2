/*
 * Problem: Generate Parentheses
 * Question: https://leetcode.com/problems/generate-parentheses/
 *
 * Revision: Build only valid prefixes. Add an opening parenthesis while fewer
 * than n have been used, and add a closing parenthesis only when it can match
 * an existing opening parenthesis.
 *
 * Time: O(Cn * n), where Cn is the nth Catalan number
 * Auxiliary space: O(n), excluding the output
 */

class Solution {
private:
vector<string> ans;

void solve(int openCount, int closeCount, int total, string &currParen)
{
    if(openCount == closeCount && openCount == total)
    {
        ans.push_back(currParen);
        return;
    }

    if(openCount < total) 
    {
        currParen += "(";
        solve(openCount + 1, closeCount, total, currParen);
        currParen.pop_back();
    }

    if(closeCount < openCount)
    {
        currParen += ")";
        solve(openCount, closeCount + 1, total, currParen);
        currParen.pop_back();
    }

    return;
}

public:
    vector<string> generateParenthesis(int n) 
    {
        string currParen = "";

        solve(0, 0, n, currParen);

        return ans;
    }
};
