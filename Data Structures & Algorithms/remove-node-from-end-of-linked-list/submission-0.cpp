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
        int count = 0;
        ListNode* cur = head;

        while(cur){
            count++;
            cur = cur->next;
        }

        int index = count - n + 1;

        ListNode* prev = nullptr;
        ListNode* curr = head;

        for(int i = 1; i < index; i++){
            prev = curr;
            curr = curr->next;
        }

        if(prev == nullptr){
            head = head->next;
        }
        else{
            prev->next = curr->next;
        }

        return head;
    }
};
