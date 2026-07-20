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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        for(int i=0; i<n; i++) fast = fast->next;
        int total = 0;
        ListNode* prev = nullptr;
        while(fast) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        // total = # of slow moves, half of number of fast moves
        if(!prev) return slow->next;
        prev->next = slow->next;
        return head;
    }
};