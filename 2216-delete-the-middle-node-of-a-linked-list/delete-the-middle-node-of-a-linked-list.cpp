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
    ListNode* deleteMiddle(ListNode* head) {

        if (head == NULL || head->next == NULL){
            return NULL;
        }
        ListNode* temp = head;
        int count = 0;

        while (temp != NULL){
            temp = temp->next;
            count++;
        }

        int target = count/2;
        ListNode* temp1 = head;
        for (int i = 0; i < target-1; i++){
            temp1 = temp1->next;
        }

        temp1->next = temp1->next->next;
        return head;
    }
};