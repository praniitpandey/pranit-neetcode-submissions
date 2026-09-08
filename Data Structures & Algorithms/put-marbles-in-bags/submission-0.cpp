class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == n)
            return 0;

        vector<long long> arr;
        for (int i = 1; i < weights.size(); i++)
            arr.push_back(weights[i - 1] + weights[i]);

        sort(arr.begin(), arr.end());

        int left = 0, right = n - 2;
        long long ans = 0;
        for (int i = 0; i < k - 1; i++)
            ans += (arr[right--] - arr[left++]);

        return ans;
    }
};