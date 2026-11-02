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
    ListNode* partition(ListNode* head, int x) {    
        ListNode* left = new ListNode();
        ListNode* right = new ListNode();
        ListNode* leftPtr = left;
        ListNode* rightPtr = right;
        while(head) {
            ListNode* next = head->next;
            if(head->val < x) {
                leftPtr->next = head;
                head->next = nullptr;
                leftPtr = leftPtr->next;
            } else {
                rightPtr->next = head;
                head->next = nullptr;
                rightPtr = rightPtr->next;
            }
            head = next;
        }
        leftPtr->next = right->next;
        return left->next;
    }
};