class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        set<int> us(nums.begin(), nums.end());
        vector<int> v(us.begin(), us.end());

        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << "\n";

        sort(v.begin(), v.end());
        int l = 1, maxl = l;
        for (int i = 0; i < v.size() - 1; i++) {
            l = 1;
            while (v[i + 1] - v[i] == 1) {
                cout << "index inside while loop: " << i << " \n";
                l++;
                i++;
            }

            cout << "consecutive length: " << l << " \n";

            if (l > maxl) {
                maxl = l;
            }
        }

        return maxl;        
    }
};
