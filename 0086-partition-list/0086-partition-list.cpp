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
    ListNode* partition(ListNode* h, int x) {
        ListNode a(0), b(0), *l = &a, *r = &b;
        while (h) {
            if (h->val < x)
                l = l->next = h;
            else
                r = r->next = h;
            h = h->next;
        }
        r->next = nullptr;
        l->next = b.next;
        return a.next;
    }
};