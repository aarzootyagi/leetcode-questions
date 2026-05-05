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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0)
            return head;
        int len = 1;
        ListNode* tail = head;
        while (tail->next != NULL) {
            len++;
            tail = tail->next;
        }
        k = k % len;
        if (k == 0)
            return head;
        int breakingNode = len - k;
        ListNode* temp = head;
        for (int i = 1; i < breakingNode; i++) {
            temp = temp->next;
        }
        ListNode* newHead = temp->next;
        temp->next = NULL;
        tail->next = head;

        return newHead;
    }
};