class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        solve(nums, 0);
        return subsets;
    }
private:
    vector<int> subset;
    vector<vector<int>> subsets;

    void solve(const vector<int>& nums, const int index) {
        if (index == nums.size()) {
            subsets.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        solve(nums, index + 1);
        
        subset.pop_back();
        int next = index + 1;
        while (next < nums.size() && nums[next] == nums[index])
            ++next;

        solve(nums, next);
    }
};
