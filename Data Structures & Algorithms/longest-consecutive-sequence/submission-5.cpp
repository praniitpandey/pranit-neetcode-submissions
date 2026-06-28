class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int currNum, length, maxLength = 0;

        for (int num : numSet) {
            if (!numSet.count(num - 1)) {
                currNum = num;
                length = 1;

                while (numSet.count(currNum + 1)) {
                    currNum++;
                    length++;
                }

                maxLength = max(length, maxLength);
            }
        }

        return maxLength;
    }
};
