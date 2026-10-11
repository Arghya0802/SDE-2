/*
 * Problem: Longest Substring Without Repeating Characters
 * Question: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 *
 * Revision: Expand the right boundary and count each character. When the new
 * character becomes duplicated, move the left boundary forward and decrement
 * outgoing frequencies until the window is unique again. Track the largest
 * valid window length.
 *
 * Time: O(n)
 * Auxiliary space: O(1) for the fixed 256-entry frequency array
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int n = s.size();
        // unordered_set<char> hashSet;
        int freq[256] = {0};

        int end = 0, ans = 0;

        for(int start = 0; start < n; start++)
        {
            char ch = s[start];
            freq[ch] += 1;

            while(end <= start && freq[ch] > 1)
            {
                freq[s[end]] -= 1;
                end++;
            }

            // hashSet.insert(ch);
            ans = max(ans, start - end + 1);
        }

        return ans;
    }
};
