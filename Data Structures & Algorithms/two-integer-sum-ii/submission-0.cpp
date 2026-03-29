class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int l = 0, r = nums.size() - 1, sum = 0;
        vector<int> solution;

        while (l < r) {

            sum = nums[l] + nums[r];

            if (sum < target) {
                l++;
            }
            else if (sum > target) {
                r--;
            }
            else if (sum == target) {
                solution.push_back(l + 1);
                solution.push_back(r + 1);

                break;
            }
        }

        return solution;        
    }
};
