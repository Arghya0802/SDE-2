/*
 * Problem: Reverse Nodes in K-Group
 * Question: https://leetcode.com/problems/reverse-nodes-in-k-group/
 *
 * Revision: Find the kth node to confirm that a complete group exists. Reverse
 * the remaining groups recursively, reverse the current inclusive range, and
 * connect the original group head—now its tail—to the reversed remainder.
 *
 * Time: O(n)
 * Auxiliary space: O(n / k) recursion stack
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
private:

ListNode *reverseLL(ListNode *start, ListNode *end)
{
    if(!start || !start -> next) return start;

    ListNode *curr = start;
    ListNode *prev = NULL, *last = NULL;

    while(prev != end)
    {
        last = prev;
        prev = curr;

        curr = curr -> next;
        prev -> next = last;
    }

    return prev;
}

ListNode *revNodeInK(ListNode *head, int k)
{
    if(!head || !head || !head -> next || k == 1) return head;

    ListNode *start = head, *end = head;

    for(int i = 0; i < k - 1; i++)
    {
        end = end -> next;

        if(end == NULL) // If we don't have K nodes, we return start
            return start;
    }

    ListNode *revRemainingGroups = reverseKGroup(end -> next, k);

    ListNode* reversedCurrentHead = reverseLL(start, end);

    start -> next = revRemainingGroups;

    return end;

}

public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(!head || !head -> next || k == 1) return head;

        return revNodeInK(head, k);
    }
};
