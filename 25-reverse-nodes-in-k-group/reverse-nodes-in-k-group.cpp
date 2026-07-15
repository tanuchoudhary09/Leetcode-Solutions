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
    ListNode* reverse(ListNode* head) {
        if(head==NULL ||  head->next==NULL) return head;
        ListNode *newHead= reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1 || !head) return head;
        ListNode *temp = head;
        ListNode *list = new ListNode(0);
        ListNode *dummy = list;
        int n = 0;
        while(temp){
            n++;
            temp = temp->next;
        }
        
        ListNode *a = head;
        ListNode *b = head; 
        while(n>=k){
            int val = k-1; 
            while(val--){
                b = b->next;
            }
            ListNode *c = b->next; 
            b->next = NULL;
            ListNode *d = reverse(a); 
            //while(dummy->next)dummy = dummy->next;
            dummy->next = d;
            dummy = a;
            a = c;
            b = c;
            n = n-k;
        }
        dummy->next = a;
        
        return list->next;
    }
};