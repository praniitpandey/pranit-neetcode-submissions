class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> currentMerge(3, 0);
        for (int i = 0; i < triplets.size(); i++) {
            if ((triplets[i][0] > target[0]) || (triplets[i][1] > target[1]) || (triplets[i][2] > target[2])) {
                continue;
            }
            else if ((triplets[i][0] == target[0]) || (triplets[i][1] == target[1]) || (triplets[i][2] == target[2])) {
                currentMerge[0] = max(currentMerge[0], triplets[i][0]);
                currentMerge[1] = max(currentMerge[1], triplets[i][1]);
                currentMerge[2] = max(currentMerge[2], triplets[i][2]);
            }

            if ((currentMerge[0] == target[0]) && (currentMerge[1] == target[1]) && (currentMerge[2] == target[2])) {
                return true;
            }

        }

        return false;        
    }
};
