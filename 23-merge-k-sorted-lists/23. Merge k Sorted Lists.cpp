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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;  // min-heap
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy; 
        if(lists.size() == 0) {
            return nullptr;
        }
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for(int i=0; i<lists.size(); i++) {
            if(lists[i]) {
                pq.push(lists[i]);
            }
        }
        while(!pq.empty()) {
            ListNode* min = pq.top();
            pq.pop();
            if(min->next) {
                pq.push(min->next);
            }
            curr->next = min;
            curr = curr->next;
        }
        return dummy->next;
    }
};