class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int i = 0, j = 0;
        vector<int> merged{};

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                merged.push_back(nums1[i++]);
            }
            else {
                merged.push_back(nums2[j++]);
            }
        }

        while (i < m) {
            merged.push_back(nums1[i++]);
        }
        while (j < n) {
            merged.push_back(nums2[j++]);
        }

        double ans = 0.0;
        if ((m + n) % 2 == 0) {
            ans += merged[(m + n)/2 - 1] + merged[(m + n)/2];
            ans /= 2;
        }
        else {
            ans += merged[(m + n)/2];
        }

        return ans;
    }
};
