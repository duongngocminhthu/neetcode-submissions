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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* groupPrev = &dummy;
        ListNode* groupNext = head;

        while(groupNext){
            ListNode* groupStart = groupNext;
            ListNode* groupEnd = groupNext;

            for(int i = 1; i < k; i++){
                groupEnd = groupEnd->next;
                if(!groupEnd){
                    return dummy.next;
                }
            }

            groupNext = groupEnd->next;

            ListNode* cur = groupStart;
            ListNode* prev = nullptr;

            for(int i = 0; i < k; i++){
                ListNode* next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }

            groupPrev->next = groupEnd;
            groupStart->next = groupNext;
            groupPrev = groupStart;
        }

        return dummy.next;
    }
};
