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
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head->next) return head;
        ListNode *temp = head;
        int x = 1;
        while(temp && x!=k){
            x++;
            temp = temp->next;
        }
        ListNode *temp1 = temp;
        ListNode *temp2 = head;
        while(temp->next){
            temp = temp->next;
            temp2 = temp2->next;
        }
        swap(temp1->val,temp2->val);
        return head;
    }
};