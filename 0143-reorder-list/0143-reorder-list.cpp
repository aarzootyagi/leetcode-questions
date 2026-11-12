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
        if(!head || !head->next) return;

        ListNode *s=head, *f=head;

        while(f->next && f->next->next) {
            s=s->next;
            f=f->next->next;
        }
        ListNode *p=nullptr, *c=s->next, *n;
        s->next=nullptr;

        while(c) {
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        ListNode *a=head, *b=p;
        while(b) {
            n=a->next;
            a->next=b;
            b=b->next;
            a->next->next=n;
            a=n;
        }
    }
};