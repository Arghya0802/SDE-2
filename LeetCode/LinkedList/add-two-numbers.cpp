/*
 * Problem: Add Two Numbers
 * Question: https://leetcode.com/problems/add-two-numbers/description/
 *
 * Revision: Traverse both lists together, add corresponding digits with the
 * carry, and append each result digit to a new linked list.
 *
 * Time: O(max(m, n))
 * Auxiliary space: O(1), excluding the output list
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *dummy = new ListNode(-1); // Dummy Node
        ListNode *tail = dummy;

        ListNode *p = l1, *q = l2;
        int carry = 0;

        while(p != NULL || q != NULL || carry != 0)
        {
            int pVal = p == NULL ? 0 : p -> val;
            int qVal = q == NULL ? 0 : q -> val;

            int sum = pVal + qVal + carry;
            carry = sum / 10;

            ListNode *newNode = new ListNode(sum % 10);
            tail -> next = newNode;
            tail = newNode;

            if(p != NULL) p = p -> next;
            if(q != NULL) q = q -> next;
        }

        return dummy -> next;
    }
};
