/*
 * Problem: Substring with Concatenation of All Words
 * Question: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
 *
 * Revision: Build the required word-frequency map and scan each possible
 * word-aligned offset with a sliding window. Reset on an unknown word and
 * shrink from the left whenever the current word exceeds its allowed count.
 * Record the left boundary when the window contains every required word.
 *
 * Time: O(n * k), accounting for substring creation and hashing, where k is
 * the common word length
 * Auxiliary space: O(u), where u is the number of unique words
 */

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        unordered_map<string, int> actualMap;

        for(auto &wd: words) actualMap[wd] += 1;

        vector<int> ans;

        int k = words[0].size(); // Since all the words are of same length
        int n = s.size(), total = words.size();
        
        for(int offset = 0; offset < k; offset++)
        {
            int start = offset;
            unordered_map<string, int> currMap;
            int cnt = 0;

            for(int end = offset; end < n; end += k)
            {
                string curr = s.substr(end, k);

                if(actualMap.find(curr) != actualMap.end())
                {
                    currMap[curr] += 1;
                    cnt++;

                    while(currMap[curr] > actualMap[curr])
                    {
                        string startWord = s.substr(start, k);
                        start += k;
                        currMap[startWord]--;
                        cnt--;
                    }

                    if(cnt == total)
                        ans.push_back(start);
                }

                else
                {
                    currMap.clear();
                    cnt = 0;
                    start = end + k;
                }
            }
        }

        return ans;
    }
};
