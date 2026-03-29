class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0, zeros = 0, maxLength = -1;
        for (int right = 0; right < nums.size(); right++) {
            zeros += (nums[right] == 0) ? 1 : 0;

            while (left < nums.size() && zeros > 1) {
                zeros -= (nums[left] == 0) ? 1 : 0;
                ++left;
            }

            maxLength = max(right - left + 1, maxLength);
        }
        
        return maxLength;
    }
};