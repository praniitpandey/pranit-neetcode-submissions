class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        sort(nums.begin(), nums.end());
        
        int left = 0, right = nums.size() - 1, count = 0;
        while (left <= right) {
            if (nums[left] + nums[right] <= limit)
                left++;
            right--;
            ++count;
        }
        
        return count;
        
    }
};