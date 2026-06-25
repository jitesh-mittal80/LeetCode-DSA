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
    int countnodes(ListNode* head){
        int count = 0;
        ListNode* temp = head;
        while (temp != NULL){
            count++;
            temp = temp->next;
        }

        return count;
    }

    ListNode* middleNode(ListNode* head) {
        int n = countnodes(head);
        int target = n/2;

        ListNode* temp = head;
        while(target>0 && temp != NULL){
            temp = temp->next;
            target--;
        }

        return temp;
    }
};