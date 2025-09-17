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

        ListNode* temp = head;
        int count = 1 ;

        if(head == NULL){
            return head;
        }
        
        while(temp ->next != NULL){
            temp = temp->next;
            count ++;
        }

        temp->next = head;
        int headpos = 0;

        k = k % count;

        while(headpos != count - k ){
            head = head ->next;
            headpos ++;
        }

        while(temp->next != head){
            temp = temp->next;
        }

        temp ->next = NULL;

        return head;

        
    }
};