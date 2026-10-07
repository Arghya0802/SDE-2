/*
 * Problem: Container With Most Water
 * Question: https://leetcode.com/problems/container-with-most-water/
 *
 * Revision: Start with the widest possible container and calculate its area
 * using the shorter boundary. Move the shorter boundary inward because it is
 * the limiting height; moving the taller boundary would reduce the width
 * without any possibility of increasing that limiting height.
 *
 * Time: O(n)
 * Auxiliary space: O(1)
 */

class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int n = height.size();
        int left = 0, right = n - 1;
        int ans = 0;

        while(left < right)
        {
            int width = right - left;
            int minHeight = min(height[left], height[right]);
            ans = max(ans, width * minHeight);

            if(height[left] < height[right]) left++;
            else right--;
        }
        
        return ans;
    }
};
