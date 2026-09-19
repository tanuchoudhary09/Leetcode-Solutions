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
    int numComponents(ListNode* head, vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>s;
        int ans = 0;
        for(int x : nums) s.insert(x);
        while(head){
            bool flag =false;
            while(head && s.count(head->val)) {
                head = head -> next;
                flag = true;
            }
            if(flag) ans++;
            if(head) head = head->next;
            else break;
        }
        return ans;
    }
};