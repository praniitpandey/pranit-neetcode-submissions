class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        vector<int> when(s.size(),removable.size()+1);
        for (int i = 0; i < removable.size(); i++)
            when[removable[i]]=i+1;
            
        int lo = 0, hi = removable.size();
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2, j = 0;
            
            for (int i = 0; i < s.size(); i++)
                if (when[i] > mid && j < p.size() && s[i]==p[j])
                    j++;

            if (j == p.size()) 
                lo = mid;
            else 
                hi = mid - 1;
        }
        
        return lo;
    }
};
