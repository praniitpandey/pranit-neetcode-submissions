class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int low = 0, high = removable.size(), mid = 0, ans = 0;

        while (low <= high) {
            mid = low + (high - low) / 2;

            string q = s;
            for (int i = 0; i < mid && i < removable.size(); i++)   //O(|removable|)
                q[removable[i]] = '#';
            
            if (isSubsequence(q, p)) {
                ans = max(ans, mid);
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }

private:
    bool isSubsequence(const string& s, const string& p) {
        int i = 0, j = 0;

        while (i < s.size() && j < p.size()) {
            if (s[i] == p[j])
                ++j;
            ++i;
        }

        return j == p.size();
    }
};
