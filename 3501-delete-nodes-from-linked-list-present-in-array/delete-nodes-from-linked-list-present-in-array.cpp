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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        //int n = nums.size();
        unordered_set<int>s;
        ListNode* dummy = new ListNode(0);
        //dummy->next = head;
        ListNode* temp = head;
        ListNode *tmp = dummy;
        for(int x : nums) s.insert(x);
        while(temp){
            if(!(s.count(temp->val))) {
                tmp->next = temp;
                tmp = tmp->next;
            }
            temp = temp->next;
            //tmp = temp->next;
        }
        tmp->next = NULL;
        return dummy->next;
    }
};