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
    ListNode* insertGreatestCommonDivisors(ListNode* root) {
        ListNode *head = root;
        
        while(head && head->next){
            int hcf = gcd(head->val,head->next->val);
            ListNode *node = new ListNode(hcf);
            ListNode *temp1 = head->next;
            head->next = node;
            head = head->next;
            head->next = temp1;
            head = head->next;//->next;
        }
        return root;
    }
};