class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int length = 0, maxLength = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                ++length;
            }
            else {
                maxLength = max(length, maxLength);
                length = 0;
            }
        }
        return max(length, maxLength);
    }
};