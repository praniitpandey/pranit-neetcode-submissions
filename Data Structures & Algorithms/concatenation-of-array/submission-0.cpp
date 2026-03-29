class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        for (int c = 0; c < 2; c++) {
            for (int i = 0; i < nums.size(); i++) {
                ans.push_back(nums[i]);
            }
        }
        
        return ans;
    }
};