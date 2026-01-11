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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        vector<ListNode*> heap;
        heap.reserve(lists.size());
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp, move(heap));
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
        return dummy.next;
    }
};