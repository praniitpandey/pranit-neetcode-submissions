class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProductSoFar = nums[0], minProductSoFar = nums[0], maxProductOverall = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int prevMax = maxProductSoFar;
            maxProductSoFar = max({nums[i], prevMax * nums[i], minProductSoFar * nums[i]});
            minProductSoFar = min({nums[i], prevMax * nums[i], minProductSoFar * nums[i]});
            maxProductOverall = max(maxProductSoFar, maxProductOverall);            
        }

        return maxProductOverall;
    }
};