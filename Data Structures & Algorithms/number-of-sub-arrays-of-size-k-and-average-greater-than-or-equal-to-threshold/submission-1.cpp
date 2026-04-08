class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size(), left = 0, right = 0;
        long long windowSum = 0;

        for (right = 0; right < k && right < n; right++) {
            windowSum += arr[right];
        }

        int avg = 0, count = 0;
        for (left = 0, right = k; right < n; left++, right++) {
            avg = windowSum/k;
            count += avg >= threshold ? 1 : 0;

            windowSum -= arr[left];
            windowSum += arr[right];
        }
        
        avg = windowSum/k;
        count += avg >= threshold ? 1 : 0;
        return count;
    }
};