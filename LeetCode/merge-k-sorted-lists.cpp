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

using pp = pair<int, ListNode *>;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<pp, vector<pp>, greater<pp>> minQ;

        int n = lists.size(); // Total number of ListNode

        for(int i = 0; i < n; i++)
        {
            ListNode *head = lists[i];
            
            if(head != NULL) minQ.push({head -> val, head});
        }

        ListNode *dummy = new ListNode(-1); // Dummy Node;
        ListNode *tail = dummy;

        while(!minQ.empty())
        {
            auto[minVal, currMinNode] = minQ.top();
            minQ.pop();

            tail -> next = currMinNode;
            tail = currMinNode;

            if(currMinNode -> next != NULL) 
                minQ.push({currMinNode -> next -> val, currMinNode -> next});
        }

        tail -> next = NULL;

        return dummy -> next;
    }
};
