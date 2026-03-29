class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> solution;
        vector<int> subset;
        generate(nums, solution, subset, 0);

        return solution;
    }

    void generate(const vector<int>& nums, vector<vector<int>>& solution, vector<int> subset, int index) {
        if (index == nums.size()) {
            solution.push_back(subset);
        }
        else {
            generate(nums, solution, subset, index + 1);
            subset.push_back(nums[index]);
            generate(nums, solution, subset, index + 1);
        }
    }
};
