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
        if (head == NULL || head->next == NULL)
            return;

        // 1. Find the middle
        ListNode* s = head;
        ListNode* f = head;
        while (f != NULL && f->next != NULL) {
            f = f->next->next;
            s = s->next;
        }

        // 2. Reverse the list from middle to end
        ListNode* prev = NULL;
        ListNode* curr = s;
        ListNode* nxt;
        while (curr != NULL) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        cout << prev->val << endl;

        // 3. Reorder list
        ListNode* p1 = head;
        ListNode* p2 = prev;
        while (p1->next != NULL && p2->next != NULL && p1 != prev) {
            ListNode* temp1 = p1->next;
            p1->next = p2;
            ListNode* temp2 = p2->next;
            p2->next = temp1;
            p1 = temp1;
            p2 = temp2;
        }
    }
};