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
    void reorderList(ListNode* head) {
        if(!head->next || !head->next->next) return;

        ListNode *slow = head, *fast = head;

        // Bước 1 : tìm middle chia làm hai list
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *list1 = head, *list2 = slow->next;
        slow->next = nullptr;
        
        // Bước 2 : reverse list2
        ListNode* prev = nullptr;
        ListNode* cur = list2;

        while(cur){
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        list2 = prev;

        // Bước 3 : merge
        ListNode *curr = list1;
        while(list1 && list2){
            list1 = list1->next;
            curr->next= list2;
            curr = curr->next;
            list2 = list2->next;
            curr->next = list1;
            curr = curr->next;
        }
    }
};
