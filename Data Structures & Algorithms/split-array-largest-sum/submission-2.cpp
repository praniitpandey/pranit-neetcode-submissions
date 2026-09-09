class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = 0, high = 0;
        for (int num : nums) {
            low = max(num, low);
            high += num;
        }

        int mid, ans = 1e9;
        while (low <= high) {
            mid = low + (high - low) / 2;

            if (canSplit(nums, k, mid)) {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }

private:
     bool canSplit(vector<int>& nums, int k, int largest) {
        int subarray = 1, curSum = 0;
        for (int num : nums) {
            curSum += num;
            if (curSum > largest) {
                subarray++;
                if (subarray > k) return 0;
                curSum = num;
            }
        }
        return true;
    }
};