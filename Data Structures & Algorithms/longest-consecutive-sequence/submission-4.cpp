class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

     if (nums.empty()) {
        return 0;
     }

     unordered_set<int> us(nums.begin(), nums.end());

     int length = 1, maxlength = 1;
     for (auto it = us.begin(); it != us.end(); it++) {
        int num = *it;

        if ((us.find(num - 1) == us.end()) && (us.find(num + 1) != us.end())) {
            length = 1;

            while (us.find(num + 1) != us.end()) {
                num++;
                length++;
            }

            if (length > maxlength) {
                maxlength = length;
            }
        }
     }

     return maxlength;
    }
};
