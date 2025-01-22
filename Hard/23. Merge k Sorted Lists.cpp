class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        vector<int> merged;
        ListNode* ans = new ListNode(0);   
        for(auto x : lists){
            while(x){
                merged.push_back(x->val);
                x = x->next;
            }
        }
        sort(merged.begin(), merged.end());
        ListNode* head = ans; 
        for(auto x : merged){
            ListNode* temp = new ListNode(x);
            head->next = temp;
            head = head->next;
        }
        return ans->next;
    }
};