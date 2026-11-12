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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);

        while(head) {
            ListNode* curr = head;
            head = head->next;

            ListNode* p = &dummy;
            while(p->next && p->next->val <= curr->val)
                p = p->next;

            curr->next = p->next;
            p->next = curr;
        }
        return dummy.next;
    }
};