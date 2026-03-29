class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0, high = nums.size()-1;
        int ans = nums[0];
        while(low<=high)  {
            int mid = (low+high)/2;
            ans = min(ans, nums[mid]);
            // in left
            if(nums[low]<=nums[mid] && nums[mid]<=nums[high])  
                high = mid-1;
            else if(nums[low]<=nums[mid])
                low = mid+1;
            else if(nums[mid]<=nums[high])
                high = mid-1;
            else 
                break; // throw error in prod code
        }
        return ans;
    }
};
