class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& queries, vector<int>& nums) {
        stack<int> st;
        unordered_map<int, int> store;
        int n = nums.size();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            store[nums[i]] = (st.empty() ? -1 : st.top());
            st.push(nums[i]);
        }
        vector<int> ans;
        for (int q : queries) {
            ans.push_back(store[q]);
        }

        return ans;
    }
};