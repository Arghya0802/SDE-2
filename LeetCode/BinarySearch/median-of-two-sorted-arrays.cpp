/*
 * Problem: Median of Two Sorted Arrays
 * Question: https://leetcode.com/problems/median-of-two-sorted-arrays/
 *
 * Revision: Binary-search the smaller array. Keep (m + n + 1) / 2 elements
 * in the combined left partition and use sentinels when a partition touches
 * an array boundary. A partition is valid when left1 <= right2 and
 * left2 <= right1. If left1 > right2, move left in the smaller array;
 * otherwise, move right. For an odd total return max(left1, left2); for an
 * even total return (max(left1, left2) + min(right1, right2)) / 2.0.
 *
 * Time: O(log(min(m, n)))
 * Auxiliary space: O(1)
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        // Assume 1st Array is always the smaller one
        // ElementsOnLeft = (m + n + 1) / 2 --> works for both Odd and even cases

        int m = nums1.size(), n = nums2.size();

        if(m > n) return findMedianSortedArrays(nums2, nums1);

        bool isOdd = (m + n) % 2 == 0 ? false : true;

        // We can take 0 elements from nums1[] or at max can take all the elements from nums1[]
        int low = 0, high = m;
        int left = (m + n + 1) / 2;

        while(low <= high)
        {
            int mid1 = low + (high - low) / 2;
            int mid2 = left - mid1;

            int left1 = mid1 == 0 ? INT_MIN : nums1[mid1 - 1];
            int left2 = mid2 == 0 ? INT_MIN : nums2[mid2 - 1];
            int right1 = mid1 == m ? INT_MAX : nums1[mid1];
            int right2 = mid2 == n ? INT_MAX : nums2[mid2];

            // Valid configuration
            if(left1 <= right2 && left2 <= right1)
            {
                if(isOdd) 
                    return max(left1, left2);

                double sum = max(left1, left2) * 1.0 + min(right1, right2) * 1.0;

                return sum / 2.0;
            }

            else if(left1 > right2) high = mid1 - 1;

            else low = mid1 + 1;
        }

        return -1;
    }
};
