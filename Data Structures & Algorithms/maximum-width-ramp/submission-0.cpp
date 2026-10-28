class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<int> stack;
        for (int i = 0; i < nums.size(); i++) {
            if (stack.empty() || nums[i] < nums[stack.back()]) stack.push_back(i);
        }
        int answer = 0;
        for (int j = (int)nums.size() - 1; j >= 0; j--) {
            while (!stack.empty() && nums[stack.back()] <= nums[j]) {
                answer = max(answer, j - stack.back()); stack.pop_back();
            }
        }
        return answer;
    }
};