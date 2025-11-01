class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> toRemove(nums.begin(),nums.end());
        ListNode dummy(0,head);
        ListNode* curr = &dummy;

        while(curr->next != nullptr){
            if(toRemove.count(curr->next->val)){
                // ListNode* temp = curr->next;
                curr->next = curr->next->next;
                // delete temp;
            }
            else{
                curr = curr->next;
            }
        }

        return dummy.next;
    }
};
