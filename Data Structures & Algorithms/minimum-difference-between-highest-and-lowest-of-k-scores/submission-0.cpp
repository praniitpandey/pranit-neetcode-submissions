class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int minDiff = 1e9;
        for (int left = 0, right = k - 1; right < nums.size(); left++, right++) {
            minDiff = min(nums[right] - nums[left], minDiff);
        }
        
        return minDiff;
    }
};