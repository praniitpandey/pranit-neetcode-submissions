class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product = 1, maxProduct = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            product = 1;
            for (int j = i; j < nums.size(); j++) {
                product *= nums[j];
                maxProduct = max(product, maxProduct);
            }
        }

        return maxProduct;        
    }
};
