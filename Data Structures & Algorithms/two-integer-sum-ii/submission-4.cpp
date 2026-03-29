class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;

        while (l < r) {
            int twoSum = numbers[l] + numbers[r];

            if (twoSum < target) {
                l++;
            }
            else if (twoSum > target) {
                r--;
            }
            else {
                return {l+1,r+1};
            }
        }
        return {0,0};

    }
};
