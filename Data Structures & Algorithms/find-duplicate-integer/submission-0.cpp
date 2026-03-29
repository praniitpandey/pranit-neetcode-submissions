class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<int> freq(n, 0);

        for (int i = 0; i < n + 1; i++) {
            ++freq[nums[i]];
        }

        for (int i = 1; i <= n; i++) {
            if (freq[i] > 1) {
                return i;
            }
        }

        return -1;
    }
};
