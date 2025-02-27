
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
        ListNode* fast = head;
        ListNode* slow = NULL;
        for (int i = 1; i < n; i++) {
            fast = fast->next;
        }

        if(fast->next == NULL){
            return head->next;
        }

        while (fast->next != NULL) {
            fast = fast->next;
            if (slow == NULL) {
                slow = head;
            }else{
                slow = slow->next;
            }
        }

        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return head;
    }
};