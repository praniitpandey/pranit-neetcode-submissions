class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, zeros = 0, maxLength = -1;
        for (int right = 0; right < nums.size(); right++) {
            zeros += (nums[right] == 0) ? 1 : 0;

            while (left < nums.size() && zeros > k) {
                zeros -= (nums[left] == 0) ? 1 : 0;
                ++left;
            }

            maxLength = max(right - left + 1, maxLength);
        }
        
        return maxLength;
    }
};