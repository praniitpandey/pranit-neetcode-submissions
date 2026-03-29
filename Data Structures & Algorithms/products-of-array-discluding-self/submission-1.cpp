class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> prefix(size, 1);
        vector<int> suffix(size, 1);
        vector<int> solution(size, 1);

        prefix[0] = nums[0];
        for (int i = 1; i < size; i++) {
            prefix[i] = prefix[i - 1] * nums[i];
        }

        suffix[size - 1] = nums[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i];
        }

        solution[0] = suffix[0 + 1];
        solution[size - 1] = prefix[size - 2];

        for (int i = 1; i <= size - 2; i++) {
            solution[i] = prefix[i - 1] * suffix[i + 1];
        }

        return solution;
    }
};
